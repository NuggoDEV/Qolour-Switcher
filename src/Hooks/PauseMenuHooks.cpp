#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/GameplayCoreInstaller.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Object.hpp"
#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
using namespace Chroma;

GameObject *leftNoteContainer;
GameObject *rightNoteContainer;
GameObject *bombContainer;
GameObject *wallContainer;

GameObject *test;

bool firstActivation;

MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ShowMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
{
    PauseMenuManager_ShowMenu(self);

    leftNoteContainer->SetActive(true);
    rightNoteContainer->SetActive(true);
    bombContainer->SetActive(true);
    wallContainer->SetActive(true);
}

MAKE_AUTO_HOOK_MATCH(Pause_PauseMenuManager_ContinueButtonPressed, &PauseMenuManager::ContinueButtonPressed, void, PauseMenuManager *self)
{
    Pause_PauseMenuManager_ContinueButtonPressed(self);

    leftNoteContainer->SetActive(false);
    rightNoteContainer->SetActive(false);
    bombContainer->SetActive(false);
    wallContainer->SetActive(false);
}

MAKE_AUTO_HOOK_MATCH(Pause_GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
    Pause_GameplayCoreInstaller_InstallBindings(self);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    leftNoteContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(-0.4f, 2.85f, 2.4f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
    rightNoteContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(0.4f, 2.85f, 2.4f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
    bombContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(-1.2f, 2.85f, 2.4f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
    wallContainer = BeatSaberUI::CreateFloatingScreen(Vector2(0.0f, 0.0f), Vector3(1.2f, 2.85f, 2.4f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, false, false);

    test = BeatSaberUI::CreateCanvas();
    auto testB = BeatSaberUI::CreateHorizontalLayoutGroup(test->get_transform());

    BeatSaberUI::CreateText(leftNoteContainer->get_transform(), "Left Saber Colour!", Vector2(13.5f, -5.0f));
    BeatSaberUI::CreateColorPicker(leftNoteContainer->get_transform(), "", colourScheme->get_saberAColor(), [colourScheme](Color value)
    {   
        colourScheme->saberAColor = value;
        NoteAPI::setGlobalNoteColorSafe(value, colourScheme->saberBColor);
    });

    BeatSaberUI::CreateText(rightNoteContainer->get_transform(), "Right Saber Colour!", Vector2(12.5f, -5.0f));
    BeatSaberUI::CreateColorPicker(rightNoteContainer->get_transform(), "", colourScheme->get_saberBColor(), [colourScheme](Color value)
    {   
        colourScheme->saberBColor = value;
        NoteAPI::setGlobalNoteColorSafe(colourScheme->saberAColor, value);
    });

    BeatSaberUI::CreateText(bombContainer->get_transform(), "Bomb Colour!", Vector2(16.0f, -5.0f));
    BeatSaberUI::CreateColorPicker(bombContainer->get_transform(), "", getModConfig().BombColour.GetValue(), [&](Color value)
    {   
        getModConfig().BombColour.SetValue(value);
        BombAPI::setGlobalBombColorSafe(value);
    });

    BeatSaberUI::CreateText(wallContainer->get_transform(), "Wall Colour!", Vector2(16.0f, -5.0f));
    BeatSaberUI::CreateColorPicker(wallContainer->get_transform(), "", colourScheme->get_obstaclesColor(), [colourScheme](Color value)
    {   
        colourScheme->obstaclesColor = value;
        ObstacleAPI::setAllObstacleColorSafe(value);
    });

    leftNoteContainer->SetActive(false);
    rightNoteContainer->SetActive(false);
    bombContainer->SetActive(false);
    wallContainer->SetActive(false);
}