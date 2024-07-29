#pragma once
#include "Includes.h"

namespace Bypass
{
	enum BypassStatus : int {
		FAILED_LOADINGVULN,
		FAILED_DISABLEPG,
		FAILED_DISABLEDSE,
		FAILED_LOADINGCHEATDRV,
		SUCCESS,
	};

	static char SeValidateImageDataOG[8]	= { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
	static char SeValidateImageHeaderOG[8]  = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

	static ULONG64 SeValidateImageDataOffset;
	static ULONG64 SeValidateImageHeaderOffset;
	static ULONG64 RetOffset;
	static ULONG64 NtoskrnlBaseAddress;
	static ULONG64 PatchgaurdValueOffset;
	static ULONG64 PatchgaurdOffset;
	static HANDLE  VulnurableDriverHandle;

	bool Init();

  // Use my PG Exploit or use EfiGuard
	// bool DisableDSE();
	// bool DisablePG();

	bool LoadVulnurableDriver();

	BypassStatus LoadCheatDriver();
	std::string BypassStatusToString(BypassStatus Status);
}
