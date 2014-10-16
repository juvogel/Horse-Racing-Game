//
//  player.cpp
//

#include "player.h"
#include "race.h"
#include <string>

using namespace std;

Player::Player(){
    string name = "Anonymous";
    setCash(500.00);
    int* bets = new int[5];
}

Player::Player(int horseNum){
    string name = "Anonymous";
    setCash(500.00);
    int* bets = new int[horseNum];
}

Player::~Player(){
    delete[] bets;
}

void Player::setName(string name){
    Player::name = name;
}

string Player::getName(){
    return name;
}

void Player::setCash(float cash){
    Player::cash = int(cash * 100);
}

int Player::getCash(){
    return cash;
}