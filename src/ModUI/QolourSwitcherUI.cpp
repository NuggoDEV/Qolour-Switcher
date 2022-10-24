#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "ModUI/QolourSwitcherUI.hpp"
using namespace QolourSwitcher;


#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;
using namespace GlobalNamespace;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"


DEFINE_TYPE(QolourSwitcher, QolourSwitcherUI);

void QolourSwitcher::QolourSwitcherUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{

   auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
   auto playerData = playerDataModel->playerData;
   auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

   if (firstActivation)
   {
      GameObject *centreScreen = BeatSaberUI::CreateScrollView(get_transform());

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

      std::vector<StringW> positions  { "Top", "Left Side", "Right Side" };

      BeatSaberUI::CreateDropdown(centreScreen->get_transform(), "Colour Picker Position", getModConfig().ColourPickerLocation.GetValue(), positions, [&](std::string value)
      {
         getModConfig().ColourPickerLocation.SetValue(value);
      });
   }
}