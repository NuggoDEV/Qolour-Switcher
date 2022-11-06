#include "main.hpp"
#include "ModUI/QolourSwitcherFlowCoordinator.hpp"

#include "GlobalNamespace/MenuTransitionsHelper.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(QolourSwitcher::UI, QolourSwitcherFlowCoordinator);

void QolourSwitcher::UI::QolourSwitcherFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        SetTitle("Qolour Switcher axscds", HMUI::ViewController::AnimationType::Out);

        showBackButton = true;

        qolourSwitcherViewController = QuestUI::BeatSaberUI::CreateViewController<QolourSwitcher::UI::QolourSwitcherViewController *>();
        qolourSwitcherViewController->flowCoordinator = this;

        currentViewController = nullptr;

        ProvideInitialViewControllers(qolourSwitcherViewController, nullptr, nullptr, nullptr, nullptr);
    }
}

void QolourSwitcher::UI::QolourSwitcherFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    if (currentViewController)
    {
        SetTitle("VFJOFFGER", HMUI::ViewController::AnimationType::In);
        ReplaceTopViewController(qolourSwitcherViewController, this, this, nullptr, HMUI::ViewController::AnimationType::Out, HMUI::ViewController::AnimationDirection::Horizontal);

        currentViewController = nullptr;

        parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
    }
}