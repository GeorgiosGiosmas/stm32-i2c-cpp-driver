#include <cstring>
#include <cstdint>
#include "/home/georgegio/stm32-i2c-cpp-driver/legacy/inc/stm32f4xx_hal_i2c.h"

enum Class ReturnStatus: uint8_t{
    EXECUTION_SUCCEEDED,
    EXECUTION_FAILED
};

// I2C C++ Driver
class Stm32i2cBus()
{
private:
    mutable std::mutex mtx;
public:
    // Constructor
    I2C_Driver_Cpp(){
        I2C_HandleTypeDef *i2c = { 0 };
    };

    // Init Driver
    ReturnStatus I2C_Driver_Cpp_Init(){}

    // Configure Driver
    ReturnStatus I2C_Driver_Cpp_Configure(I2C_HandleTypeDef& hi2c, I2C_TypeDef& Instance){}

    // Transmit Data -> HAL_I2C_Master/Slaver_Transmit(...)


    // Receive Data -> HAL_I2C_Master/Slaver_Receive(...)


    // Error Handling -> ??? Will see if we can fir anything here


    // Deconstructor + Deinit Driver
    ~I2C_Driver_Cpp(){
        extern "C"{
            HAL_I2C_DeInit(hi2c);
        }
    }
};
