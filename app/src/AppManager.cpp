#include "AppManager.hpp"


/**
 * 初始化
 * 1.配置包含配置文件上（字体，界面风格，勾选数据等）
 * 2.数据管理
 */
AppManager::AppManager() {
    init();
}

int AppManager::init() {
     //配置
    confmanager = ConfigManager::create();

    //数据管理初始化
    datamanager = DataManager::create();

    // 托盘菜单栏
    tray = new Tray();
    tray->init();
}

void AppManager::Run() {
    // 启动

    // 将启动主界面加入线程管理（默认只启动主界面）

    // 数据获取模块加入线程管理

    // 线程管理启动

    // 启动菜单栏，进行循环控制
}

int AppManager::rigister_mainwin()
{
    //注册主窗口
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance_;
    wc.lpszClassName = L"TinyCPM";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hIcon = LoadIcon(hInstance_, MAKEINTRESOURCE(IDI_WINDOW2CLEAR));
}

// 创建系统托盘图标
void AppManager::CreateTrayIcon(HWND hwnd)
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

    swprintf_s(g_nid.szTip, sizeof(g_nid.szTip) / sizeof(wchar_t), L"Window2Clear %s - 窗口透明度控制", "V1.0.0");

    Shell_NotifyIcon(NIM_ADD, &g_nid);
}

// 主窗口过程
LRESULT CALLBACK AppManager::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_CREATE:
        break;

    case WM_HOTKEY:
        break;

    case WM_TRAYICON:
        if (lParam == WM_RBUTTONUP) {
            ShowContextMenu(hwnd);
        }
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_TRAY_SETTINGS:
            ShowSettingsWindow();
            break;
        case ID_TRAY_EXIT:
            PostQuitMessage(0);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}


void AppManager::ShowContextMenu(HWND hwnd) {
    HMENU hMenu = CreatePopupMenu();


    AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu, MF_STRING, ID_TRAY_SETTINGS, L"设置");
    AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu, MF_STRING, ID_TRAY_EXIT, L"退出");

    POINT pt;
    GetCursorPos(&pt);

    SetForegroundWindow(hwnd);
    TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hwnd, NULL);
    DestroyMenu(hMenu);
}

void AppManager::ShowSettingsWindow() {

}

AppManager::~AppManager() {
    // 释放资源
}