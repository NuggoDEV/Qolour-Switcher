#include "UI/FlowCoordinators/QolourSwitcherFlowCoordinator.hpp"
using namespace QolourSwitcher::UI::FlowCoordinators;

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(QolourSwitcher::UI::FlowCoordinators, QolourSwitcherFlowCoordinator);

void QolourSwitcherFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    SetTitle("Qolour Switcher", HMUI::ViewController::AnimationType::In);
    showBackButton = true;
    
    QolourSwitcherViewController = QuestUI::BeatSaberUI::CreateViewController<ViewControllers::QolourSwitcherUI *>();

    
    ProvideInitialViewControllers(QolourSwitcherViewController, nullptr, nullptr, nullptr, nullptr);
}

void QolourSwitcherFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}