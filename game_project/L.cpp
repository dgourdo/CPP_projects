#include "L.h"
#include <ncurses.h>

L::L(int newX, int newY) : Moving(newX,newY){} //Moving's constructor,setters and getters

void L::setX(int x) {
    Moving::setX(x);
}

int L::getX() const {
    return Moving::getX();
}

void L::setY(int y) {
    Moving::setY(y);
}

int L::getY() const {
    return Moving::getY();
}

void L::moveUp() {
    Moving::moveUp();
}

void L::moveDown() {
    Moving::moveDown();
}

void L::moveRight() {
    Moving::moveRight();
}

void L::moveLeft() {
    Moving::moveLeft();
}



void L::move(vector<vector<char>> &maze) {
    const char WALL='*';
    int numOfRows;
    int numOfCols;

    numOfRows=maze.size();
    numOfCols=maze[0].size();


    //Οι συντεταγμένες του Λουκά Μαλφόη
    int LX=getX();
    int LY=getY();

    int way;
    int c;

    //ncurses library
    //Κίνηση:Χρήση Cursor keys
    while (true) { // Έξοδος αν πατηθεί το πλήκτρο ESCAPE(Βρίσκεται στη συνάρτηση Play())

        c=getch(); //Η είσοδος του χρήστη
        way=c;

        if (c ==' ') { // Ακινησία του L αν ο χρήστης πατήσει SPACE(δεν υποστηρίζεται ως κουμπί από τη βιβλιοθήκη, σε αντίθεση με τα υπόλοιπα κουμπία)
            continue; //Ακινησία
        } else {

            switch (way) {
                case KEY_UP: //Για την κίνηση του Μαλφόη, ισχύουν οι κανόνες της κίνησης του Ποτερίδη
                    if ((LY - 1 > 0) && (maze[LY - 1][LX] != WALL)) {
                        moveUp();
                    }
                    break;

                case KEY_DOWN:
                    if((LY+1<numOfRows) && (maze[LY+1][LX]!=WALL)) {
                        moveDown();
                    }
                    break;

                case KEY_RIGHT:
                    if((LX+1<numOfCols) && (maze[LY][LX+1]!=WALL)) {
                        moveRight();
                    }
                    break;

                case KEY_LEFT:
                    if((LX-1>0) && (maze[LY][LX-1]!=WALL)) {
                        moveLeft();
                    }
                    break;

            }
        }
    }




}
