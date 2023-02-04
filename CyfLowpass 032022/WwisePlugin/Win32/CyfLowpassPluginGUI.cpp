
#include "CyfLowpassPluginGUI.h"

CyfLowpassPluginGUI::CyfLowpassPluginGUI()
{
}

ADD_AUDIOPLUGIN_CLASS_TO_CONTAINER(
    CyfLowpass,            // Name of the plug-in container for this shared library
    CyfLowpassPluginGUI,   // Authoring plug-in class to add to the plug-in container
    CyfLowpassFX           // Corresponding Sound Engine plug-in class
);
