#ifndef ICE20390043_THEORYEXERCISE_M_H
#define ICE20390043_THEORYEXERCISE_M_H

#include "Moving.h"
#include "Stone.h"

class Stone;

class M: public Moving{ //Κληρονομικότητα
    private:
        int x;
        int y;

    public:
    M(int,int);

    void setX(int x) override;
    int getX() const override;
    void setY(int y) override;
    int getY() const override;

    void moveUp() override;
    void moveDown() override;
    void moveRight() override;
    void moveLeft() override;

    void move(vector<vector<char>> &, Stone &);


};



#endif //ICE20390043_THEORYEXERCISE_M_H
