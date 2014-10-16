//
//  player.h
//

#ifndef PLAYER_H_EXISTS
#define PLAYER_H_EXISTS

#include <string>

class Player {
private:
    std::string name;
    int cash;
    int* bets;
public:
    Player();
    Player(int horseNum);
    ~Player();
    void setName(std::string name);
    std::string getName();
    void setCash(float cash);
    int getCash();
    void placeBet(float bet);
};

#endif /* defined(PLAYER_H_EXISTS) */