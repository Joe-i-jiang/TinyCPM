#pragma once
#include "SysData.hpp"

/**
 * 哪些是可用的
 */
typedef struct {
    bool uCPU_usage_rate = false;
    bool uCPU_power = false;
    bool uCPU_temperature = false;
    bool uCPU_voltage = false;

    bool uused_mem = false;
    bool ufree_mem = false;
    bool utotal_mem = false;

    bool uupload_speed = false;
    bool udownload_speed = false;
} UsedData;


/**
 * DataManager
 * 负责整个数据模块的控制，以及基础数据的控制
 */
class DataManager {
public:
    DataManager();
    ~DataManager();

    int init();
private:

};

