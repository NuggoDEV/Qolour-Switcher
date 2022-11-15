#include "beatsaber-hook/shared/config/rapidjson-utils.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"
#include "modloader/shared/modloader.hpp"

struct config_t
{
    bool toggleSwitch1 = true;
    bool toggleSwitch2 = true;
    bool toggleSwitch3 = true;
    bool toggleSwitch4 = true;
};


Configuration& getConfig();
void SaveConfig();
bool LoadConfig();