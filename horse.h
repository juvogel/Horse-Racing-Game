//
//  horse.h
//

#ifndef HORSE_H_EXISTS
#define HORSE_H_EXISTS

#include <string>

class Horse {
private:
    int position;
    int chance;
    std::string name;
public:
    Horse();
    void setChance(int chance);
    void advance();
    int getPosition();
    void setName(std::string name);
    std::string getName();
};

#endif /* defined(HORSE_H_EXISTS) */