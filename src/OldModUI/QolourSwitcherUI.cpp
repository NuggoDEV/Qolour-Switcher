#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "ModUI/QolourSwitcherUI.hpp"
using namespace QolourSwitcher;


#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Resources.hpp"
using namespace UnityEngine;
using namespace GlobalNamespace;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/MenuTransitionsHelper.hpp"

DEFINE_TYPE(QolourSwitcher, QolourSwitcherUI);

bool activated;
GameObject *leftContainer;

GameObject *time1;
GameObject *time2;
GameObject *time3;
GameObject *time4;
GameObject *time5;

void QolourSwitcherUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{

   auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
   auto playerData = playerDataModel->playerData;
   auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

   if (firstActivation)
   {
      GameObject *centreScreen = BeatSaberUI::CreateScrollView(get_transform());


      std::vector<StringW> positions  { "Top", "Left Side", "Right Side" };

      BeatSaberUI::CreateDropdown(centreScreen->get_transform(), "Colour Picker Position", getModConfig().ColourPickerLocation.GetValue(), positions, [&](std::string value)
      {
         getModConfig().ColourPickerLocation.SetValue(value);
      });


      BeatSaberUI::CreateColorPicker(centreScreen->get_transform(), "Left Saber Colour", colourScheme->get_saberAColor(), [colourScheme](Color colour)
      {
         colourScheme->saberAColor = colour;
      });

      BeatSaberUI::CreateColorPicker(centreScreen->get_transform(), "Right Saber Colour", colourScheme->get_saberBColor(), [colourScheme](Color colour)
      {
         colourScheme->saberBColor = colour;
      });

      BeatSaberUI::CreateColorPicker(centreScreen->get_transform(), "Bomb Colour", getModConfig().BombColour.GetValue(), [&](Color colour)
      {
         getModConfig().BombColour.SetValue(colour);
         getModConfig().ColoursChanged.SetValue(true);
      });
      
      BeatSaberUI::CreateColorPicker(centreScreen->get_transform(), "Wall Colour", colourScheme->get_obstaclesColor(), [colourScheme](Color colour)
      {
         colourScheme->obstaclesColor = colour;
         getModConfig().ColoursChanged.SetValue(true);
      });

      leftContainer = BeatSaberUI::CreateFloatingScreen(Vector2(50.0f, 60.0f), Vector3(-1.5f, 1.2f, 2.2f), Vector3(0.0f, -30.0f, 0.0f), 0.0f, true, false);
      leftContainer->SetActive(false);

      BeatSaberUI::CreateSliderSetting(centreScreen->get_transform(), "Amount of Timed Switches", 1, getModConfig().AmountOfTimedSwitches.GetValue(), 0, 5, [](int value) 
      {
         getModConfig().AmountOfTimedSwitches.SetValue(value);
         Resources::FindObjectsOfTypeAll<MenuTransitionsHelper *>()[0]->RestartGame(nullptr);
      });

      if (getModConfig().AmountOfTimedSwitches.GetValue() > 0)
      {
         leftContainer->SetActive(true);
         activated = true;
      }
      else if (getModConfig().AmountOfTimedSwitches.GetValue() == 1)
      {
         BeatSaberUI::CreateSliderSetting(centreScreen->get_transform(), "First Timed Switch", 1, 2, 0, 420, [](int value)
         {
            getModConfig().Time1.SetValue(value);
         });
      }
      else if (getModConfig().AmountOfTimedSwitches.GetValue() == 2)
      {
         BeatSaberUI::CreateSliderSetting(centreScreen->get_transform(), "Second Timed Switch", 1, 2, 0, 420, [](int value)
         {
            getModConfig().Time2.SetValue(value);
         });
      }

      else if (getModConfig().AmountOfTimedSwitches.GetValue() == 3)
      {
         BeatSaberUI::CreateSliderSetting(centreScreen->get_transform(), "Third Timed Switch", 1, 2, 0, 420, [](int value)
         {
            getModConfig().Time3.SetValue(value);
         });
      }

      else if (getModConfig().AmountOfTimedSwitches.GetValue() == 4)
      {
         BeatSaberUI::CreateSliderSetting(centreScreen->get_transform(), "Fourth Timed Switch", 1, 2, 0, 420, [](int value)
         {
            getModConfig().Time4.SetValue(value);
         });
      }

      else if (getModConfig().AmountOfTimedSwitches.GetValue() == 5)
      {
         BeatSaberUI::CreateSliderSetting(centreScreen->get_transform(), "Fifth Timed Switch", 1, 2, 0, 420, [](int value)
         {
            getModConfig().Time5.SetValue(value);
         });
      }

   }

   if (!activated)
      leftContainer->set_active(true);
      activated = true;
}

void QolourSwitcherUI::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling)
{
   leftContainer->set_active(false);
   activated = false;
}