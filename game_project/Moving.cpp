#include "Moving.h"

Moving::Moving(int newX, int newY):x(newX),y(newY){}

void Moving::setX(int x) {
    this->x=x;
}

int Moving::getX() const {
    return x;
}

void Moving::setY(int y) {
    this->y=y;
}

int Moving::getY() const {
    return y;
}

void Moving::moveUp() {
    setY((getY()-1)); //Μία θέση προς τα πάνω(οι γραμμές αυξάνονται προς τα κάτω)
}

void Moving::moveDown() {
    setY((getY()+1));
}

void Moving::moveRight() {
    setX((getX()+1));
}

void Moving::moveLeft() {
    setX((getX()-1));
}



