#pragma once
#include "stdafx.h"
#include "Mecurus.h"

namespace Protect
{
	extern BOOL isDebugOnline;

	VOID STDCAL ProtectInit();
	VOID STDCAL ProcessProtectStart(INT ProtectLevel);
}