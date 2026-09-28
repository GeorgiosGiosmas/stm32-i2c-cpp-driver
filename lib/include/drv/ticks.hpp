#include <cstdint>

#pragma once

constexpr uint32_t elapsed_ticks(uint32_t start, uint32_t end)
{
    return end - start;
}