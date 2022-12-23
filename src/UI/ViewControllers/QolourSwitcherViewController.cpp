#include "UI/ViewControllers/QolourSwitcherViewController.hpp"
using namespace QolourSwitcher::UI::ViewControllers;

#include "ModConfig.hpp"
#include "bsml/shared/BSML.hpp"
#include "assets.hpp"

DEFINE_TYPE(QolourSwitcher::UI::ViewControllers, QolourSwitcherViewController);

void QolourSwitcherViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation)
        return;

    BSML::parse_and_construct(IncludedAssets::settings_bsml, this->get_transform(), this);
}
//oid MainViewCon