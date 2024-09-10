#include "M.h"
#include <cmath>
#include <list>

M::M(int newX, int newY) : Moving(newX,newY){} //Moving's constructor,setters and getters

void M::setX(int x) {
    Moving::setX(x);
}

int M::getX() const {
    return Moving::getX();
}

void M::setY(int y) {
    Moving::setY(y);
}

int M::getY() const {
    return Moving::getY();
}

void M::moveUp() {
    Moving::moveUp();
}

void M::moveDown() {
    Moving::moveDown();
}

void M::moveRight() {
    Moving::moveRight();
}

void M::moveLeft() {
    Moving::moveLeft();
}


void M::move(vector<vector<char>> &maze, Stone &stone) {
    const char WALL='*';
    int numOfRows;
    int numOfCols;

    numOfRows=maze.size();
    numOfCols=maze[0].size();


    //stone's coordinates
    int sX=stone.getX();
    int sY=stone.getY();

    //The coordinates of Poteridis(M)
    int MX=getX();
    int MY=getY();

    //Χρησιμοποιούμε τον τύπο της απόστασης, ώστε να υπολογίσουμε
    // τη μικρότερη απόσταση μεταξύ πετραδιού και Μπάμπη Ποτερίδη
    //(η κίνηση του Μ δηλαδή είναι όσο πιο έξυπνη γίνεται).
    double min_distance;
    string direction;

    //Ευκλείδια μετρική -> https://www.wikiwand.com/el/%CE%95%CF%85%CE%BA%CE%BB%CE%B5%CE%AF%CE%B4%CE%B5%CE%B9%CE%B1_%CE%BC%CE%B5%CF%84%CF%81%CE%B9%CE%BA%CE%AE
    //Για τη συνάρτηση sqrt() και για την pow() χρειαζόμαστε τη βιβλιοθήκη cmath.
    min_distance=sqrt(pow((sX-MX),2)+pow((sY-MY),2));

    //Για να επιλέξουμε κατεύθυνση κίνησης, πρώτα ελέγχουμε το γεγονός εάν
    //πραγματοποιώντας την εκάστοτε κίνηση πέφτουμε πάνω σε κάποιο τοίχο ή
    //βγαίνουμε εκτός ορίων του λαβύρινθου.
    //Έπειτα, υπολογίζουμε 4 νέες αποστάσεις. Η κάθε απόσταση αντιστοιχεί
    //με κίνηση για κάθε από τις 4 κατευθύνσεις.
    double distance_up=sqrt(pow((sX-MX),2)+pow((sY-(MY-1)),2));
    double distance_down=sqrt(pow((sX-MX),2)+pow((sY-(MY+1)),2));
    double distance_right=sqrt(pow((sX-(MX+1)),2)+pow((sY-MY),2));
    double distance_left=sqrt(pow((sX-(MX-1)),2)+pow((sY-MY),2));

    //1)
    if((MY-1>0) && (maze[MY-1][MX]!=WALL)){
        if(distance_up<min_distance){
            min_distance=distance_up;
            direction="up";
        }
    }

    //2)
    if((MY+1<numOfRows) && (maze[MY+1][MX]!=WALL)){
        if(distance_down<min_distance){
            min_distance=distance_down;
            direction="down";
        }
    }


    //3)
    if((MX+1<numOfCols) && (maze[MY][MX+1]!=WALL)){
        if(distance_right<min_distance){
            min_distance=distance_right;
            direction="right";
        }
    }

    //4)
    if((MX-1>0) && (maze[MY][MX-1]!=WALL)){
        if(distance_left<min_distance){
            min_distance=distance_left;
            direction="left";
        }
    }

    //Ελέγχουμε την ύπαρξη ισοτήτων ανάμεσα στα distances, χρησιμοποιώντας μία λίστα
    list<double> distances_list;
    distances_list.push_back(distance_up);
    distances_list.push_back(distance_down);
    distances_list.push_back(distance_right);
    distances_list.push_back(distance_left);

    list<double>::iterator it1;
    list<double>::iterator it2;

    for(it1=distances_list.begin();it1!=distances_list.end();it1++) { //list traverse with 2 iterators
        for (it2 = next(it1); it2 != distances_list.end(); it2++) {
            if (*it1 != *it2) { //Δεν υπάρχει ισότητα μεταξύ κάποιων distances(κανονική λειτουργία)
                //Αφού δεν επιτρέπονται switch με string cases
                if (direction == "up") {
                    moveUp();
                } else if (direction == "down") {
                    moveDown();
                } else if (direction == "right") {
                    moveRight();
                } else if (direction == "left") {
                    moveLeft();
                } else {   //Ακινησία
                    setX(MX);
                    setY(MY);
                } //Στις ισοτητες:Επιλέγουμε καρφωτά κάποια κατεύθυνση(εναλλακτικά θα μπορούσσαν να χρησιμοποιηθούν τυχαίοι αριθμοί)
            } else { //Τετραπλη ισότητα
                if (distance_up == distance_down == distance_right == distance_left) {
                    moveUp();
                } //Τριπλη ισότητα
                else if (distance_up == distance_down == distance_right) {
                    moveDown();
                }else if (distance_up == distance_left == distance_right) {
                    moveUp();
                }else if (distance_up == distance_down == distance_left) {
                    moveRight();
                }else if (distance_right == distance_down == distance_left) {
                 moveLeft();
                }else if (distance_right == distance_down == distance_left) {
                    moveLeft();
                } //Απλή ισότητα
                else if (distance_up == distance_down) {
                    moveUp();
                }else if (distance_up == distance_right) {
                    moveRight();
                }else if (distance_up == distance_left) {
                    moveLeft();
                }else if (distance_right == distance_down) {
                    moveDown();
                }else if (distance_down == distance_left) {
                    moveLeft();
                }else if (distance_right == distance_left) {
                    moveRight();
                }
            }
        }
    }



}
