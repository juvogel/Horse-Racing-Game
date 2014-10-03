//
//  main.cpp
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "horse.h"
#include "race.h"

using namespace std;

int main(){
    cout << "Welcome to the Kentucky Derby!" << flush << endl;          // welcome user to the Kentucky Derby!
    Race kentuckyDerby (25, 6);                                         // create instance of horse to length of 25, with 6 horses
    kentuckyDerby.start();                                              // start the race
}