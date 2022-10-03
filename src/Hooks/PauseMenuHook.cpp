#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"

#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
using namespace Chroma;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/SaberType.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;



GameObject *leftSaberScreen;
GameObject *rightSaberScreen;
GameObject *bombScreen;
GameObject *wallScreen;
bool screensEnabled;

MAKE_AUTO_HOOK_MATCH(PauseMenuManager_ShowMenu, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
{
    PauseMenuManager_ShowMenu(self);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);


    if (!getModConfig().ModToggle.GetValue())
    {
        leftSaberScreen = BeatSaberUI::CreateFloatingScreen(Vector2(10.0f, 10.0f), Vector3(-0.5f, 2.85f, 2.4f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);
        rightSaberScreen = BeatSaberUI::CreateFloatingScreen(Vector2(10.0f, 10.0f), Vector3(0.5f, 2.85f, 2.4f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);       

        bombScreen = BeatSaberUI::CreateFloatingScreen(Vector2(10.0f, 10.0f), Vector3(-0.5f, 3.2f, 2.35f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);
        wallScreen = BeatSaberUI::CreateFloatingScreen(Vector2(10.0f, 10.0f), Vector3(0.5f, 3.2f, 2.35f), Vector3(-30.0f, 0.0f, 0.0f), 0.0f, false, false);


        BeatSaberUI::CreateText(leftSaberScreen->get_transform(), "Left Saber Colour!", Vector2(17.5f, 0.0f));

        BeatSaberUI::CreateColorPicker(leftSaberScreen->get_transform(), "", colourScheme->get_saberAColor(), [colourScheme](Color colour)
        {
            getLogger().info("Saving left saber colour!");
            colourScheme->saberAColor = colour;
            getModConfig().ColoursChanged.SetValue(true);
        });


        BeatSaberUI::CreateText(rightSaberScreen->get_transform(), "Right Saber Colour!", Vector2(15.0f, 0.0f));

        BeatSaberUI::CreateColorPicker(rightSaberScreen->get_transform(), "", colourScheme->get_saberBColor(), [colourScheme](Color colour)
        {
            getLogger().info("Saving right saber colour");
            colourScheme->saberBColor = colour;
            getModConfig().ColoursChanged.SetValue(true);
        });

        if (getModConfig().ExtraToggle.GetValue())
        {
            BeatSaberUI::CreateText(bombScreen->get_transform(), "Bomb Colour!", Vector2(20.0f, 0.0f));

            BeatSaberUI::CreateColorPicker(bombScreen->get_transform(), "", getModConfig().BombColour.GetValue(), [&](Color colour)
            {
                getLogger().info("Saving Bomb Colour!");
                getModConfig().BombColour.SetValue(colour);
                getModConfig().ColoursChanged.SetValue(true);
            });


            BeatSaberUI::CreateText(wallScreen->get_transform(), "Wall Colour!", Vector2(20.0f, 0.0f));

            BeatSaberUI::CreateColorPicker(wallScreen->get_transform(), "", colourScheme->get_obstaclesColor(), [colourScheme](Color colour)
            {
                getLogger().info("Saving Wall Colour!");
                colourScheme->obstaclesColor = colour;
                getModConfig().ColoursChanged.SetValue(true);
            });
        }

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