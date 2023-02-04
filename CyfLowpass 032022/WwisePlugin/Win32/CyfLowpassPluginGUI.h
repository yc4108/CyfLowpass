#pragma once

#include "../CyfLowpassPlugin.h"

class CyfLowpassPluginGUI final
	: public AK::Wwise::Plugin::PluginMFCWindows<>
	, public AK::Wwise::Plugin::GUIWindows
{
public:
	CyfLowpassPluginGUI();

};
