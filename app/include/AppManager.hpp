#pragma once
#include <windows.h>

#include "ConfigManager.hpp"
#include "DataManager.hpp"
#include "TrayWin.hpp"
#include "Common.hpp"
#include "resource.h"


/**
 * app管理
 * 管理其他窗口，菜单栏，同时也是程序核心窗口，主要是为了减少项目复杂度
 */
class AppManager {
public:
    AppManager();
    ~AppManager();

    void Run();

private:
    int init();

    int rigister_mainwin(); // 注册主窗口
    
private:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    static void ShowContextMenu(HWND);

    static void ShowSettingsWindow();

    void CreateTrayIcon(HWND hwnd);

private:
    WNDCLASS wc;
    HINSTANCE hInstance_;
    bool isRunning_;

private:
    ConfigManager *confmanager;
    DataManager *datamanager;

    HWND g_hMainWnd = NULL;           // 主窗口句柄
    HWND g_hSettingsWnd = NULL;       // 设置窗口句柄
    NOTIFYICONDATA g_nid = { 0 };     // 系统托盘图标数据
};