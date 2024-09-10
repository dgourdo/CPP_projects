#ifndef ICE20390043_THEORYEXERCISE_L_H
#define ICE20390043_THEORYEXERCISE_L_H

#include "Moving.h"

class L: public Moving{
private:
    int x;
    int y;

public:
    L(int,int);

    void setX(int x) override;
    int getX() const override;
    void setY(int y) override;
    int getY() const override;

    void moveUp() override;
    void moveDown() override;
    void moveRight() override;
    void moveLeft() override;

    void move(vector<vector<char>> &);  //Δεν παίρνει το πετράδι ως όρισμα(αναφορά), σε αντίθεση με τον Ποτερίδη.
                                                //Ο χρήστης κινεί τον παίχτη προς το πετράδι, που είναι ο σκοπός του παιχνιδιού,
                                                // χρησιμοποιώντας τη λογική του και την εμπειρία του στα παιχνίδια.

};



#endif //ICE20390043_THEORYEXERCISE_L_H
