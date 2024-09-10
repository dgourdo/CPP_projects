#include "Engine.h"

Engine::Engine(){}

vector<vector<char>> Engine::LoadMazeFromFile(const string& file_name) {
    ifstream file(file_name); //χρησιμοποιούμε το αρχείο αποκλειστικά για ανάγνωση
    vector<vector<char>> maze;
    string line;
    vector<char> row;

    if(file.is_open()){
            //Διαβάζουμε τις γραμμές του λαβύρινθου
            while(getline(file, line)){
             for (char c: line) { //for-each in Java-style
                if (c != '*' && c != '.' && c!='\n') {//Στο αρχείο πρέπει να υπάρχουν μόνο οι χαρακτήρες '*' και '.'
                    throw runtime_error("Οι χαρακτήρες από τους οποίους αποτελείται ο λαβύρινθος είναι οι εξής:'*' και '.'");
                }
                row.push_back(c);//προσθέτουμε κάθε χαρακτήρα στον vector<char> row
            }
            maze.push_back(row);//προσθέτουμε κάθε row στον vector<vector<char>> maze
            row.clear();

        }
            file.close();
            //Ελέγχουμε αν η περίμετρος του λαβύρινθου είναι τοίχος
            //(δηλαδή πρέπει η πρώτη και η τελευταία γραμμή, αλλά και η πρώτη και η τελευταία στήλη
            // να αποτελούνται μόνο από το χαρακτήρα '*').

            //Χρήση γενικών μεθόδων της STL -> Θεωρία(Ενότητα 8)
            //1) Έλεγχος πρώτης γραμμής
            for (char c: maze.front()) {
                if (c != '*' && c !='\n') {  //Σε όλους τους ελέγχους λαμβάνουμε υπ'όψιν μας και το χαρακτήρα αλλαγής γραμμής, που εννοείται πως υπάρχει στο αρχείο.
                    throw runtime_error("Η περίμετρος του λαβύρινθου πρέπει να αποτελείται από τοίχο.");
                }
            }

            //2) Έλεγχος τελευταίας γραμμής
            for (char c: maze.back()) {
                if (c != '*' && c !='\n') {
                    throw runtime_error("Η περίμετρος του λαβύρινθου πρέπει να αποτελείται από τοίχο.");
                }
            }

            //3),4) Έλεγχος πρώτης και τελευταίας στήλης
            //χρήση για iterator διάσχιση
            vector<vector<char>>::iterator row_it;
            for (row_it = maze.begin(); row_it != maze.end(); row_it++) {
                if ((row_it->front() != '*') || (row_it->back() != '*')) {
                    throw runtime_error("Η περίμετρος του λαβύρινθου πρέπει να αποτελείται από τοίχο.");
                }
            }

    }else {
        throw runtime_error("Αδυναμία φόρτωσης του αρχείου:" +file_name);
    }

    return maze;
}

void Engine::RandomStartingPositions(vector<vector<char>>& maze,M& M, L& L, Stone& stone) {

    const char WALL='*';
    int numOfCols=0;

    if(!maze.empty()){
        numOfCols=maze[0].size();
    }

    int numOfRows = maze.size();

    srand(0); //τυχαιότητα

    // Τυχαία αρχική θέση του Ποτερίδη(M)
    do {
        if(numOfCols>0){
        M.setX(rand() % numOfCols);
    }

        if(numOfCols>0){
         M.setY(rand() % numOfRows);
    }
    }while(maze[M.getY()][M.getX()]==WALL);

    // Τυχαία αρχική θέση του Μαλφόη(L)
    do {
        L.setX(rand() % numOfCols);
        L.setY(rand() % numOfRows);
    }while((maze[L.getY()][L.getX()]==WALL) || ((L.getX()==M.getX()) && (L.getY()==M.getY())));

    // Τυχαία αρχική θέση του πετραδιού(stone)
    do {
        stone.setX(rand() % numOfCols);
        stone.setY(rand() % numOfRows);
    }while((maze[stone.getY()][stone.getX()]==WALL) || ((stone.getX()==M.getX()) && (stone.getY()==M.getY())) || ((stone.getX()==L.getX()) && (stone.getY()==L.getY())));



}

