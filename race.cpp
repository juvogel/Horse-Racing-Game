//
//  race.cpp
//

#include "race.h"
#include "horse.h"
#include <iostream>
#include <random>

using namespace std;

Race::Race(){
    numOfHorses = 5;                            // initially set number of horses to 5
    h = new Horse[numOfHorses];                 // create new array of horse type
    random_device randomNum;                    // declare random number
    int chance = randomNum() % 10 + 1;          // set chance to random number between 1 and 10
    int i;
    for ( i = 0; i < numOfHorses; i++) {        // iterate through horse type array
        h[i].setChance(chance);                 // set chance in a horse to the random number generated
    }
    Race::length = 25;                          // initially set length to 25
}

Race::Race(int length){
    Race::length = length;                      // set length to integer passed through the parameter
}

Race::Race(int length, int numOfHorses){
    Race::length = length;                      // set length to integer passed through the first parameter
    delete[] h;                                 // delete initial horse type array
    h = new Horse[numOfHorses];                 // create another horse type array based on length parameter
    Race::numOfHorses = numOfHorses;            // number of horses based on numOfHorses parameter
    random_device randomNum;
    int i;
    for ( i = 0; i < numOfHorses; i++) {        // iterate through horse type array
        int chance = randomNum() % 10 + 1;      // generate random number between 1 and 10
        h[i].setChance(chance);                 // set chance in a horse to the random number generated
    }
}

Race::~Race(){
    delete[] h;                                 // delete horse type array, in other words garbage collection
}

void Race::printLane(int horseNum){
    int i;
    for (i = 0; i < length; i++) {              // print out horse lane for horse specified by "horseNum"
        if (i != h[horseNum].getPosition()){    // as long as i, the counter, does not equal the position of the horse, print a "."
            cout << ".";
        } else {                                // when the counter equals the position of the horse print out the number of the horse
            cout << horseNum;
        }
    }
    cout << endl;
}

void Race::start(){
    bool winner = false;
    while (winner == false) {                                   // while there is no winner run the race
        int i;
        for (i = 0; i < numOfHorses; i++) {                     // print lanes for each instance of horse
            h[i].advance();                                     // have each horse flip the coin to see if they advance
            if (h[i].getPosition() == Race::length) {           // if a horse has finished the race print "Horse 'whatever number' wins!"
                cout << "Horse " << i << " wins!" << endl;
                winner = true;                                  // sets winner to true
            } else {                                            // if the horse hasn't finished the race print out where they are
                printLane(i);
            }
        }
        cout << "Press ENTER for another turn:" << flush;       // tells user to press enter for another turn
        cin.ignore();
    }
}