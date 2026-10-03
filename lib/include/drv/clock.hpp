#pragma once
#include <cstdint>

class Clock{
public:
    virtual ~Clock() = default;
    virtual uint32_t now_ticks() const        = 0;
    virtual uint32_t ticks_per_second() const = 0;
};