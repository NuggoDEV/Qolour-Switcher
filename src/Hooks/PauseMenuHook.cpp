#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Color.hpp"
#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;


GameObject *leftSaberScreen;
GameObject *rightSaberScreen;
GameObject *bombScreen;
GameObject *wallScreen;
GameObject *resetScreen;
bool screensEnabled;


MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ShowMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
{
    PauseMenuManager_ShowMenu(self);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    leftSaberScreen = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(-0.4f, 2.85f, 2.4f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);
    rightSaberScreen = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(0.4f, 2.85f, 2.4f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);       
    bombScreen = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(-1.2f, 2.85f, 2.4f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);
    wallScreen = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(1.2f, 2.85f, 2.4f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);
    resetScreen = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(-0.5f, 0.1f, 0.0f), Vector3(90.0f, 0.0f, 0.0f), 0.0f, false, false);

    
    BeatSaberUI::CreateText(leftSaberScreen->get_transform(), "Left Saber Colour!", Vector2(13.5f, -5.0f));
    BeatSaberUI::CreateColorPicker(leftSaberScreen->get_transform(), "", colourScheme->get_saberAColor(), [colourScheme](Color colour)
    {
        getLogger().info("Saving Left Saber Colour");
        colourScheme->saberAColor = colour;
        getModConfig().ColoursChanged.SetValue(true);
        getLogger().info("Saved Left Saber Colour Successfully!");
    });


    BeatSaberUI::CreateText(rightSaberScreen->get_transform(), "Right Saber Colour!", Vector2(12.5f, -5.0f));
    BeatSaberUI::CreateColorPicker(rightSaberScreen->get_transform(), "", colourScheme->get_saberBColor(), [colourScheme](Color colour)
    {
        getLogger().info("Saving Right Saber Colour");
        colourScheme->saberBColor = colour;
        getModConfig().ColoursChanged.SetValue(true);
        getLogger().info("Saved Right Saber Colour Successfully!");
    });

    
    BeatSaberUI::CreateText(bombScreen->get_transform(), "Bomb Colour!", Vector2(16.0f, -5.0f));
    BeatSaberUI::CreateColorPicker(bombScreen->get_transform(), "", getModConfig().BombColour.GetValue(), [&](Color colour)
    {
        getLogger().info("Saving Bomb Colour!");
        getModConfig().BombColour.SetValue(colour);
        getModConfig().ColoursChanged.SetValue(true);
        getLogger().info("Saved Bomb Colour Successfully!");
    });


    BeatSaberUI::CreateText(wallScreen->get_transform(), "Wall Colour!", Vector2(16.0f, -5.0f));
    BeatSaberUI::CreateColorPicker(wallScreen->get_transform(), "", colourScheme->get_obstaclesColor(), [colourScheme](Color colour)
    {
        getLogger().info("Saving Wall Colour!");
        colourScheme->obstaclesColor = colour;
        getModConfig().ColoursChanged.SetValue(true);
        getLogger().info("Saved Wall Colour Successfully!");
    });
    screensEnabled = true;

    if (!screensEnabled)
    {
        getLogger().info("Setting Pickers to Active");
        leftSaberScreen->SetActive(true);
        rightSaberScreen->SetActive(true);
        bombScreen->SetActive(true);
        wallScreen->SetActive(true);
        getLogger().info("Set All Pickers to Active Successfully");
    }
}


MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ContinueButtonPressed, &PauseMenuManager::ContinueButtonPressed, void, PauseMenuManager *self) {
    PauseMenuManager_ContinueButtonPressed(self);
    
    getLogger().info("Setting All Pickers to Inactive!");
    leftSaberScreen->SetActive(false);
    rightSaberScreen->SetActive(false);
    bombScreen->SetActive(false);
    wallScreen->SetActive(false);

    screensEnabled = false;
    getLogger().info("Set All Pickers to Inactive Successfully!");
}