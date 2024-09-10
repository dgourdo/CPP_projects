#include "Moving.h"
#include "M.h"
#include "L.h"
#include "Stone.h"
#include "Engine.h"

int main(int argc,char** argv){

        if(argc!=2){
            cout<<"ERROR!Το αρχείο που φιλοξενεί το λαβύρινθο πρέπει να δοθεί σαν όρισμα στη γραμμή εντολών."<<endl;
        }

        const string& file_name=(argv[0]);

        try{
            Engine engine;
            vector<vector<char>> maze=engine.LoadMazeFromFile(file_name);

            M M(0,0);
            L L(0,0);
            Stone stone(0,0);

            engine.Play(maze,M,L,stone);
        }catch(const exception& e){
            cout<<"ERROR!"<<e.what();
        }

    return 0;
}

//g++ -c Moving.cpp -o Moving.o
//g++ -c M.cpp -o M.o
//g++ -c L.cpp -o L.o
//g++ -c Stone.cpp -o Stone.o
//g++ -c Engine.cpp -o Engine.o
//g++ Moving.o M.o L.o Stone.o Engine.o main.cpp -o main -lncurses


