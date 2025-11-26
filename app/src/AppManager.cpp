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
    confmanager = new ConfigManager();
    confmanager->init();

    //数据管理初始化
    datamanager = new DataManager();
    datamanager->init();
}

void AppManager::Run() {
    // 启动

    // 将启动主界面加入线程管理（默认只启动主界面）

    // 数据获取模块加入线程管理

    // 线程管理启动

    // 启动菜单栏，进行循环控制
}

AppManager::~AppManager() {
    // 释放资源
}