#include "plugin.h"

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    _plugin_registerformatfunction(pluginHandle, "ascii", [](char* dest, size_t destCount, int argc, char* argv[], duint value, void* userdata)
    {
        char string[MAX_STRING_SIZE / 2];
        if(!DbgMemRead(value, string, sizeof(string) - 2))
            return FORMAT_ERROR;
        if(strlen(string) >= destCount)
            return FORMAT_BUFFER_TOO_SMALL;
        strcpy_s(dest, destCount, string);
        return FORMAT_SUCCESS;
    }, nullptr);
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here.
void pluginStop()
{
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
