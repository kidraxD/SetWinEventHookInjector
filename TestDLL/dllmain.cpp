#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call != DLL_PROCESS_ATTACH)
		return true;

	MessageBoxA(NULL, "TestDLL.dll loaded!", "Info", MB_OK | MB_ICONINFORMATION);
	
	return true;
}

// WINEVENTPROC
extern "C" __declspec(dllexport) void WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD idEventThread, DWORD dwmsEventTime)
{
	return;
}