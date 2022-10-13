#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig, 
    CONFIG_VALUE(DidUserCrash, bool, "If the user crashes before results screen", true);
    CONFIG_VALUE(ColoursChanged, bool, "When a Colour Gets Changed", false);
    CONFIG_VALUE(BombColour, Color, "Bomb Colour Value", Color(0.1, 0.1, 0.1, 1));

    CONFIG_VALUE(LeftStart, Color, "Left Saber Level Start Value", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightStart, Color, "Right Saber Level Start Value", Color(0, 0, 1, 1));
    CONFIG_VALUE(BombStart, Color, "Bomb Level Start Value", Color(0.1, 0.1, 0.1, 1));
    CONFIG_VALUE(WallStart, Color, "Wall Level Start Value", Color(0.7, 0, 0, 1));
    
    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(DidUserCrash);
        CONFIG_INIT_VALUE(ColoursChanged);
        CONFIG_INIT_VALUE(BombColour);

        CONFIG_INIT_VALUE(LeftStart);
        CONFIG_INIT_VALUE(RightStart);
        CONFIG_INIT_VALUE(BombStart);
        CONFIG_INIT_VALUE(WallStart);
    )
)