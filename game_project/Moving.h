#ifndef ICE20390043_THEORYEXERCISE_MOVING_H
#define ICE20390043_THEORYEXERCISE_MOVING_H

#include <iostream>
#include <vector>

using namespace std ;

class M;
class L;

class Moving{ //abstract class
    protected:   //the coordinates
        int x;
        int y;

    public:
    Moving(int,int);

    virtual void setX(int x);

    virtual int getX() const;

    virtual void setY(int y);

    virtual int getY() const;

    virtual void moveUp();

    virtual void moveDown();

    virtual void moveRight();

    virtual void moveLeft();

    //2ος Τρόπος υλοποίησης(Οι μέθοδοι move των κλάσεων M, L, Stone
    //πρέπει να δέχονται μόνο το χάρτη ως παρ'αμετρο σε αυτή την περίπτωση).
    //virtual void move(vector<vector<char>> &)=0; //pure virtual method -> Polymorphism

};

#endif //ICE20390043_THEORYEXERCISE_MOVING_H
