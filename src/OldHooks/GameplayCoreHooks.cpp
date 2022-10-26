#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/GameplayCoreInstaller.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "chroma/shared/BombAPI.hpp"
using namespace Chroma;

MAKE_AUTO_HOOK_MATCH(GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
    GameplayCoreInstaller_InstallBindings(self);
    getModConfig().DidUserCrash.SetValue(true);

    getModConfig().ColoursChanged.SetValue(true);
    getLogger().info("Set Colours Changed to True on Map Start!");

    BombAPI::setGlobalBombColorSafe(getModConfig().BombColour.GetValue());
    getLogger().info("Set Bomb Colour on Map Start!");

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId); 

    getLogger().info("Saving all colours to config");
    getModConfig().LeftStart.SetValue(colourScheme->get_saberAColor());
    getModConfig().RightStart.SetValue(colourScheme->get_saberBColor());
    getModConfig().BombStart.SetValue(getModConfig().BombColour.GetValue());
    getModConfig().WallStart.SetValue(colourScheme->get_obstaclesColor());
    getLogger().info("Successfully saved all colours to config");
}