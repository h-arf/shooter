#pragma once
#include "includes.h"
class ScreenObject//do not dervive from here just a protocol(for now)
{
public:
    virtual std::vector<std::string> Disp();
    virtual std::vector<int> XYLW();
};
