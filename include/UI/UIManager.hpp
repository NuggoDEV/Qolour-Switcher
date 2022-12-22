#pragma once
#include "HMUI/ViewController.hpp"

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CLASS_CODEGEN(QolourSwitcher::UI, UIManager, Il2CppObject,
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, qolourSwitcherView);

    DECLARE_BSML_PROPERTY(Color, LeftSaber);
    DECLARE_BSML_PROPERTY(Color, RightSaber);
    DECLARE_BSML_PROPERTY(Color, BombColour);
    DECLARE_BSML_PROPERTY(Color, WallColour);

    DECLARE_BSML_PROPERTY(bool, TimedToggle1);
    DECLARE_BSML_PROPERTY(float, TimedActivation1);
    DECLARE_BSML_PROPERTY(Color, LeftColour1);
    DECLARE_BSML_PROPERTY(Color, RightColour1);
    DECLARE_BSML_PROPERTY(Color, BombColour1);
    DECLARE_BSML_PROPERTY(Color, WallColour1);


    DECLARE_BSML_PROPERTY(bool, TimedToggle2);
    DECLARE_BSML_PROPERTY(float, TimedActivation2);
    DECLARE_BSML_PROPERTY(Color, LeftColour2);
    DECLARE_BSML_PROPERTY(Color, RightColour2);
    DECLARE_BSML_PROPERTY(Color, BombColour2);
    DECLARE_BSML_PROPERTY(Color, WallColour2);


    DECLARE_BSML_PROPERTY(bool, TimedToggle3);
    DECLARE_BSML_PROPERTY(float, TimedActivation3);
    DECLARE_BSML_PROPERTY(Color, LeftColour3);
    DECLARE_BSML_PROPERTY(Color, RightColour3);
    DECLARE_BSML_PROPERTY(Color, BombColour3);
    DECLARE_BSML_PROPERTY(Color, WallColour3);


    DECLARE_BSML_PROPERTY(bool, TimedToggle4);
    DECLARE_BSML_PROPERTY(float, TimedActivation4);
    DECLARE_BSML_PROPERTY(Color, LeftColour4);
    DECLARE_BSML_PROPERTY(Color, RightColour4);
    DECLARE_BSML_PROPERTY(Color, BombColour4);
    DECLARE_BSML_PROPERTY(Color, WallColour4);

    DECLARE_CTOR(ctor);
    public:
        static UIManager *get_instance();
    private:
        static SafePtr<UIManager> instance;
)