//
//  horse.h
//

#ifndef HORSE_H_EXISTS
#define HORSE_H_EXISTS

class Horse {
private:
    int position;
    int chance;
public:
    Horse();
    void setChance(int chance);
    void advance();
    int getPosition();
};

#endif /* defined(HORSE_H_EXISTS) */
