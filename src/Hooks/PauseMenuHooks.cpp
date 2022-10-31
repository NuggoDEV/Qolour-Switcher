#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/BeatEffectSpawner.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Object.hpp"
#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

GameObject *leftNoteContainer;
GameObject *rightNoteContainer;
GameObject *bombContainer;
GameObject *wallContainer;

bool firstActivation;

MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ShowMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
{
    PauseMenuManager_ShowMenu(self);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    if (firstActivation)
    {
        leftNoteContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(-1.2f, 2.85f, 2.3f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);
        rightNoteContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(-1.6f, 2.3f, 2.85f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);
        bombContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(1.2f, 2.3f, 2.85f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);
        wallContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(1.6f, 2.3f, 2.85f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);

        BeatSaberUI::CreateColorPicker(leftNoteContainer->get_transform(), "", colourScheme->get_saberAColor(), [colourScheme](Color value)
        {   colourScheme->saberAColor = value;  });

        BeatSaberUI::CreateColorPicker(rightNoteContainer->get_transform(), "", colourScheme->get_saberBColor(), [colourScheme](Color value)
        {   colourScheme->saberBColor = value;  });

        BeatSaberUI::CreateColorPicker(bombContainer->get_transform(), "", getModConfig().BombColour.GetValue(), [&](Color value)
        {   getModConfig().BombColour.SetValue(value);  });

        BeatSaberUI::CreateColorPicker(wallContainer->get_transform(), "", colourScheme->get_obstaclesColor(), [colourScheme](Color value)
        {   colourScheme->obstaclesColor = value;  });

        firstActivation = false;
    }

    if (!firstActivation)
        leftNoteContainer->SetActive(true);
        rightNoteContainer->SetActive(true);
        bombContainer->SetActive(true);
        wallContainer->SetActive(true);
}

MAKE_AUTO_HOOK_MATCH(Pause_BeatEffectSpawner_Start, &BeatEffectSpawner::Start, void, BeatEffectSpawner *self)
{
    firstActivation = true;
}