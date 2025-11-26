#pragma once
#include "ConfigManager.hpp"
#include "DataManager.hpp"
#include "Tray.hpp"

class AppManager {
public:
    AppManager();
    ~AppManager();

    void Run();

private:
    int init();
    
private:
    ConfigManager *confmanager;
    DataManager *datamanager;

    Tray *tray;
};