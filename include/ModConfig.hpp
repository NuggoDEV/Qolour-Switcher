#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(LeftSaber, Color, "Left Saber", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightSaber, Color, "Right Saber", Color(0, 0, 1, 1));
    CONFIG_VALUE(BombColour, Color, "Bomb Colour", Color(0.1, 0.1, 0.1, 1));
    CONFIG_VALUE(WallColour, Color, "Wall Colour", Color(0.8, 0, 0, 1));

    CONFIG_VALUE(TimedToggle1, bool, "First Timed Switch Activation Toggle", false);
    CONFIG_VALUE(TimedActivation1, float, "First Timed Switch Activation", 0.0f);
    CONFIG_VALUE(LeftSaber1, Color, "Left Saber 1 Colour", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightSaber1, Color, "Right Saber 1 Colour", Color(0, 0, 1, 1));
    CONFIG_VALUE(BombColour1, Color, "Bomb Colour 1", Color(0.1, 0.1, 0.1, 1));
    CONFIG_VALUE(WallColour1, Color, "Wall Colour 1", Color(0.8, 0, 0, 1));


    CONFIG_VALUE(TimedToggle2, bool, "Second Timed Switch Activation Toggle", false);
    CONFIG_VALUE(TimedActivation2, float, "Second Timed Switch Activation", 0.0f);
    CONFIG_VALUE(LeftSaber2, Color, "Left Saber 2 Colour", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightSaber2, Color, "Right Saber 2 Colour", Color(0, 0, 1, 1));
    CONFIG_VALUE(BombColour2, Color, "Bomb Colour 2", Color(0.1, 0.1, 0.1, 1));
    CONFIG_VALUE(WallColour2, Color, "Wall Colour 2", Color(0.8, 0, 0, 1));


    CONFIG_VALUE(TimedToggle3, bool, "Third Timed Switch Activation Toggle", false);
    CONFIG_VALUE(TimedActivation3, float, "Third Timed Switch Activation", 0.0f);
    CONFIG_VALUE(LeftSaber3, Color, "Left Saber 3 Colour", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightSaber3, Color, "Right Saber 3 Colour", Color(0, 0, 1, 1));
    CONFIG_VALUE(BombColour3, Color, "Bomb Colour 3", Color(0.1, 0.1, 0.1, 1));
    CONFIG_VALUE(WallColour3, Color, "Wall Colour 3", Color(0.8, 0, 0, 1));


    CONFIG_VALUE(TimedToggle4, bool, "Fourth Timed Switch Activation Toggle", false);
    CONFIG_VALUE(TimedActivation4, float, "Fourth Timed Switch Activation", 0.0f);
    CONFIG_VALUE(LeftSaber4, Color, "Left Saber 4 Colour", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightSaber4, Color, "Right Saber 4 Colour", Color(0, 0, 1, 1));
    CONFIG_VALUE(BombColour4, Color, "Bomb Colour 4", Color(0.1, 0.1, 0.1, 1));
    CONFIG_VALUE(WallColour4, Color, "Wall Colour 4", Color(0.8, 0, 0, 1));
)