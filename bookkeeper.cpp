//
//  bookkeeper.cpp
//

#include <random>
#include <cmath>
#include "bookkeeper.h"

using namespace std;

Bookkeeper::Bookkeeper(){
    takeout = 0.16;                                                     // initializes track takeout to 16%
    horseNum = 5;                                                       // initializes number of horses to 5
    odds = new Win[horseNum];                                           // initializes new Win betting structure
    generateOdds();                                                     // generates odds for horses
}

Bookkeeper::Bookkeeper(int horseNum){
    takeout = 0.16;                                                     // initializes track takeout to 16%
    Bookkeeper::horseNum = horseNum;                                    // sets number of horses to inputted parameter
    odds = new Win[horseNum];                                           // initializes new Win betting structure
    generateOdds();                                                     // generates odds for horses
}

Bookkeeper::~Bookkeeper(){
    delete[] odds;                                                      // garbage collecting
}

void Bookkeeper::generateOdds(){
    int i;
    random_device randGen;
    int betSum = 0;
    for (i = 0; i < horseNum; i++) {                                    // calculate sum of all bets
        odds[i].betAmount = (randGen() % 50 + 1)*1000;                  // generate all bets for each horse
        betSum += odds[i].betAmount;
    }
    int payoutPool = (1.0 - takeout) * betSum;                          // track takeout
    float potWinnings[horseNum];
    for (i = 0; i < horseNum; i++) {                                    // subtract payout pool from bet amount for each horse
        potWinnings[i] = payoutPool - odds[i].betAmount;                // divide the difference from the bet amount to find amount to be split amongst winners
        potWinnings[i] = (potWinnings[i] / (float)odds[i].betAmount) * 10;
        odds[i].oddsDec = floor(potWinnings[i]) / 10;                   // result is rounded down to the nearest tenth
    }
}

float Bookkeeper::getOdds(int index){
    return odds[index].oddsDec;                                         // returns odds for particular horse
}

void Bookkeeper::calculateOdds(int bets[]){
    int i;
    int betSum = 0;
    for (i = 0; i < horseNum; i++) {                                    // calculate sum of all bets
        odds[i].betAmount += bets[i];                                   // generate all bets for each horse
        betSum += odds[i].betAmount;
    }
    int payoutPool = (1.0 - takeout) * betSum;                          // track takeout
    float potWinnings[horseNum];
    for (i = 0; i < horseNum; i++) {                                    // subtract payout pool from bet amount for each horse
        potWinnings[i] = payoutPool - odds[i].betAmount;                // divide the difference from the bet amount to find amount to be split amongst winners
        potWinnings[i] = (potWinnings[i] / (float)odds[i].betAmount) * 10;
        odds[i].oddsDec = floor(potWinnings[i]) / 10;                   // result is rounded down to the nearest tenth
    }
}