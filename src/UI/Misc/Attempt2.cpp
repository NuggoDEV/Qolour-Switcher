#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/LevelBar.hpp"
using namespace GlobalNamespace;

#include "bsml/shared/BSML/Components/ModalColorPicker.hpp"
#include "bsml/shared/BSML/GameplaySetup/GameplaySetup.hpp"

#include "bsml/shared/BSML.hpp"
#include "assets.hpp"
#include "UI/Misc/Attempt2.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

GameObject *gameObject;

namespace QolourSwitcher::UI::Misc
{
    MAKE_AUTO_HOOK_MATCH(SEIF, &PauseMenuManager::ShowMenu, void, PauseMenuManager *self)
    {
        SEIF(self);

        BSML::BSMLParser::parse_and_construct(IncludedAssets::pause_settings_bsml, gameObject->get_transform(), self);        
    }

    Color PauseMenu::get_LeftSaber() { return getModConfig().LeftSaber.GetValue(); }
    void PauseMenu::set_LeftSaber(Color value) { getModConfig().LeftSaber.SetValue(value); }

    Color PauseMenu::get_RightSaber() { return getModConfig().RightSaber.GetValue(); }
    void PauseMenu::set_RightSaber(Color value) { getModConfig().RightSaber.SetValue(value); }

    Color PauseMenu::get_BombColour() { return getModConfig().BombColour.GetValue(); }
    void PauseMenu::set_BombColour(Color value) { getModConfig().BombColour.SetValue(value); }

    Color PauseMenu::get_WallColour() { return getModConfig().WallColour.GetValue(); }
    void PauseMenu::set_WallColour(Color value) { getModConfig().WallColour.SetValue(value); }
}