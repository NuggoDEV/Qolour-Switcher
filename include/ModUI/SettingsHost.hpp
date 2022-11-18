#pragma once
#include "HMUI/ViewController.hpp"

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CLASS_CODEGEN(QolourSwitcher, SettingsHost, Il2CppObject,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, settingsViewController);

    DECLARE_BSML_PROPERTY(bool, toggleSwitch1);
    DECLARE_BSML_PROPERTY(bool, toggleSwitch2);
    DECLARE_BSML_PROPERTY(bool, toggleSwitch3);
    DECLARE_BSML_PROPERTY(bool, toggleSwitch4);

    DECLARE_BSML_PROPERTY(float, timedSwitch1);
    DECLARE_BSML_PROPERTY(float, timedSwitch2);
    DECLARE_BSML_PROPERTY(float, timedSwitch3);
    DECLARE_BSML_PROPERTY(float, timedSwitch4);

    DECLARE_BSML_PROPERTY(Color, timedSwitch1LeftColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch1RightColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch1BombColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch1WallColour);

    DECLARE_BSML_PROPERTY(Color, timedSwitch2LeftColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch2RightColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch2BombColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch2WallColour);

    DECLARE_BSML_PROPERTY(Color, timedSwitch3LeftColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch3RightColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch3BombColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch3WallColour);

    DECLARE_BSML_PROPERTY(Color, timedSwitch4LeftColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch4RightColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch4BombColour);
    DECLARE_BSML_PROPERTY(Color, timedSwitch4WallColour);

    DECLARE_CTOR(ctor);
    public:
        static SettingsHost *get_instance();
    private:
        static SafePtr<SettingsHost> instance;
)