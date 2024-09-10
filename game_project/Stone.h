#ifndef ICE20390043_THEORYEXERCISE_STONE_H
#define ICE20390043_THEORYEXERCISE_STONE_H

#include "Moving.h"
#include "M.h"
#include "L.h"

class M;

class Stone: public Moving {
private:
    int x;
    int y;

public:
    Stone(int, int);

    void setX(int x) override;

    int getX() const override;

    void setY(int y) override;

    int getY() const override;

    void move(vector<vector<char>> &, M &, L &);
};

#endif //ICE20390043_THEORYEXERCISE_STONE_H