void Engine::PrintMaze(const vector<vector<char>>& maze, const M& M, const L& L, const Stone& stone) {

    //Πηγές που βοήθησαν στην κατανόηση της βιβλιοθήκης ncurces:
    //https://invisible-island.net/ncurses/ncurses-intro.html
    //https://jbwyatt.com/ncurses.html
    //https://dev.to/tbhaxor/windows-in-ncurses-part-3-2e4

    //Η αρχικοποίηση της βιβλιοθήκης ncurces, οι απαραίτηες εντολές που πρέπει να εκτελέσουμε για να λειτουργήσει
    //αλλά και η κατάργηση της βρίσκονται στη συνάρτηση Play, στην οποία καλείται η PrintMaze.

    int i,j;

    for(i=0;i<maze.size();i++){
        for(j=0;j<maze[i].size();j++){
            char c=maze[i][j];
            //Πρώτα καλείται η RandomStartingPositions στη main, οπότε ακολουθούμε τους σχετικούς περιορισμούς
            if(i==M.getY() && j==M.getX()){
                attron(COLOR_PAIR(2)); //Ενεργοποίηση κόκκινου χρώματος για τον Ποτερίδη
                mvprintw(i,j,"%c",'M'); //Εκτύπωση του χαρακτήρα 'Μ' στη συγκεκριμένη θέση, με το κατάλληλο χρώμα
                attroff(COLOR_PAIR(2)); //Ενεργοποίηση κόκκινου χρώματος
            }if(i==L.getY() && j==L.getX()){
                attron(COLOR_PAIR(3));
                mvprintw(i,j,"%c",'L');
                attroff(COLOR_PAIR(3));
            }if(i==stone.getY() && j==stone.getX()){
                attron(COLOR_PAIR(1));
                mvprintw(i,j,"%c",'s');
                attroff(COLOR_PAIR(1));
            }else{
                mvprintw(i,j,"%c",c); //Εκτύπωση του υπόλοιπου λαβύρινθου
            }
        }
}

    refresh(); //Ανανέωση της οθόνης
    getch(); //Αναμονή για είσοδο του χρήστη μέσω του πληκτρολογίου


}

void Engine::MoveStudents(vector<vector<char>>& maze,M &M, L &L,Stone &stone) {
    L.move(maze);
    M.move(maze,stone);

}

void Engine::MoveStone(Stone& stone,vector<vector<char>> &maze, M &M, L &L) {
    stone.move(maze,M,L);
}


void Engine::Play(vector<vector<char>> &maze,M &M,L&L,Stone &stone) {

        // Αρχικοποίηση της βιβλιοθήκης ncurses
        initscr();

        //Απαραίτητες εντολές για τη λειτουργία της ncurses
        noecho();
        cbreak();
        curs_set(0);
        keypad(stdscr, true);

        start_color();

        init_pair(1,COLOR_BLUE,COLOR_BLACK); //Χρώμα πετραδιού(επιλέχθηκε τυχαία)
        init_pair(2,COLOR_RED,COLOR_BLACK); //Χρώμα Ποτερίδη(βάσει της εκφώνησης)
        init_pair(3,COLOR_GREEN,COLOR_BLACK); //Χρώμα Μαλφόη(βάσει της εκφώνησης)
        init_pair(4,COLOR_CYAN,COLOR_BLACK); //χρώμα εκτυπώσεων αποτελεσμάτων

        int round = 0;
        char c;
        int Poteridis_wins=0;
        int Malfois_wins=0;

        while ((c=getch())!=27){ //Μέχρι να πατήσει ESCAPE ο χρήστης(για να τερματίσει το πρόγραμμα)
            clear(); //καθαρισμός της οθόνης

            printw("Round %d\n !",++round);

            RandomStartingPositions(maze,M,L,stone); //κλήση συνάρτησης
            PrintMaze(maze,M,L,stone); //κλήση συνάρτησης

            while (!((stone.getX() == M.getX() && stone.getY() == M.getY()) ||(stone.getX() == L.getX() && stone.getY() == L.getY()))) { //until someone wins

                MoveStudents(maze,M,L,stone); //κλήση συνάρτησης
                MoveStone(stone,maze,M,L) ; //κλήση συνάρτησης

                if ((stone.getX() == M.getX() && stone.getY() == M.getY())) {
                    printw("Ο Μπάμπης Ποτερίδης κέρδισε το γύρο %d.\n",round);
                    Poteridis_wins++;

                } else if (stone.getX() == L.getX() && stone.getY() == L.getY()) {
                    printw("Ο Λουκάς Μαλφόης κέρδισε το γύρο %d.\n",round);
                    Malfois_wins++;
                }

                refresh();
                timeout(100);
            }

        }

        //Οι εκτυπώσεις που ακολουθούν πραγματοποιούνται με χρώμα cyan.
        //Επίσης, το κείμενο είναι κινούμενο.
        attron(COLOR_PAIR(4));

        mvprintw(0,0,"---Στατιστικά---\n");
        mvprintw(0,0,"Συνολικοί γύροι:%d\n",round);
        mvprintw(0,0,"-Ο Μπάμπης Ποτερίδης κέρδισε %d γύρους!\n",Poteridis_wins);
        mvprintw(0,0,"-Ο Λουκάς Μαλφόης κέρδισε %d γύρους!\n",Malfois_wins);

        if(Poteridis_wins>Malfois_wins){
            mvprintw(0,0,"-Ο Μπάμπης Ποτερίδης κέρδισε τον αγώνα!!!n");
        }else if(Poteridis_wins<Malfois_wins){
            mvprintw(0,0,"-Ο  Λουκάς Μαλφόης κέρδισε τον αγώνα!!!\n");
        }else{
            mvprintw(0,0,"Ο αγώνας έληξε ισόπαλος\n");
        }
        attroff(COLOR_PAIR(4));

        refresh();
        getch();

        // Καταργηση της βιβλιοθήκης ncurses
        endwin();
    }
