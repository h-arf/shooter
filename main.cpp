#include <iostream>
#include "enemy.h"
#include "includes.h"
#include <chrono>
#include <thread>
#include "ncurses.h"
int main(){
    initscr();      // start ncurses
    noecho();       // do not print input values
    cbreak();       // terminate ncurses on ctrl + c
    start_color();  // enable color
    Enemy e;
    string space{};
    auto evars=e.XYLW();
    int x=0,y=0;
    WINDOW*enemy_window=newwin(evars[3]+1,80,0,0);
    bool dir=true;
    for (;1;){
        if (dir){
            x+=1;
        }else{
            x-=1;
        }
        if (x>=50||x<=0){
            dir=!dir;
        }
        for (auto i:e.Disp()){
            mvwprintw(enemy_window,y,x,i.c_str());
            y++;
        }
        y=0;
        wrefresh(enemy_window);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        wclear(enemy_window);
    }
    endwin();
}

