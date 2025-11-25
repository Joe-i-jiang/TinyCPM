#pragma once
#include "ConfigManager.hpp"

class AppManager {
public:
    AppManager();
    ~AppManager();

    void Run();
    
private:
    ConfigManager confmanager;
};