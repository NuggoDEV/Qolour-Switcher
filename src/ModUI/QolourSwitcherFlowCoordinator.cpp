#include "ModUI/QolourSwitcherFlowCoordinator.hpp"
#include "ModUI/QolourSwitcherViewController.hpp"

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(QolourSwitcher::UI, QolourSwitcherFlowCoordinator);

void QolourSwitcher::UI::QolourSwitcherFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        timedSettingsViewController = BeatSaberUI::CreateViewController<QolourSwitcher::UI::TimedSettingsViewController *>();
        mainSettingsViewController = BeatSaberUI::CreateViewController<QolourSwitcher::UI::QolourSwitcherSettingsViewController *>();
        toggleSettingsViewController = BeatSaberUI::CreateViewController<QolourSwitcher::UI::ToggleSettingsViewController *>();

        showBackButton = true;

        ProvideInitialViewControllers(mainSettingsViewController, toggleSettingsViewController, timedSettingsViewController, nullptr, nullptr);
        SetTitle("Qolour Switcher Settings", HMUI::ViewController::AnimationType::In);
    }
}

void QolourSwitcher::UI::QolourSwitcherFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}