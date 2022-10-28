#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig, 
    CONFIG_VALUE(DidUserCrash, bool, "If the user crashes before results screen", true);
    CONFIG_VALUE(ColoursChanged, bool, "When a Colour Gets Changed", false);
    CONFIG_VALUE(BombColour, Color, "", Color(0.1, 0.1, 0.1, 0.5));

    CONFIG_VALUE(LeftStart, Color, "Left Saber Level Start Value", Color(1, 0, 0, 1));
    CONFIG_VALUE(RightStart, Color, "Right Saber Level Start Value", Color(0, 0, 1, 1));
    CONFIG_VALUE(BombStart, Color, "Bomb Level Start Value", Color(0.1, 0.1, 0.1, 1));
    CONFIG_VALUE(WallStart, Color, "Wall Level Start Value", Color(0.7, 0, 0, 1));

    CONFIG_VALUE(ColourPickerLocation, std::string, "Position of the Colour Pickers", "Top");

    CONFIG_VALUE(LeftNotePosition, Vector3, "Left Note Picker Position", Vector3(-2.0f, 0.4f, 0.2f));
    CONFIG_VALUE(LeftNoteRotation, Vector3, "Left Note Picker Position", Vector3(-2.0f, 0.4f, 0.2f));

    CONFIG_VALUE(RightNotePosition, Vector3, "Right Note Picker Position", Vector3(-2.0f, 0.4f, 0.2f));
    CONFIG_VALUE(RightNoteRotation, Vector3, "Right Note Picker Position", Vector3(-2.0f, 0.4f, 0.2f));

    CONFIG_VALUE(BombPosition, Vector3, "Bomb Picker Position", Vector3(-2.0f, 0.4f, 0.2f));
    CONFIG_VALUE(BombRotation, Vector3, "Bomb Picker Position", Vector3(-2.0f, 0.4f, 0.2f));

    CONFIG_VALUE(WallPosition, Vector3, "Wall Picker Position", Vector3(-2.0f, 0.4f, 0.2f));
    CONFIG_VALUE(WallRotation, Vector3, "Wall Picker Position", Vector3(-2.0f, 0.4f, 0.2f));

    CONFIG_VALUE(TimedSwitch1, bool, "", false);
    CONFIG_VALUE(TimedSwitch2, bool, "", false);
    CONFIG_VALUE(TimedSwitch3, bool, "", false);
    CONFIG_VALUE(TimedSwitch4, bool, "", false);

    CONFIG_VALUE(TimedSwitch1Int, int, "", 0);
    CONFIG_VALUE(TimedSwitch2Int, int, "", 120);
    CONFIG_VALUE(TimedSwitch3Int, int, "", 240);
    CONFIG_VALUE(TimedSwitch4Int, int, "", 360);
    
    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(DidUserCrash);
        CONFIG_INIT_VALUE(ColoursChanged);
        CONFIG_INIT_VALUE(BombColour);

        CONFIG_INIT_VALUE(LeftStart);
        CONFIG_INIT_VALUE(RightStart);
        CONFIG_INIT_VALUE(BombStart);
        CONFIG_INIT_VALUE(WallStart);

        CONFIG_INIT_VALUE(ColourPickerLocation);

        CONFIG_INIT_VALUE(LeftNotePosition);
        CONFIG_INIT_VALUE(LeftNoteRotation);

        CONFIG_INIT_VALUE(RightNotePosition);
        CONFIG_INIT_VALUE(RightNoteRotation);

        CONFIG_INIT_VALUE(BombPosition);
        CONFIG_INIT_VALUE(BombRotation);

        CONFIG_INIT_VALUE(WallPosition);
        CONFIG_INIT_VALUE(WallRotation);

        CONFIG_INIT_VALUE(TimedSwitch1);
        CONFIG_INIT_VALUE(TimedSwitch2);
        CONFIG_INIT_VALUE(TimedSwitch3);
        CONFIG_INIT_VALUE(TimedSwitch4);

        CONFIG_INIT_VALUE(TimedSwitch1Int);
        CONFIG_INIT_VALUE(TimedSwitch2Int);
        CONFIG_INIT_VALUE(TimedSwitch3Int);
        CONFIG_INIT_VALUE(TimedSwitch4Int);

    )
)