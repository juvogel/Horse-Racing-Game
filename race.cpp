//
//  race.cpp
//

#include "race.h"
#include "horse.h"
#include "bookkeeper.h"
#include "player.h"
#include <iostream>
#include <random>
#include <unistd.h>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

Race::Race(){
    numOfHorses = 5;                                        // initially set number of horses to 5
    h = new Horse[numOfHorses];                             // create new array of horse type
    random_device randomGen;                                // declare random number
    // set name to random name in file
    ifstream nameFile;
    nameFile.open("horses.dat");                            // opens file containing horse names
    string names;
    vector<string> listNames;                               // creates new vector for names of the horses
    while (!nameFile.eof()){                                // while not at the end of the file
        getline(nameFile, names, ',');                      // read each value between the commas
        listNames.push_back(names);                         // add the name to the vector
    }
    nameFile.close();                                       // close the file
    int i;
    for ( i = 0; i < numOfHorses; i++) {                    // iterate through horse type array
        int chance = randomGen() % 3 + 2;                   // set chance to random number between 2 and 4
        h[i].setChance(chance);                             // set chance in a horse to the random number generated
        int randomNum = randomGen() % listNames.size();     // generate number between 1 and amount of possible names
        h[i].setName(listNames[randomNum]);                 // assign horse name to random name chosen
        cout << i;
    }
    Race::length = 25;                                      // initially set length to 25
    bookie = new Bookkeeper (numOfHorses);                  // intialize bookkeeper class
    player = new Player (numOfHorses);
}

Race::Race(int length, int numOfHorses){
    Race::length = length;                                  // set length to integer passed through the first parameter
    h = new Horse[numOfHorses];                             // create another horse type array based on length parameter
    Race::numOfHorses = numOfHorses;                        // number of horses based on numOfHorses parameter
    random_device randomGen;                                // declare random number
    // set name to random name in file
    ifstream nameFile;
    nameFile.open("horses.dat");                            // opens file containing horse names
    string names;
    vector<string> listNames;                               // creates new vector for names of the horses
    while (!nameFile.eof()){                                // while not at the end of the file
        getline(nameFile, names, ',');                      // read each value between the commas
        listNames.push_back(names);                         // add the name to the vector
    }
    nameFile.close();                                       // close the file
    int i;
    for ( i = 0; i < Race::numOfHorses; i++) {              // iterate through horse type array
        int chance = randomGen() % 3 + 2;                   // set chance to random number between 2 and 4
        h[i].setChance(chance);                             // set chance in a horse to the random number generated
        int randomNum = randomGen() % listNames.size();     // generate number between 1 and amount of possible names
        string name = listNames[randomNum];
        h[i].setName(name);                                 // assign horse name to random name chosen
    }
    bookie = new Bookkeeper (numOfHorses);                  // intialize bookkeeper class
    player = new Player (numOfHorses);
}

Race::~Race(){
    delete[] h;                                 // delete horse type array, in other words garbage collection
    delete bookie;
}

void Race::setLength(int length){
    Race::length = length;                      // set length to integer passed through the parameter
}

void Race::printLane(int horseNum){
    int i;
    for (i = 0; i < length; i++) {              // print out horse lane for horse specified by "horseNum"
        if (i != h[horseNum].getPosition()){    // as long as i, the counter, does not equal the position of the horse, print a "."
            cout << ".";
        } else {                                // when the counter equals the position of the horse print out the number of the horse
            cout << horseNum + 1;
        }
    }
    cout << endl;
}

void Race::printLineUp(){
    cout << "\033[1m" << left << setw(6) << "Post" << setw(30) << "Horse" << setw(5) << "Odds" << "\033[0m" << endl;    // prints out headers of table
    int i;
    for (i = 0; i < numOfHorses; i++) {                                                                                 // iterate through horses
        cout << left << setw(6) << i + 1 << setw(30) << h[i].getName() << setw(5) << bookie->getOdds(i) << endl;        // print out horse number, name, and odds
    }
    cout << endl;
}

void Race::start(){
    bool winner = false;
    while (winner == false) {                                   // while there is no winner run the race
        int i;
        cout << "\033[2J\033[;H";
        for (i = 0; i < numOfHorses; i++) {                     // print lanes for each instance of horse
            h[i].advance();                                     // have each horse flip the coin to see if they advance
            if (h[i].getPosition() == Race::length) {           // if a horse has finished the race print "Horse 'whatever number' wins!"
                cout << h[i].getName() << " wins!" << endl;
                winner = true;                                  // sets winner to true
            } else {                                            // if the horse hasn't finished the race print out where they are
                printLane(i);
            }
        }
        cout << endl;
        usleep(150000);                                         // pauses the next track update by .3 seconds
    }
}