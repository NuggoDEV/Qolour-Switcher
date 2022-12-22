#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/DefaultScenesTransitionsFromInit.hpp"
#include "GlobalNamespace/MainMenuViewController.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(InitSceneTransitions_TransitionToNextScene, &DefaultScenesTransitionsFromInit::TransitionToNextScene, void, DefaultScenesTransitionsFromInit *self, bool goStraightToMenu, bool goStraightToEditor, bool goToRecordingToolScene)
{
    InitSceneTransitions_TransitionToNextScene(self, goStraightToMenu, goStraightToEditor, goToRecordingToolScene);

    auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModal->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    getModConfig().LeftSaber.SetValue(colourScheme->get_saberAColor());
    getModConfig().RightSaber.SetValue(colourScheme->get_saberBColor());
    getModConfig().WallColour.SetValue(colourScheme->get_obstaclesColor());
}

MAKE_AUTO_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void, MainMenuViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);

    auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModal->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    colourScheme->saberAColor = getModConfig().LeftSaber.GetValue();
    colourScheme->saberBColor = getModConfig().RightSaber.GetValue();
    colourScheme->obstaclesColor = getModConfig().WallColour.GetValue();
}