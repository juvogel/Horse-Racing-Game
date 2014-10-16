//
//  horse.cpp
//

#include "horse.h"
#include <cmath>
#include <random>

using namespace std;

Horse::Horse(){
    int position = 0;                                   // initialize position to 0
    int chance = 2;                                     // chance is 1:2
    string name = "Lucky Lad";                          // name is 'Lucky Lad'
}

void Horse::setChance(int chance){
    Horse::chance = chance;                             // set chance to parameter passed in
}

void Horse::advance(){
    random_device randomNum;                            // generate random number
    int advance = randomNum() % chance + 1;             // set advance to get a random number between 1 and the value at chance
    if (chance == advance){                             // if the number of possibilites is equal to advance, increase position by 1
        position++;
    }
}

int Horse::getPosition(){
    return Horse::position;                             // return the position of the horse
}

void Horse::setName(string name){
    Horse::name = name;                                 // set name to parameter passed in
}

string Horse::getName(){
    return Horse::name;                                 // return the name of the horse
}