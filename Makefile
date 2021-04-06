CXX=g++
CFLAGS=-std=c++17
LFLAGS=-lncurses
ALLDEPENDON=includes.h

default_target: all
.PHONY : default_target

all: shooter

debug: shooter_d

shooter: enemy.o main.o 
	$(CXX) $(CFLAGS) enemy.o main.o -o shooter $(LFLAGS)
enemy.o: enemy.h $(ALLDEPENDON) enemy.cpp
	$(CXX) $(CFLAGS) -c enemy.cpp
main.o: $(ALLDEPENDON) main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

shooter_d: enemy_d.o main_d.o 
	$(CXX) $(CFLAGS) -g enemy_d.o main_d.o -o shooter_d $(LFLAGS)
enemy_d.o: enemy.h $(ALLDEPENDON) enemy.cpp
	$(CXX) $(CFLAGS) -g -c enemy.cpp -o enemy_d.o
main_d.o: $(ALLDEPENDON) main.cpp
	$(CXX) $(CFLAGS) -g -c main.cpp -o main_d.o
