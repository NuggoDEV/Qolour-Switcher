#include "UI/ViewControllers/QolourSwitcherViewController.hpp"
using namespace QolourSwitcher::UI::ViewControllers;
using namespace QolourSwitcher::UI;


#include "ModConfig.hpp"
#include "bsml/shared/BSML.hpp"
#include "assets.hpp"

DEFINE_TYPE(QolourSwitcher::UI::ViewControllers, QolourSwitcherViewController);


void QolourSwitcherViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation)
        return;

    BSML::parse_and_construct(IncludedAssets::settings_bsml, this->get_transform(), this);

    std::function<std::string(float)> TimeFormatFunction = [](float value)
    {
        int minutes = value / 60;
        int seconds = value - minutes * 60;
        std::string minuteStr = std::to_string(minutes);
        std::string secondStr = std::to_string(seconds);
        if (minutes == 0)
            return secondStr + "s";
        else if (minutes > 0 && seconds == 0)
            return minuteStr + "m";
        else
            return minuteStr + "m : " + secondStr + "s"; 
    };
    TimeSlider1->formatter = TimeFormatFunction;
    TimeSlider2->formatter = TimeFormatFunction;
    TimeSlider3->formatter = TimeFormatFunction;
    TimeSlider4->formatter = TimeFormatFunction;
}