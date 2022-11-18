#pragma once

#include "config-utils/shared/config-utils.hpp"
#include "bsml/shared/macros.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(didUserCrash, bool, "Causes restore colours prompt to appear", false);
    CONFIG_VALUE(coloursChanged, bool, "Turns true when one of the colours are changed via the pause menu", false);
    

    CONFIG_VALUE(toggleSwitch1, bool, "Activates the first timed switch", false);
    CONFIG_VALUE(toggleSwitch2, bool, "Activates the second timed switch", false);
    CONFIG_VALUE(toggleSwitch3, bool, "Activates the third timed switch", false);
    CONFIG_VALUE(toggleSwitch4, bool, "Activates the fourth timed switch", false);

    CONFIG_VALUE(timedSwitch1, float, "Time for the first colour switch to happen", 0);
    CONFIG_VALUE(timedSwitch2, float, "Time for the second colour switch to happen", 0);
    CONFIG_VALUE(timedSwitch3, float, "Time for the third colour switch to happen", 0);
    CONFIG_VALUE(timedSwitch4, float, "Time for the fourth colour switch to happen", 0);

    CONFIG_VALUE(bombColour, Color, "Bomb colour since base game doesn't save value", Color(0.1f, 0.1f, 0.1f, 1.0f));

    CONFIG_VALUE(leftStartColour, Color, "Left saber start value for restore prompt", Color(0.1f, 0.1f, 0.1f, 1.0f));
    CONFIG_VALUE(rightStartColour, Color, "Right saber start value for restore prompt", Color(0.1f, 0.1f, 0.1f, 1.0f));
    CONFIG_VALUE(bombStartColour, Color, "Bomb start value for restore prompt", Color(0.1f, 0.1f, 0.1f, 1.0f));
    CONFIG_VALUE(wallStartColour, Color, "Wall start value for restore prompt", Color(0.1f, 0.1f, 0.1f, 1.0f));

    CONFIG_VALUE(timedSwitch1LeftColour, Color, "Left saber colour for first switch", Color(1.0f, 0.0f, 0.0f, 1.0f));
    CONFIG_VALUE(timedSwitch1RightColour, Color, "Right saber colour for first switch", Color(0.0f, 0.0f, 1.0f, 1.0f));
    CONFIG_VALUE(timedSwitch1BombColour, Color, "Bomb colour for first switch", Color(0.1f, 0.1f, 0.1f, 1.0f));
    CONFIG_VALUE(timedSwitch1WallColour, Color, "Wall colour for first switch", Color(0.7f, 0.0f, 0.0f, 1.0f));

    CONFIG_VALUE(timedSwitch2LeftColour, Color, "Left saber colour for second switch", Color(1.0f, 0.0f, 0.0f, 1.0f));
    CONFIG_VALUE(timedSwitch2RightColour, Color, "Right saber colour for second switch", Color(0.0f, 0.0f, 1.0f, 1.0f));
    CONFIG_VALUE(timedSwitch2BombColour, Color, "Bomb colour for second switch", Color(0.1f, 0.1f, 0.1f, 1.0f));
    CONFIG_VALUE(timedSwitch2WallColour, Color, "Wall colour for second switch", Color(0.7f, 0.0f, 0.0f, 1.0f));

    CONFIG_VALUE(timedSwitch3LeftColour, Color, "Left saber colour for third switch", Color(1.0f, 0.0f, 0.0f, 1.0f));
    CONFIG_VALUE(timedSwitch3RightColour, Color, "Right saber colour for third switch", Color(0.0f, 0.0f, 1.0f, 1.0f));
    CONFIG_VALUE(timedSwitch3BombColour, Color, "Bomb colour for third switch", Color(0.1f, 0.1f, 0.1f, 1.0f));
    CONFIG_VALUE(timedSwitch3WallColour, Color, "Wall colour for third switch", Color(0.7f, 0.0f, 0.0f, 1.0f));

    CONFIG_VALUE(timedSwitch4LeftColour, Color, "Left saber colour for fourth switch", Color(1.0f, 0.0f, 0.0f, 1.0f));
    CONFIG_VALUE(timedSwitch4RightColour, Color, "Right saber colour for fourth switch", Color(0.0f, 0.0f, 1.0f, 1.0f));
    CONFIG_VALUE(timedSwitch4BombColour, Color, "Bomb colour for fourth switch", Color(0.1f, 0.1f, 0.1f, 1.0f));
    CONFIG_VALUE(timedSwitch4WallColour, Color, "Wall colour for fourth switch", Color(0.7f, 0.0f, 0.0f, 1.0f));

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(didUserCrash);
        CONFIG_INIT_VALUE(coloursChanged);
        CONFIG_INIT_VALUE(bombColour);

        CONFIG_INIT_VALUE(toggleSwitch1);
        CONFIG_INIT_VALUE(toggleSwitch2);
        CONFIG_INIT_VALUE(toggleSwitch3);
        CONFIG_INIT_VALUE(toggleSwitch4);

        CONFIG_INIT_VALUE(timedSwitch1);
        CONFIG_INIT_VALUE(timedSwitch2);
        CONFIG_INIT_VALUE(timedSwitch3);
        CONFIG_INIT_VALUE(timedSwitch4);

        CONFIG_INIT_VALUE(timedSwitch1LeftColour);
        CONFIG_INIT_VALUE(timedSwitch1RightColour);
        CONFIG_INIT_VALUE(timedSwitch1BombColour);
        CONFIG_INIT_VALUE(timedSwitch1WallColour);
        
        CONFIG_INIT_VALUE(timedSwitch2LeftColour);
        CONFIG_INIT_VALUE(timedSwitch2RightColour);
        CONFIG_INIT_VALUE(timedSwitch2BombColour);
        CONFIG_INIT_VALUE(timedSwitch2WallColour);

        CONFIG_INIT_VALUE(timedSwitch3LeftColour);
        CONFIG_INIT_VALUE(timedSwitch3RightColour);
        CONFIG_INIT_VALUE(timedSwitch3BombColour);
        CONFIG_INIT_VALUE(timedSwitch3WallColour);

        CONFIG_INIT_VALUE(timedSwitch4LeftColour);
        CONFIG_INIT_VALUE(timedSwitch4RightColour);
        CONFIG_INIT_VALUE(timedSwitch4BombColour);
        CONFIG_INIT_VALUE(timedSwitch4WallColour);
    )
)