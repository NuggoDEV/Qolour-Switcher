#pragma once

#include "HMUI/ViewController.hpp"
#include "custom-types/shared/macros.hpp"
#include "custom-types/shared/coroutine.hpp"

#include "bsml/shared/macros.hpp"
#include "bsml/shared/BSML/Components/Settings/SliderSetting.hpp"
using namespace BSML;

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(QolourSwitcher::UI::ViewControllers, QolourSwitcherUI, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&HMUI::ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_INSTANCE_METHOD(void, Update);

    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider1);
    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider2);
    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider3);
    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider4);


    DECLARE_BSML_PROPERTY(Color, LeftSaber);
    DECLARE_BSML_PROPERTY(Color, RightSaber);
    DECLARE_BSML_PROPERTY(Color, BombColour);
    DECLARE_BSML_PROPERTY(Color, WallColour);


    DECLARE_BSML_PROPERTY(bool, TimedToggle1);
    DECLARE_BSML_PROPERTY(float, TimedActivation1);
    DECLARE_BSML_PROPERTY(Color, LeftSaber1);
    DECLARE_BSML_PROPERTY(Color, RightSaber1);
    DECLARE_BSML_PROPERTY(Color, BombColour1);
    DECLARE_BSML_PROPERTY(Color, WallColour1);


    DECLARE_BSML_PROPERTY(bool, TimedToggle2);
    DECLARE_BSML_PROPERTY(float, TimedActivation2);
    DECLARE_BSML_PROPERTY(Color, LeftSaber2);
    DECLARE_BSML_PROPERTY(Color, RightSaber2);
    DECLARE_BSML_PROPERTY(Color, BombColour2);
    DECLARE_BSML_PROPERTY(Color, WallColour2);


    DECLARE_BSML_PROPERTY(bool, TimedToggle3);
    DECLARE_BSML_PROPERTY(float, TimedActivation3);
    DECLARE_BSML_PROPERTY(Color, LeftSaber3);
    DECLARE_BSML_PROPERTY(Color, RightSaber3);
    DECLARE_BSML_PROPERTY(Color, BombColour3);
    DECLARE_BSML_PROPERTY(Color, WallColour3);


    DECLARE_BSML_PROPERTY(bool, TimedToggle4);
    DECLARE_BSML_PROPERTY(float, TimedActivation4);
    DECLARE_BSML_PROPERTY(Color, LeftSaber4);
    DECLARE_BSML_PROPERTY(Color, RightSaber4);
    DECLARE_BSML_PROPERTY(Color, BombColour4);
    DECLARE_BSML_PROPERTY(Color, WallColour4);
)