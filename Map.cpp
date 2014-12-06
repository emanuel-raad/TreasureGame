/* 
 * File:   Map.cpp
 * Author: emanuel
 * 
 * Created on December 5, 2014, 3:52 PM
 */
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

#include "Map.h"

Map::Map(){
    row = 7;
    col = 10;
    xpos = 0;
    ypos = 0;
    xposOld = 0;
    yposOld = 0;
    
    map = new string*[row];
    pos = new string*[row];
    for(int i = 0; i < row; i++){
        map[i] = new string [col];
        pos[i] = new string [col];
    }
}

//rewrite this function to clear map
void Map::setupMap(){

    firstRun = true;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            map[i][j] = "X";
            pos[i][j] = " ";
        }
    }
    
    double seed = time(0);
    srand(seed);

    for (int i = 0; i < 6 ; i++)
    {
        int x = rand() % row;
        int y = rand() % col;
        
        cout << x << " " << y << endl;
        if (i == 5)
            pos[x][y] = "G";
        else
            pos[x][y] = "T";
    }

    //position
    setPosition();
    cout << "done!" << endl;
}

void Map::welcome(){
    cout << "Use WASD to move around the map" << endl;
    cout << "Try and find the treasure without stepping on the traps!" << endl;
    cout << "Ready?" << endl;
    cin.get();
}

void Map::printMap(){
    
    cout << "ypos:" << ypos << endl;
    cout << "xpos:" << xpos << endl;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    
    firstRun = false;
}

void Map::move(){
    char direction;
    cin >> direction;
    yposOld = ypos;
    xposOld = xpos;
    switch (direction) {
        case 'w':
            if (ypos > 0)
                ypos -= 1;
            break;
        case 's':
            if (ypos < (row-1))
                ypos += 1;
            break;
        case 'd':
            if (xpos < (col-1))
                xpos += 1;
            break;
        case 'a':
            if (xpos > 0)
            xpos -= 1;
            break;
        default:
            break;    
    }

    setPosition();
}

void Map::setPosition(){
    map[abs(yposOld)][xposOld] = "X";
    map[abs(ypos)][xpos] = "P";
}

bool Map::detect(){
    if (pos[abs(ypos)][xpos] == "T")
        cout << "You lose" << endl;
    else if (pos[abs(ypos)][xpos] == "G")
        cout << "You win" << endl;
}
Map::~Map(){
    delete [] map;
}