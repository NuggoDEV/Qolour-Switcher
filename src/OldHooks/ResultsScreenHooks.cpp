#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/ResultsViewController.hpp"
#include "GlobalNamespace/BeatEffectSpawner.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Color.hpp"
#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

using namespace QuestUI;

GameObject *restoreScreen;
bool restoreScreenActive;

MAKE_AUTO_HOOK_MATCH(ResultsViewController_DidActivate, &ResultsViewController::DidActivate, void, ResultsViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    ResultsViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);
    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);
    
    if (firstActivation)
    {
        restoreScreen = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(-1.20f, -0.1f, 4.0f), Vector3(35.0f, 0.0f, 0.0f), 0.0f, false, false);
        BeatSaberUI::CreateUIButton(restoreScreen->get_transform(), "Restore Colours", Vector2(40.0f, 10.0f), [colourScheme]()
        {
            colourScheme->saberAColor = getModConfig().LeftStart.GetValue();
            colourScheme->saberBColor = getModConfig().RightStart.GetValue();
            colourScheme->obstaclesColor = getModConfig().WallStart.GetValue();
            getModConfig().BombColour.SetValue(getModConfig().BombStart.GetValue());
            getModConfig().DidUserCrash.SetValue(false);
        });
        restoreScreenActive = true;
    }
    if (!restoreScreenActive)
    {
        restoreScreen->SetActive(true);
        restoreScreenActive = true;
    }
}

MAKE_AUTO_HOOK_MATCH(ResultsViewController_DidDeactivate, &ResultsViewController::DidDeactivate, void, ResultsViewController *self, bool removedFromHierarchy, bool screenSystemDisabling)
{
    ResultsViewController_DidDeactivate(self, removedFromHierarchy, screenSystemDisabling);

    restoreScreen->SetActive(false);
    restoreScreenActive = false;
    getModConfig().DidUserCrash.SetValue(false);
}