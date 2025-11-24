#include <iostream>
#include <fstream>
#include <zlog.h>
#include <cstdarg>
#ifdef _WIN32
#include <direct.h> // _mkdir
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

// 宏方便调用
#define log_info(...)  do { LogManager::getInstance().info(__VA_ARGS__); } while(0)
#define log_error(...) do { LogManager::getInstance().error(__VA_ARGS__); } while(0)

class LogManager {
public:
    static LogManager& getInstance();

    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;

    void info(const char* fmt, ...);
    void error(const char* fmt, ...);

private:
    LogManager();
    ~LogManager();
};

