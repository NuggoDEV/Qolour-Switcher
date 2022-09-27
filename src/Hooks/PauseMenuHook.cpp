#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"

#include "GlobalNamespace/PauseMenuManager.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

GameObject *leftSaberScreen;
GameObject *rightSaberScreen;
bool screensEnabled;

MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ShowMenu, &PauseMenuManager::ShowMenu, void, GlobalNamespace::PauseMenuManager *self)
{
    PauseMenuManager_ShowMenu(self);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);


    if (!getModConfig().ModToggle.GetValue())
    {
        leftSaberScreen = BeatSaberUI::CreateFloatingScreen(Vector2(10.0f, 10.0f), Vector3(-0.5f, -0.3f, 2.6f), Vector3(25.0f, 0.0f, 0.0f), 0.0f, false, false);
        rightSaberScreen = BeatSaberUI::CreateFloatingScreen(Vector2(10.0f, 10.0f), Vector3(0.5f, -0.3f, 2.6f), Vector3(25.0f, 0.0f, 0.0f), 0.0f, false, false);

        BeatSaberUI::CreateColorPicker(leftSaberScreen->get_transform(), "", colourScheme->get_saberAColor(), [colourScheme](Color colour)
        {
            getLogger().info("Saving left saber colour!");
            colourScheme->saberAColor = colour;
        });

        BeatSaberUI::CreateColorPicker(rightSaberScreen->get_transform(), "", colourScheme->get_saberBColor(), [colourScheme](Color colour)
        {
            getLogger().info("Saving right saber colour");
            colourScheme->saberBColor = colour;
        });

        screensEnabled = true;
    }
    else if (getModConfig().ModToggle.GetValue()) {}

    if (!screensEnabled)
    {
        getLogger().info("Setting pickers to active");
        leftSaberScreen->SetActive(true);
        rightSaberScreen->SetActive(true);
    }
}


MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ContinueButtonPressed, &PauseMenuManager::ContinueButtonPressed, void, PauseMenuManager *self) {
    PauseMenuManager_ContinueButtonPressed(self);
    
    if (!getModConfig().ModToggle.GetValue())
    {
    getLogger().info("Disabling Colour Picker!");
    leftSaberScreen->SetActive(false);
    rightSaberScreen->SetActive(false);
    
    screensEnabled = false;
    }
    else if (getModConfig().ModToggle.GetValue()) {}
}


//MAKE_AUTO_HOOK_MATCH(PauseMenuManager_MenuButtonPressed, &PauseMenuManager::MenuButtonPressed, void, PauseMenuManager *self) {
//    PauseMenuManager_MenuButtonPressed(self);
//
//        leftSaberScreen->SetActive(false);
//        rightSaberScreen->SetActive(false);
//}
//
//MAKE_AUTO_HOOK_MATCH(PauseMenuManager_RestartButtonPressed, &PauseMenuManager::RestartButtonPressed, void, PauseMenuManager *self) {
//    PauseMenuManager_RestartButtonPressed(self);
//        leftSaberScreen->SetActive(false);
//        rightSaberScreen->SetActive(false);
//}