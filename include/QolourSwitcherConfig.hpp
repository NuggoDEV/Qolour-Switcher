#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig, 
    CONFIG_VALUE(ModToggle, bool, "Disable Qolour Switcher", false);
    CONFIG_VALUE(ColoursChanged, bool, "When a Colour Gets Changed", false);
    CONFIG_VALUE(ExtraToggle, bool, "Enable Extra Toggles", false);
    CONFIG_VALUE(BombColour, Color, "Bomb Colour Value", Color(0.1, 0.1, 0.1, 1));
    
    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(ModToggle);
        CONFIG_INIT_VALUE(ColoursChanged);
        CONFIG_INIT_VALUE(ExtraToggle);
        CONFIG_INIT_VALUE(BombColour);
    )
)