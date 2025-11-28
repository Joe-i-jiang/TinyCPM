#include "BaseModule.hpp"

class CpuModule : public BaseModule {
public:
    CpuModule();
    ~CpuModule();

    int Init() override;
    int Update() override;
    int Render() override;
    int Shutdown() override;

private:
    double CPU_usage_rate = 0.0f;
    double CPU_power = 0.0f;
    double CPU_temperature = 0.0f;
    double CPU_voltage = 0.0f;
};