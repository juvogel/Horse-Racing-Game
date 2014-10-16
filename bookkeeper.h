//
//  bookkeeper.h
//

#ifndef BOOKKEEPER_H_EXISTS
#define BOOKKEEPER_H_EXISTS

#include <string>

class Bookkeeper {
private:
    struct Win{
        int betAmount;
        float oddsDec;
        //std::string oddsFrac;
    };
    float takeout;
    int horseNum;
    Win* odds;
public:
    Bookkeeper();
    Bookkeeper(int horseNum);
    ~Bookkeeper();
    void generateOdds();
    float getOdds(int index);
    void calculateOdds(int bets[]);
};

#endif /* defined(BOOKKEEPER_H_EXISTS) */