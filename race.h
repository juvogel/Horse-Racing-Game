//
//  race.h
//

#ifndef RACE_H_EXISTS
#define RACE_H_EXISTS

#include "horse.h"

class Race {
    private:
        Horse* h;
        int length;
        int numOfHorses;
    public:
        Race();
        Race(int length);
        Race(int length, int numOfHorses);
        ~Race();
        void printLane(int horseNum);
        void start();
        int checkTie();
};

#endif /* defined(RACE_H_EXISTS) */
