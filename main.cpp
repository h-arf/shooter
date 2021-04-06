#include <iostream>
#include "enemy.h"
#include "includes.h"
#include "screenobject.h"
#include <chrono>
#include <thread>
#include <random>
#include <algorithm>
#include "ncurses.h"
int nc(int COLS){
    long double d=COLS/6;
    return d;
}
int main(){
    initscr();      // start ncurses
    noecho();       // do not print input values
    cbreak();       // terminate ncurses on ctrl + c
    start_color();  // enable color
    int ncols=nc(COLS);
    std::string bar;
    int N=1;
    for (int i=0;i<ncols;i++){
        bar.push_back('|');
    }
    Enemy e;
    auto evars=e.XYLW();
    int x=0,y=0;
    WINDOW*enemy_window=newwin(evars[3],COLS,0,0);
    WINDOW*bar_window=newwin(1,COLS,LINES,0);
    bool dir=true;
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    wattron(enemy_window, COLOR_PAIR(2));
    int stren=std::rand();
    for (int i2=0;true;i2++){
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
        stren=(stren)|(i2+1)&(i2/2)%6;
        for (int count=0;count<ncols;count++){
            wattron(bar_window,COLOR_PAIR(N));
            mvwprintw(bar_window,0,count*ncols,bar.c_str());
            if (N==1){
                N=2;
            }else{
                N=1;
            }
        }
        attron(COLOR_PAIR(N));
        wrefresh(enemy_window);
        wrefresh(bar_window);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        wclear(enemy_window);
    }
    endwin();
}

