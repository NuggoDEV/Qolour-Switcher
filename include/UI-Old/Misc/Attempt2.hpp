#pragma once

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"
#include "bsml/shared/BSML/Components/Settings/ColorSetting.hpp"

DECLARE_CLASS_CODEGEN(QolourSwitcher::UI::Misc, PauseMenu, Il2CppObject,

    DECLARE_BSML_PROPERTY(UnityEngine::Color, LeftSaber);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, RightSaber);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, BombColour);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, WallColour);
)