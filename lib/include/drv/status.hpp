#pragma once
#include <cstdint>

enum class Status: uint8_t
{
    Ok = 0,
    BusError,
    Timeout,
    NotReady,
    Overrun
};

