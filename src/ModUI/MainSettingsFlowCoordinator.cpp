#include "main.hpp"
#include "ModUI/FlowCoordinator.hpp"
#include "ModUI/MainSettingsViewController.hpp"
#include "ModUI/TimedSettingsViewController.hpp"
using namespace QolourSwitcherUI;

#include "GlobalNamespace/MenuTransitionsHelper.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(QolourSwitcherUI, SettingsFlowCoordinator);

void SettingsFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        SetTitle("Main Settings", HMUI::ViewController::AnimationType::Out);

        showBackButton = true;

        settingsViewController = QuestUI::BeatSaberUI::CreateViewController<QolourSwitcher::Views::MainSettingsViewController *>();
        timedSettingsViewController = QuestUI::BeatSaberUI::CreateViewController<QolourSwitcher::Views::TimedSettingsViewController *>();

        currentViewController = nullptr;

        ProvideInitialViewControllers(settingsViewController, timedSettingsViewController, nullptr, nullptr, nullptr);
    }
}

void SettingsFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);

    if (currentViewController)
    {
        SetTitle("Timed Switches", HMUI::ViewController::AnimationType::In);
        ReplaceTopViewController(settingsViewController, this, this, nullptr, HMUI::ViewController::AnimationType::Out, HMUI::ViewController::AnimationDirection::Horizontal);

        currentViewController = nullptr;
    }
    else
    {
        parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
    }
}