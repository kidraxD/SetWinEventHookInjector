#include <Windows.h>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <Window Class Name> <DLL Path>\n", argv[0]);
		return 1;
	}

	std::string WindowClassName = argv[1];
	std::string DllPath = argv[2];
	
	HWND Window = FindWindowA(WindowClassName.c_str(), NULL);
	if (!Window)
	{
		printf("Error: Could not find window with class name '%s'.\n", WindowClassName.c_str());
		return 1;
	}

	DWORD ProcessId = 0;
	DWORD ThreadId = GetWindowThreadProcessId(Window, &ProcessId);
	if (!ProcessId || !ThreadId)
	{
		printf("Error: Could not get process ID from window handle.\n");
		return 1;
	}

	HMODULE Module = LoadLibraryExA(DllPath.c_str(), NULL, DONT_RESOLVE_DLL_REFERENCES);
	if (!Module)
	{
		printf("Error: Could not load DLL from path '%s'.\n", DllPath.c_str());
		return 1;
	}

	auto WinEventProc = (WINEVENTPROC)GetProcAddress(Module, "WinEventProc");
	if (!WinEventProc) {
		printf("Error: Could not find 'WinEventProc' in the DLL.\n");
		return 1;
	}

	HWINEVENTHOOK Hook = SetWinEventHook(EVENT_MIN, EVENT_MAX, Module, WinEventProc, ProcessId, ThreadId, WINEVENT_INCONTEXT);
	if (!Hook)
	{
		printf("Error: Could not set WinEvent hook.\n");
		return 1;
	}

	printf("Successfully set WinEvent hook. Press Enter to exit...\n");

	std::cin.get();

	UnhookWinEvent(Hook);
	printf("Hook removed. Exiting.\n");
	return 0;
}