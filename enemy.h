#pragma once
#include "includes.h"
class Enemy{
private:
    int x;
    static const int l={7};
    static const int w={3};
    bool shooting={false};
public:
    std::vector<std::string> Disp();
    Enemy(){}
     std::vector<int> XYLW() {return {x,0,7,3};};
};