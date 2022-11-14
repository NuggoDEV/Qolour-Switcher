#pragma once

#include "config-utils/shared/config-utils.hpp"
#include "bsml/shared/macros.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig, 

    DECLARE_BSML_PROPERTY(Color, LeftSaberColour);

)