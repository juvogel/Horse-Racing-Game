//
//  main.cpp
//
//  ASCII art by Patrick Gillespie - patorjk.com
//

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "horse.h"
#include "race.h"
#include "player.h"

using namespace std;

int mainMenu();
void betMenu();
void title();
void goodbye();
void clearscr();

int main(){
    int numHorses;
    bool keepGoing = true;
    clearscr();
    cout << "Welcome to the Kentucky Derby!" << endl << endl << flush;          // welcome user to the Kentucky Derby!
    while (keepGoing) {
        keepGoing = false;
        cout << "How many horses will be racing today? ";                       // ask player for number of horses
        cin >> numHorses;
        cin.ignore();
        if (numHorses < 2) {
            cout << endl << "Please enter a number greater than 1..." << endl;
            keepGoing = true;
        }
    }
    Race kentuckyDerby (50, numHorses);                                         // create instance of race with length of 50 and user specified amount of horses
    keepGoing = true;
    while (keepGoing) {
        int response = mainMenu();
        clearscr();
        if (response == 1) {
            kentuckyDerby.printLineUp();
            cout << endl << "Press ENTER to go back to the menu." << flush;
            cin.ignore();
        } else if (response == 2) {
            //place your bets goes here
            kentuckyDerby.printLineUp();
            betMenu();
            cout << "Feature coming soon..." << endl;
            cout << endl << "Press ENTER to go back to the menu." << flush;
            cin.ignore();
        } else if (response == 3) {
            kentuckyDerby.start();
            cout << endl << "Press ENTER to exit." << flush;
            cin.ignore();
            keepGoing = false;
            goodbye();
        } else if (response == 0) {
            keepGoing = false;
            goodbye();
        } else {
            cout << "Sorry, what was that again?" << flush;
        }
    }// end while loop
}

int mainMenu(){
    int response;
    clearscr();
    title();
    cout << "1) Display Horse Line Up" << endl;
    cout << "2) Place Bets" << endl;
    cout << "3) Start the Race" << endl;
    cout << "0) Exit" << endl;
    cin >> response;
    cin.ignore();
    return response;
}

void betMenu(){
    cout << endl << endl;
    
}

void title(){
    ifstream inFile;
    inFile.open("kentuckyderby.txt");
    if (inFile.is_open()) {
        string line;
        cout << "\033[32m";
        while (!inFile.eof()){
            getline(inFile, line);
            cout << line << endl;
        }
        cout << "\033[0m";
        inFile.close();
    } else {
        cout << "Kentucky Derby" << endl;
    }
}

void goodbye(){
    clearscr();
    ifstream inFile;
    inFile.open("goodbye.txt");
    if (inFile.is_open()) {
        string line;
        cout << "\033[36m";
        while (!inFile.eof()){
            getline(inFile, line);
            cout << line << endl;
        }
        cout << "\033[0m";
        inFile.close();
    } else {
        cout << "Goodbye";
    }
    usleep(3*1000000);
    clearscr();
}

void clearscr(){
    cout << "\033[2J\033[;H";                                               // clears the screen
}