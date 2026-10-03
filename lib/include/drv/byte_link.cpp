#pragma once
#include "drv/status.hpp"

class ByteLink{
public:
    virtual ~ByteLink() = default;
    virtual void attach(ByteSink& sink) = 0;
    virtual Status start_receive()      = 0;
    virtual Status stop()               = 0;
    virtual const char* name() const    = 0;
};

