#include "SysData.hpp"

SysData& SysData::Instance() {
    static SysData instance;
    return instance;
}

// ---------------- 写入 ----------------
void SysData::setCpuUsageRate(double data) {
    std::lock_guard<std::mutex> lock(mtx);
    CPU_usage_rate = data;
}

void SysData::setCpuPower(double data) {
    std::lock_guard<std::mutex> lock(mtx);
    CPU_power = data;
}

void SysData::setCpuTemperature(double data) {
    std::lock_guard<std::mutex> lock(mtx);
    CPU_temperature = data;
}

void SysData::setCpuVoltage(double data) {
    std::lock_guard<std::mutex> lock(mtx);
    CPU_voltage = data;
}

void SysData::setMemery(double used, double total) {
    std::lock_guard<std::mutex> lock(mtx);
    used_mem = used;
    total_mem = total;
    free_mem = total - used;
}

void SysData::setNetworkSpeed(double upload, double download) {
    std::lock_guard<std::mutex> lock(mtx);
    upload_speed = upload;
    download_speed = download;
}

// ---------------- 读取 ----------------
double SysData::getCpuUsageRate() {
    std::lock_guard<std::mutex> lock(mtx);
    return CPU_usage_rate;
}

double SysData::getCpuPower() {
    std::lock_guard<std::mutex> lock(mtx);
    return CPU_power;
}

double SysData::getCpuTemperature() {
    std::lock_guard<std::mutex> lock(mtx);
    return CPU_temperature;
}

double SysData::getCpuVoltage() {
    std::lock_guard<std::mutex> lock(mtx);
    return CPU_voltage;
}

double SysData::getUsedMem() {
    std::lock_guard<std::mutex> lock(mtx);
    return used_mem;
}

double SysData::getFreeMem() {
    std::lock_guard<std::mutex> lock(mtx);
    return free_mem;
}

double SysData::getTotalMem() {
    std::lock_guard<std::mutex> lock(mtx);
    return total_mem;
}

double SysData::getUploadSpeed() {
    std::lock_guard<std::mutex> lock(mtx);
    return upload_speed;
}

double SysData::getDownloadSpeed() {
    std::lock_guard<std::mutex> lock(mtx);
    return download_speed;
}
