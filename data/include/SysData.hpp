#pragma once
#include <mutex>

class SysData {
public:
    static SysData& Instance();

    // ---- 写入接口（采集线程用） ----
    void setCpuUsageRate(double);
    void setCpuPower(double);
    void setCpuTemperature(double);
    void setCpuVoltage(double);

    void setMemery(double, double);

    void setNetworkSpeed(double, double);

    // ---- 读取接口（界面线程用） ----
    double getCpuUsageRate();
    double getCpuPower();
    double getCpuTemperature();
    double getCpuVoltage();

    double getUsedMem();
    double getFreeMem();
    double getTotalMem();

    double getUploadSpeed();
    double getDownloadSpeed();

private:
    SysData() = default;
    ~SysData() = default;

    SysData(const SysData&) = delete;
    SysData& operator=(const SysData&) = delete;

private:
/**
 * CPU数据
 */
    double CPU_usage_rate = 0.0f;
    double CPU_power = 0.0f;
    double CPU_temperature = 0.0f;
    double CPU_voltage = 0.0f;

/**
 * 内存数据
 */
    double used_mem = 0.0f;
    double free_mem = 0.0f;
    double total_mem = 0.0f;

/**
 * 网速
 */
    double upload_speed = 0.0f;
    double download_speed = 0.0f;

    // 全局锁
    std::mutex mtx;
};

// ---- 写入接口（采集线程用） ----
#define _setCpuUsageRate(data) do { SystemData::Instance().setCpuUsageRate(data); } while(0)
#define _setCpuPower(data) do { SystemData::Instance().setCpuPower(data); } while(0)
#define _setCpuTemperature(data) do { SystemData::Instance().setCpuTemperature(data); } while(0)
#define _setCpuVoltage(data) do { SystemData::Instance().setCpuVoltage(data); } while(0)

#define _setMemery(data1, data2) do { SystemData::Instance().setMemery(data1, data2); } while(0)

#define _setNetworkSpeed(data1, data2) do { SystemData::Instance().setNetworkSpeed(data1, data2); } while(0)

// ---- 读取接口（界面线程用） ----
#define _getCpuUsageRate() SystemData::Instance().getCpuUsageRate()
#define _getCpuPower() SystemData::Instance().getCpuPower()
#define _getCpuTemperature() SystemData::Instance().getCpuTemperature()
#define _getCpuVoltage() SystemData::Instance().getCpuVoltage()

#define _getUsedMem() SystemData::Instance().getUsedMem()
#define _getFreeMem() SystemData::Instance().getFreeMem()
#define _getTotalMem() SystemData::Instance().getTotalMem()

#define _getUploadSpeed() SystemData::Instance().getUploadSpeed()
#define _getDownloadSpeed() SystemData::Instance().getDownloadSpeed()