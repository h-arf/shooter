#include "includes.h"
class ScreenObject
{
public:
    ScreenObject(/* args */);
    ~ScreenObject();
    virtual std::vector<std::string> Disp();
    virtual std::vector<int> XYLW();
};
