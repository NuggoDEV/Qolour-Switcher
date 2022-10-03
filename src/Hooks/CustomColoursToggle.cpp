#include "main.hpp"
#include "QolourSwitcherHooks.hpp"

#include "GlobalNamespace/MainMenuViewController.hpp"
#include "GlobalNamespace/GameCoreSceneSetup.hpp"
#include "GlobalNamespace/StandardLevelDetailViewController.hpp"
#include "GlobalNamespace/ColorSchemeColorToggleController.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Object.hpp"
using namespace UnityEngine;

MAKE_AUTO_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void, MainMenuViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);
    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    bool customColours = playerData->colorSchemesSettings->overrideDefaultColors; // Look at ColorSchemesSettings.hpp and QolourSwitcherUI.cpp
    
    if (!customColours)
    {
        playerData->colorSchemesSettings->overrideDefaultColors = true;
    }
}

MAKE_AUTO_HOOK_MATCH(StandardLevelDetailViewController_DidActivate, &StandardLevelDetailViewController::DidActivate, void, StandardLevelDetailViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    StandardLevelDetailViewController_DidActivate(self, firstActivation, addedToHierarchy, firstActivation);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    bool customColours = playerData->colorSchemesSettings->overrideDefaultColors; 
    
    if (!customColours)
    {
        playerData->colorSchemesSettings->overrideDefaultColors = true;
    }    
}