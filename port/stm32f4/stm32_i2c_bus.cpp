#include "stm32_i2c_bus.hpp"

// I2C Bus Initialization
Stm32i2cBus::I2C_Driver_Cpp_Init(){
    extern "C"{
            if(HAL_I2C_Init(this->hi2c) != HAL_OK)
                return ReturnStatus::EXECUTION_FAILED;

            return ReturnStatus::EXECUTION_SUCCEEDED;
    }
}

// I2c bus Configuration
Stm32i2cBus::I2C_Driver_Cpp_Configure(I2C_HandleTypeDef& hi2c, I2C_TypeDef& Instance){
    hi2c.Instance = Instance;
    // ...
    hi2c.Init.ClockSpeed = 100000; // I don't know if i should hardcode or also use the I2C_HandleTypeDef *hi2c; as input to the function and not as a private variable.
    // ...

    return ReturnStatus::EXECUTION_SUCCEEDED;
}