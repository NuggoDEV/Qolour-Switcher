#pragma once

#include "main.hpp"

#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController.hpp"
#include "ModUI/TimedSettingsViewController.hpp"

#include "custom-types/shared/macros.hpp"


DECLARE_CLASS_CODEGEN(QolourSwitcher::UI, QolourSwitcherSettingsViewController, HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(QolourSwitcher::UI::TimedSettingsViewController*, timedSettingsViewController);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)