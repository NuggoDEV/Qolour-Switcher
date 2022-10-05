#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig, 
    CONFIG_VALUE(ModToggle, bool, "Disable Qolour Switcher", false);
    CONFIG_VALUE(ColoursChanged, bool, "When a Colour Gets Changed", false);
    CONFIG_VALUE(BombColour, Color, "Bomb Colour Value", Color(0.1, 0.1, 0.1, 1));

    CONFIG_VALUE(LeftSaberStartColour, Color, "Left Saber Colour Value", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightSaberStartColour, Color, "Right Saber Colour Value", Color(0, 0, 1, 1));
    CONFIG_VALUE(WallStartColour, Color, "Wall Colour Value", Color(1, 0, 0, 0.5));
    CONFIG_VALUE(BombStartColour, Color, "Bomb Start Colour Value", Color(0.1, 0.1, 0.1, 1));
    
    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(ModToggle);
        CONFIG_INIT_VALUE(ColoursChanged);
        CONFIG_INIT_VALUE(BombColour);

        CONFIG_INIT_VALUE(LeftSaberStartColour);
        CONFIG_INIT_VALUE(RightSaberStartColour);
        CONFIG_INIT_VALUE(WallStartColour);
        CONFIG_INIT_VALUE(BombStartColour);
    )
)