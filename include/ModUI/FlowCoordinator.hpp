#pragma once

#include "custom-types/shared/macros.hpp"
#include "custom-types/shared/register.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
#include "MainSettingsViewController.hpp"
#include "TimedSettingsViewController.hpp"
#include "main.hpp"

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(QolourSwitcherUI, SettingsFlowCoordinator, HMUI::FlowCoordinator,
    DECLARE_INSTANCE_FIELD(QolourSwitcher::Views::MainSettingsViewController*, settingsViewController);
    DECLARE_INSTANCE_FIELD(QolourSwitcher::Views::TimedSettingsViewController*, timedSettingsViewController);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&HMUI::ViewController::DidActivate), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, GET_FIND_METHOD(&HMUI::FlowCoordinator::BackButtonWasPressed), HMUI::ViewController* topViewController);
)