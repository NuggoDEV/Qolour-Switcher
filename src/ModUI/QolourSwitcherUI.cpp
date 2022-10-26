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

GameObject *floatingContainer;
bool TimedSwitchersOn = false;

void QolourSwitcherUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{

    // Getting the players current active colour scheme
    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    if (!TimedSwitchersOn)
    {
        // Container disabled until sliders are activated
        floatingContainer->SetActive(false);  
        getLogger().info("Set Floating Container to false as timed switches isn't on"); 
    }

    if (firstActivation)
    {
        // Create the containers
        GameObject *mainContainer = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());
        floatingContainer = BeatSaberUI::CreateFloatingScreen(Vector2(50.0, 60.0f), Vector3(-2.0f, 1.5f, 2.0f), Vector3(0.0f, -30.0f, 0.0f), 0.0f, true, false);

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
        BeatSaberUI::CreateColorPicker(mainContainer->get_transform(), "Bomb Colour", colourScheme->get_saberAColor(), [colourScheme](Color colour)
        {
            bombColour = colour;
            getLogger().info("Set Bomb Colour Successfully");
        });
    }
}

void QolourSwitcherUI::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling)
{

}