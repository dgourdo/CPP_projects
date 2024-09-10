#include <unistd.h>
#include "Stone.h"

Stone::Stone(int newX, int newY) : Moving(newX,newY){} //Moving's constructor,setters and getters

void Stone::setX(int x) {
    Moving::setX(x);
}

int Stone::getX() const {
    return Moving::getX();
}

void Stone::setY(int y) {
    Moving::setY(y);
}

int Stone::getY() const {
    return Moving::getY();
}



void Stone::move(vector<vector<char>> &maze, M &M, L &L) {
    const char WALL='*';
    int numOfRows;
    int numOfCols;

    numOfRows=maze.size();
    numOfCols=maze[0].size();

    //Οι συντεταγμένες του Μπάμπη Ποτερίδη
    int MX=M.getX();
    int MY=M.getY();

    //Οι συντεταγμένες του Λουκά Μαλφόη
    int LX=L.getX();
    int LY=L.getY();

    //ΤΥΧΑΙΑ ΧΡΟΝΙΚΑ ΔΙΑΣΤΗΜΑΤΑ ΜΕΤΑΚΙΝΗΣΗΣ ΤΟΥ ΠΕΤΡΑΔΙΟΥ ΣΕ ΝΕΑ ΘΕΣΗ
    //Αρχικοποίηση της γεννήτριας τυχαίων αριθμών με την τρέχουσα ώρα
    srand(static_cast<unsigned int>(time(nullptr)));   //https://www.softwaretestinghelp.com/random-number-generator-cpp/

    while(true){
        int new_sX=rand() % numOfCols;
        int new_sY=rand() % numOfRows;

        if(((maze[new_sX][new_sY] != WALL) && (new_sX != MX || new_sY != MY) && (LX != new_sX ||LY != new_sY))) { //περιορισμοί αλλαγής θέσης
            setX(new_sX);
            setY(new_sY);

            int sleep_time=10 + rand() % 6; //Τυχαίος αριθμός στο εύρος 10-15 δευτερολέπτων(τυχαίο χρονικό διάστημα,
            //τέτοιο όμως ώστε να μην είναι εύκολο το παιχνίδι, αλλά ούτε και δύσκολο)
            sleep(sleep_time);  //Ανά 10-15 δευτερόλεπτα -> ΑΛΛΑΓΗ ΘΕΣΗΣ ΓΙΑ ΤΟ ΠΕΤΡΑΔΙ
        }

    }


}