#include "main.hpp"
#include "ModConfig.hpp"
#include "HardCodedValues.hpp"

#include "ModUI/QolourSwitcherUI.hpp"
using namespace QolourSwitcher;

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Color.hpp"
#include "UnityEngine/Object.hpp"
using namespace UnityEngine;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/MenuTransitionsHelper.hpp"
using namespace GlobalNamespace;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(QolourSwitcher, QolourSwitcherUI);

GameObject *leftFloatingContainer;
GameObject *rightFloatingContainer;


std::string SecondsToString(float value)
{
    int minutes = value / 60;
    int seconds = value - minutes * 60;
    std::string minuteStr = std::to_string(minutes);
    std::string secondStr = std::to_string(seconds);

    return minuteStr + ":" + secondStr;
}


void QolourSwitcherUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{

    // Getting the players current active colour scheme
    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    if (firstActivation)
    {
        // Create the containers
        GameObject *mainContainer = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());
        leftFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(50.0, 60.0f), Vector3(-2.0f, 1.5f, 2.8f), Vector3(0.0f, -30.0f, 0.0f), 0.0f, true, false);
        rightFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(50.0, 60.0f), Vector3(2.0f, 1.5f, 2.8f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, true, false);

        // Creation of the four colour pickers
        // Left saber colour picker
        BeatSaberUI::CreateColorPicker(mainContainer->get_transform(), "Left Saber Colour", colourScheme->get_saberAColor(), [colourScheme](Color colour)
        {
            colourScheme->saberAColor = colour;
            getLogger().info("Set Left Saber Colour Successfully");
        });

        // Right saber colour picker
        BeatSaberUI::CreateColorPicker(mainContainer->get_transform(), "Right Saber Colour", colourScheme->get_saberBColor(), [colourScheme](Color colour)
        {
            colourScheme->saberBColor = colour;
            getLogger().info("Set Right Saber Colour Successfully");
        });

        // Wall colour picker
        BeatSaberUI::CreateColorPicker(mainContainer->get_transform(), "Wall Colour", colourScheme->get_obstaclesColor(), [colourScheme](Color colour)
        {
            colourScheme->obstaclesColor = colour;
            getLogger().info("Set Wall Colour Successfully");
        });

        // Bomb colour picker
        BeatSaberUI::CreateColorPicker(mainContainer->get_transform(), "Bomb Colour", getModConfig().BombColour.GetValue(), [&](Color colour)
        {
            getModConfig().BombColour.SetValue(colour);
            getLogger().info("Set Bomb Colour Successfully");
        });



        // Creation of timed switches toggles
        BeatSaberUI::CreateToggle(leftFloatingContainer->get_transform(), "Enable First Timed Switch", getModConfig().TimedSwitch1.GetValue(), Vector2(0.0f, -12.0f), [](bool value)
        {   getModConfig().TimedSwitch1.SetValue(value);   });

        BeatSaberUI::CreateToggle(leftFloatingContainer->get_transform(), "Enable Second Timed Switch", getModConfig().TimedSwitch2.GetValue(), Vector2(0.0f, -22.0f), [](bool value)
        {   getModConfig().TimedSwitch2.SetValue(value);   });

        BeatSaberUI::CreateToggle(leftFloatingContainer->get_transform(), "Enable Third Timed Switch", getModConfig().TimedSwitch3.GetValue(), Vector2(0.0f, -32.0f), [](bool value)
        {   getModConfig().TimedSwitch3.SetValue(value);   });

        BeatSaberUI::CreateToggle(leftFloatingContainer->get_transform(), "Enable Fourth Timed Switch", getModConfig().TimedSwitch4.GetValue(), Vector2(0.0f, -42.0f), [](bool value)
        {   getModConfig().TimedSwitch4.SetValue(value);   });
    

        auto ts1 = getModConfig().TimedSwitch1Int.GetValue();
        auto ts2 = getModConfig().TimedSwitch2Int.GetValue();
        auto ts3 = getModConfig().TimedSwitch3Int.GetValue();
        auto ts4 = getModConfig().TimedSwitch4Int.GetValue();
    
        // Creation of timed switches time settings
        auto slider1 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "First Time", 1, ts1, 0, 120, Vector2(0.0f, -12.0f), [](int value)
        {
            getModConfig().TimedSwitch1Int.SetValue(value);
        });
        slider1->FormatString = std::move(SecondsToString);

        auto slider2 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "Second Time", 1, ts2, ts1, 240, Vector2(0.0f, -22.0f), [](int value)
        {
            getModConfig().TimedSwitch2Int.SetValue(value);
        });
        slider2->FormatString = std::move(SecondsToString);

        auto slider3 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "Third Time", 1, ts3, ts2, 360, Vector2(0.0f, -32.0f), [](int value)
        {
            getModConfig().TimedSwitch3Int.SetValue(value);
        });
        slider3->FormatString = std::move(SecondsToString);

        auto slider4 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "Fourth Time", 1, ts4, ts3, 480, Vector2(0.0f, -42.0f), [](int value)
        {
            getModConfig().TimedSwitch4Int.SetValue(value);
        });
        slider4->FormatString = std::move(SecondsToString);
    }

    leftFloatingContainer->SetActive(true);
    rightFloatingContainer->SetActive(true);
}

void QolourSwitcherUI::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling)
{
    leftFloatingContainer->SetActive(false);
    rightFloatingContainer->SetActive(false);
}