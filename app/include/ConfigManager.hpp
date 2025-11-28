
/**
 * 配置管理器
 * 管理的是主线程控制的配置
 * 1.界面皮肤字体模块
 */
class ConfigManager {
public:
    static ConfigManager* create();
    static void destroy();

    // 禁用拷贝构造和赋值操作
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

public:
/**
 * 数据收集模块
 */

private:
    int init();
    ConfigManager();
    ~ConfigManager();
};