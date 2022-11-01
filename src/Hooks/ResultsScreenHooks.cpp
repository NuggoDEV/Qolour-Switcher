#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/ResultsViewController.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

GameObject *restoreContainer;

MAKE_AUTO_HOOK_MATCH(ResultsViewController_DidActivate, &ResultsViewController::DidActivate, void, ResultsViewController *self, bool firstActivation, bool addedToHierarchy, bool screensystemEnabling)
{
    ResultsViewController_DidActivate(self, firstActivation, addedToHierarchy, screensystemEnabling);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    if (firstActivation)
    {
        restoreContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(-0.75f, 0.3f, 4.0f), Vector3(35.0f, 0.0f, 0.0f), 0.0f, false, false);

        BeatSaberUI::CreateUIButton(restoreContainer->get_transform(), "Restore Colours", [colourScheme]()
        {
            colourScheme->saberAColor = getModConfig().LeftStart.GetValue();
            colourScheme->saberBColor = getModConfig().RightStart.GetValue();
            colourScheme->obstaclesColor = getModConfig().WallStart.GetValue();
            getModConfig().BombColour.SetValue(getModConfig().BombStart.GetValue());
        });
    }
    restoreContainer->SetActive(true);
}

MAKE_AUTO_HOOK_MATCH(ResultsViewController_DidDeactivate, &ResultsViewController::DidDeactivate, void, ResultsViewController *self, bool removedFromHierarchy, bool screenSystemDisabling)
{
    ResultsViewController_DidDeactivate(self, removedFromHierarchy, screenSystemDisabling);

    restoreContainer->SetActive(false);
}