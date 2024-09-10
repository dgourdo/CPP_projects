#ifndef ICE20390043_THEORYEXERCISE_ENGINE_H
#define ICE20390043_THEORYEXERCISE_ENGINE_H

#include "M.h"
#include "L.h"
#include "Stone.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <ncurses.h>
#include <string>

using namespace std;

class Engine{

public:
    Engine();

    vector<vector<char>> LoadMazeFromFile(const string&);
    void RandomStartingPositions(vector<vector<char>>&,M&,L&,Stone&);
    void PrintMaze(const vector<vector<char>>&,const M&,const L&,const Stone&);

    void MoveStudents(vector<vector<char>>&,M&,L&,Stone&);
    void MoveStone(Stone&,vector<vector<char>>&,M&,L&);
    void Play(vector<vector<char>>&,M&,L&,Stone&);

};

#endif //ICE20390043_THEORYEXERCISE_ENGINE_H
