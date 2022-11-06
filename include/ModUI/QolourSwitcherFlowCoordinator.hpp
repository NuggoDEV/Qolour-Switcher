#pragma once

#include "main.hpp"
#include "ModUI/QolourSwitcherViewController.hpp"
#include "ModUI/TimedSettingsViewController.hpp"

#include "custom-types/shared/macros.hpp"
#include "custom-types/shared/register.hpp"

#include "HMUI/FlowCoordinator.hpp"

DECLARE_CLASS_CODEGEN(QolourSwitcher::UI, QolourSwitcherFlowCoordinator, HMUI::FlowCoordinator,

    DECLARE_INSTANCE_FIELD(QolourSwitcher::UI::QolourSwitcherViewController *qolourSwitcherViewController);
    DECLARE_INSTANCE_FIELD(QolourSwitcher::UI::TimedSettingsViewController *timedSettingsViewController);

    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, currentViewController);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "BackButtonWasPressed", 1), HMUI::ViewController* topViewController);
)