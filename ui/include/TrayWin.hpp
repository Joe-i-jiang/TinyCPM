#pragma once

class TrayWin {
public:
    static TrayWin& instance();

    static TrayWin &create(HWND hwn);
    static void destory();

private:
    TrayWin();
    ~TrayWin();
};


// 创建系统托盘图标
void CreateTrayIcon(HWND hwnd)
{
    ZeroMemory(&g_nid, sizeof(NOTIFYICONDATA));
    g_nid.cbSize = sizeof(NOTIFYICONDATA);
    g_nid.hWnd = hwnd;
    g_nid.uID = 1;
    g_nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    g_nid.uCallbackMessage = WM_TRAYICON;

    // 直接加载图标资源
    g_nid.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_WINDOW2CLEAR));
    if (!g_nid.hIcon) {
        // 如果无法加载自定义图标，使用默认应用程序图标
        g_nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    }

    swprintf_s(g_nid.szTip, sizeof(g_nid.szTip) / sizeof(wchar_t), L"Window2Clear %s - 窗口透明度控制", APP_VERSION);

    Shell_NotifyIcon(NIM_ADD, &g_nid);
}