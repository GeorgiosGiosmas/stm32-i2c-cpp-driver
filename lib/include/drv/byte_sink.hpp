#pragma once
#include <cstdint>
#include "drv/status.hpp"

class ByteSink{
public:
    virtual ~ByteSink() = default;
    virtual void on_byte(uint8_t b) = 0;
    virtual void on_error(Status s) = 0;
};

