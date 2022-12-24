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

DECLARE_CLASS_CODEGEN(QolourSwitcher::UI::ViewControllers, QolourSwitcherViewController, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&HMUI::ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider1);
    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider2);
    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider3);
    DECLARE_INSTANCE_FIELD(SliderSetting*, TimeSlider4);

)