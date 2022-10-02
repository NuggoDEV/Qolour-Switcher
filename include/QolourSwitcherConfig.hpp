#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig, 
    CONFIG_VALUE(ModToggle, bool, "Disable Qolour Switcher", false);
    CONFIG_VALUE(ColoursChanged, bool, "", false);
    
    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(ModToggle);
        CONFIG_INIT_VALUE(ColoursChanged);
    )
)