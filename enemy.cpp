#include "enemy.h"
#include "includes.h"
vector<string> Enemy::Disp(){
vector<string> r={
        "    ^ ^    ",
        " <<  ^  >> ",
        "<  << >>  >",
    };
    return r;
}