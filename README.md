# SetWinEventHookInjector

A small Windows proof-of-concept that demonstrates loading a DLL into another process using the `SetWinEventHook` API with `WINEVENT_INCONTEXT`.  
Includes:

- `TestDLL.dll` — a test DLL that shows a message box when loaded and exports a `WinEventProc`.
- `SetWinEventHookInjector.exe` — a simple injector program that finds a target window by class name and sets a WinEvent hook for the target process/thread using the supplied DLL.

> **Important:** This repository contains code that performs DLL injection. Use only on machines/systems you own or where you have explicit permission. Misuse (targeting systems you do not own or do not have permission to test) may be illegal and unethical. See the **Legal & Safety** section below.

---

### Legal & Safety

Do not use this code on computers you do not own or do not have explicit authorization to test. Unauthorized access, modification, or interference with computer systems is illegal in many jurisdictions.

This code is provided for educational and research purposes only. The repository owner accepts no responsibility for misuse.

If you are performing security testing, ensure you have written authorization (e.g., a signed rules-of-engagement or permission from the system owner).