#ifdef _WIN32
#include <windows.h>
#endif
#include "LogManager.hpp"
#include "AppManager.hpp"

int main(int argc, char *argv[]) {
    log_info("启动......");

#ifdef _WIN32
    // 创建命名互斥量
    HANDLE hMutex = CreateMutex(NULL, TRUE, L"MyOverlayAppMutex");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        // 程序已经在运行，尝试激活窗口
        HWND hwnd = FindWindow(L"MyOverlayWindowClass", NULL);
        if (hwnd)
        {
            ShowWindow(hwnd, SW_RESTORE);     // 恢复窗口
            SetForegroundWindow(hwnd);        // 激活窗口
        }

        log_info("程序已经在运行！");
        return 0;  // 退出新启动实例
    }

    // ----- 主程序入口 -----
    // 创建 AppManager，启动线程、窗口和模块
    AppManager app;
    app.Run();

    // 程序退出前释放互斥量
    ReleaseMutex(hMutex);
    CloseHandle(hMutex);
#endif

    return 0;
}