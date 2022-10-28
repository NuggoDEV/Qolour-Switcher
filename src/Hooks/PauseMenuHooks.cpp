#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
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

bool firstActivation = true;


MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ShowMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
{
    if (firstActivation)
    {
        auto playerDataModal = Object::FindObjectOfType<PlayerDataModel *>();
        auto playerData = playerDataModal->playerData;
        auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

        leftNoteContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(-1.2f, 2.3f, 2.85f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);
        rightNoteContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(-1.6f, 2.3f, 2.85f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);
        bombContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(1.2f, 2.3f, 2.85f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);
        wallContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(1.6f, 2.3f, 2.85f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, true, true, 1);
    }
}