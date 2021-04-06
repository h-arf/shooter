#include "screenobject.h"
class Enemy{
private:
    int x;
    int y;
    static const int l={7};
    static const int w={3};
public:
    std::vector<std::string> Disp();
    Enemy(){}
    std::vector<int> XYLW(){return {0,0,7,3};}
};