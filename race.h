//
//  race.h
//

#ifndef RACE_H_EXISTS
#define RACE_H_EXISTS

#include "horse.h"
#include "bookkeeper.h"
#include "player.h"

class Race {
    private:
        Horse* h;
        int length;
        int numOfHorses;
        Bookkeeper* bookie;
        Player* player;
    public:
        Race();
        Race(int length, int numOfHorses);
        ~Race();
        void printLane(int horseNum);
        void start();
        void printLineUp();
        void setLength(int length);
};

#endif /* defined(RACE_H_EXISTS) */