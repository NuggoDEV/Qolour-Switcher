#include "main.hpp"
#include "ModConfig.hpp"

#include "ModUI/QolourSwitcherUI.hpp"
using namespace QolourSwitcher;

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Color.hpp"
#include "UnityEngine/Object.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
using namespace UnityEngine;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/MenuTransitionsHelper.hpp"
using namespace GlobalNamespace;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

using namespace TMPro;

DEFINE_TYPE(QolourSwitcher, QolourSwitcherUI);

GameObject *leftFloatingContainer;
GameObject *rightFloatingContainer;


GameObject *firstLeftNoteFloatingContainer;
GameObject *firstRightNoteFloatingContainer;

GameObject *secondLeftNoteFloatingContainer;
GameObject *secondRightNoteFloatingContainer;

GameObject *thirdLeftNoteFloatingContainer;
GameObject *thirdRightNoteFloatingContainer;

GameObject *fourthLeftNoteFloatingContainer;
GameObject *fourthRightNoteFloatingContainer;

std::string SecondsToString(float value)
{
    int minutes = value / 60;
    int seconds = value - minutes * 60;
    std::string minuteStr = std::to_string(minutes);
    std::string secondStr = std::to_string(seconds);

    return minuteStr + "m :" + secondStr + "s";
}


void QolourSwitcherUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    getLogger().info("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

    // Getting the players current active colour scheme
    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    if (firstActivation)
    {
        // Create the containers
        GameObject *mainContainer = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());
        leftFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(50.0, 60.0f), Vector3(-2.3f, 1.5f, 2.8f), Vector3(0.0f, -30.0f, 0.0f), 0.0f, true, false);
        rightFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(50.0, 70.0f), Vector3(2.3f, 1.5f, 2.8f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, true, false);

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
    
        // Creation of timed switches time controllers
        auto slider1 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "First", 1, ts1, 0, 120, Vector2(0.0f, -0.0f), [](int value)
        {   getModConfig().TimedSwitch1Int.SetValue(value);    });
        slider1->FormatString = std::move(SecondsToString);

        auto slider2 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "Second", 1, ts2, ts1, 240, Vector2(0.0f, -18.3f), [](int value)
        {   getModConfig().TimedSwitch2Int.SetValue(value);    });
        slider2->FormatString = std::move(SecondsToString);
        
        auto slider3 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "Third", 1, ts3, ts2, 360, Vector2(0.0f, -34.8f), [](int value)
        {   getModConfig().TimedSwitch3Int.SetValue(value);    });
        slider3->FormatString = std::move(SecondsToString);
        
        auto slider4 = BeatSaberUI::CreateSliderSetting(rightFloatingContainer->get_transform(), "Fourth", 1, ts4, ts3, 480, Vector2(0.0f, -50.3f), [](int value)
        {   getModConfig().TimedSwitch4Int.SetValue(value);    });
        slider4->FormatString = std::move(SecondsToString);




        firstLeftNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.1f, 2.5f, 2.9f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);
        firstRightNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.7f, 2.5f, 2.55356f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);

        secondLeftNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.1f, 1.95f, 2.9f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);
        secondRightNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.7f, 1.95f, 2.55356f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);

        thirdLeftNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.1f, 1.48f, 2.9f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);
        thirdRightNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.7f, 1.48f, 2.55356f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);

        fourthLeftNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.1f, 1.0f, 2.9f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);
        fourthRightNoteFloatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(2.7f, 1.0f, 2.55356f), Vector3(0.0f, 30.0f, 0.0f), 0.0f, false, false);


        // First colour pickers
        TextMeshProUGUI *firstLN = BeatSaberUI::CreateText(firstLeftNoteFloatingContainer->get_transform(), "Left Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(firstLeftNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch1LNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch1LNColour.SetValue(value);    });
        firstLN->set_fontSize(3.0f);

        TextMeshProUGUI *firstRN = BeatSaberUI::CreateText(firstRightNoteFloatingContainer->get_transform(), "Right Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(firstRightNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch1RNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch1RNColour.SetValue(value);    });
        firstRN->set_fontSize(3.0f);

        
        // Second colour pickers
        TextMeshProUGUI *secondLN = BeatSaberUI::CreateText(secondLeftNoteFloatingContainer->get_transform(), "Left Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(secondLeftNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch2LNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch2LNColour.SetValue(value);    });
        secondLN->set_fontSize(3.0f);

        TextMeshProUGUI *secondRN = BeatSaberUI::CreateText(secondRightNoteFloatingContainer->get_transform(), "Right Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(secondRightNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch2RNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch2RNColour.SetValue(value);    });
        secondRN->set_fontSize(3.0f);


        // Third colour pickers
        TextMeshProUGUI *thirdLN = BeatSaberUI::CreateText(thirdLeftNoteFloatingContainer->get_transform(), "Left Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(thirdLeftNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch3LNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch3LNColour.SetValue(value);    });
        thirdLN->set_fontSize(3.0f);

        TextMeshProUGUI *thirdRN = BeatSaberUI::CreateText(thirdRightNoteFloatingContainer->get_transform(), "Right Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(thirdRightNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch3RNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch3RNColour.SetValue(value);    });
        thirdRN->set_fontSize(3.0f);
//
//
        //// Fourth colour pickers
        TextMeshProUGUI *fourthLN = BeatSaberUI::CreateText(fourthLeftNoteFloatingContainer->get_transform(), "Left Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(fourthLeftNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch4LNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch4LNColour.SetValue(value);    });
        fourthLN->set_fontSize(3.0f);

        TextMeshProUGUI *fourthRN = BeatSaberUI::CreateText(fourthRightNoteFloatingContainer->get_transform(), "Right Saber", Vector2(17.5f, -9.0f));
        BeatSaberUI::CreateColorPicker(fourthRightNoteFloatingContainer->get_transform(), "", getModConfig().TimedSwitch4RNColour.GetValue(), [&](Color value)
        {    getModConfig().TimedSwitch4RNColour.SetValue(value);    });
        fourthRN->set_fontSize(3.0f);
    }

    leftFloatingContainer->SetActive(true);
    rightFloatingContainer->SetActive(true);


    firstLeftNoteFloatingContainer->SetActive(true);
    firstRightNoteFloatingContainer->SetActive(true);

    secondLeftNoteFloatingContainer->SetActive(true);
    secondRightNoteFloatingContainer->SetActive(true);

    thirdLeftNoteFloatingContainer->SetActive(true);
    thirdRightNoteFloatingContainer->SetActive(true);
    
    fourthLeftNoteFloatingContainer->SetActive(true);
    fourthRightNoteFloatingContainer->SetActive(true);
}

void QolourSwitcherUI::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling)
{
    leftFloatingContainer->SetActive(false);
    rightFloatingContainer->SetActive(false);


    firstLeftNoteFloatingContainer->SetActive(false);
    firstRightNoteFloatingContainer->SetActive(false);

    secondLeftNoteFloatingContainer->SetActive(false);
    secondRightNoteFloatingContainer->SetActive(false);

    thirdLeftNoteFloatingContainer->SetActive(false);
    thirdRightNoteFloatingContainer->SetActive(false);

    fourthLeftNoteFloatingContainer->SetActive(false);
    fourthRightNoteFloatingContainer->SetActive(false);
}