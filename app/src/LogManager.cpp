#include "LogManager.hpp"

LogManager &LogManager::getInstance() {
    static LogManager instance;
    return instance;
}

void LogManager::info(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    dzlog_info(fmt, args);
    va_end(args);
}

void LogManager::error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    dzlog_error(fmt, args);
    va_end(args);
}

LogManager::LogManager() {
    // 1. 创建 logs 文件夹
    struct stat st;
    if (stat("./logs", &st) != 0) {
#ifdef _WIN32
        int ret = _mkdir("./logs");
#else
        int ret = mkdir("./logs", 0755);
#endif
        if (ret != 0) {
            std::cerr << "Failed to create directory: " << "./logs" << std::endl;
        }
    }

    // 2. 创建默认 zlog.conf
    std::ofstream conf("./zlog.conf");
    if (conf.is_open()) {
        conf << "[global]\n";
        conf << "buffer_min = 1024\n";
        conf << "rotate_lock_file = ./logs/zlog.lock\n\n";
        conf << "[formats]\n";
        conf << "simple = \"%d %m%n\"\n\n";
        conf << "[categories]\n";
        conf << "default = \"file; simple; ./logs/project.log\"\n";
        conf.close();
    } else {
        std::cerr << "Failed to create zlog.conf" << std::endl;
    }

    // 3. 初始化 dzlog
    int rc = zlog_init("zlog.conf");
    if (rc) {
        std::cerr << "dzlog init failed" << std::endl;
    }
}

LogManager::~LogManager() {
    zlog_fini();
}