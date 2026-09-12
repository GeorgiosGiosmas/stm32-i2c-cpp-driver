#include <cstring>
#include <cstdint>
#include "stm32_i2c_bus.hpp"
#include "/home/georgegio/stm32-i2c-cpp-driver/legacy/inc/stm32f4xx_hal_i2c.h"

using namespace std;

// I2C C++ Driver
class I2C_Driver_Cpp()
{
private:

public:
    // Constructor
    I2C_Driver_Cpp(){
        I2C_HandleTypeDef *i2c = { 0 };
    };

    // Init Driver
    ReturnStatus I2C_Driver_Cpp_Init(){
        if(HAL_I2C_Init(this->hi2c) != HAL_OK)
            return EXECUTION_FAILED;

        return EXECUTION_SUCCEEDED;
    }

    // Configure Driver
    ReturnStatus I2C_Driver_Cpp_Configure(I2C_HandleTypeDef *hi2c, I2C_TypeDef *Instance){
        hi2c->Instance = Instance;
        // ...
        hi2c->Init.ClockSpeed = 100000; // I don't know if i should hardcode or also use the I2C_HandleTypeDef *hi2c; as input to the function and not as a private variable.
        // ...

        return EXECUTION_SUCCEEDED;
    }

    // Transmit Data -> HAL_I2C_Master/Slaver_Transmit(...)


    // Receive Data -> HAL_I2C_Master/Slaver_Receive(...)


    // Error Handling -> ??? Will see if we can fir anything here


    // Deconstructor + Deinit Driver
    ~I2C_Driver_Cpp(){
        HAL_I2C_DeInit(hi2c);
    }
};
