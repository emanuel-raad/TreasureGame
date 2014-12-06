/* 
 * File:   Map.cpp
 * Author: emanuel
 * 
 * Created on December 5, 2014, 3:52 PM
 */

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#include "MAP.h"
#include "PLAYER.h"

Map::Map(){
    row = 7;
    col = 10;
    
    map = new string*[row];
    pos = new string*[row];
    for(int i = 0; i < row; i++){
        map[i] = new string [col];
        pos[i] = new string [col];
    }
}


void Map::setupMap(){
    //cout << xpos << ypos << endl;
    firstRun = true;
    
    //Fills map and pos array with values.
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            map[i][j] = "X";
            pos[i][j] = " ";
        }
    }
    
    double seed = time(0); //Randomly chooses 5 coords for the traps. 
    srand(seed);

    for (int i = 0; i < 6 ; i++)
    {
        int x = rand() % row; //Random number between 0 and number of rows
        int y = rand() % col; //Random number between 0 and number of columns
        
        coords[i] += to_string(x) + to_string(y); //Debugging coords
        
        //cout << coords[i] << endl;
        if (i == 5)
            pos[x][y] = "G"; //Sets 1 gold
        else
            pos[x][y] = "T"; //Sets 5 traps
    }

    setPosition();
    cout << "Setup properly!" << endl;
}

// Welcome message. Waits until the user presses enter to start the game
void Map::welcome(){
    cout << "Use WASD to move around the map" << endl;
    cout << "Try and find the gold without stepping on the traps!" << endl;
    cout << "Ready?" << endl;
    cin.ignore();
}

void Map::printMap(){
    //Prints 50 newlines to "clear" the console
    cout << string(50, '\n');
    //Current position
    cout << "ypos:" << ypos << endl; 
    cout << "xpos:" << xpos << endl;
    
    //Prints map array. 2d array
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    
    firstRun = false;
}

void Map::printAnswers(){
    //Prints newlines to "clear" the console
    cout << string(50, '\n');
    
    /* Prints two maps side by side. realMap is the map with the player and
     * all the tiles hidden. ansMap is the map with the gold and treasure
     * shown. 
     */
    for(int i = 0; i < row; i++){
        string realMap, ansMap;
        for(int j = 0; j < col; j++){
            realMap += map[i][j];
            if (pos[i][j] != " ")
                ansMap += pos[i][j];
            else
                ansMap += map[i][j];
        }
        cout << realMap << "\t" << ansMap << endl;
    }
    
    //status is set in detect(). Either "You win!" or "You lose!"
    cout << status << endl;
    cout << "Move count:" << moveCount << endl; //moveCount set in move()
    cout << "Thank you!" << endl;
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
    moveCount += 1;
    setPosition();
}

/* Changes the value of where the player is moving to P
 * Changes the value of where the player is to X (default value for hidden tiles)
 */
void Map::setPosition(){
    map[abs(yposOld)][xposOld] = "X";
    map[abs(ypos)][xpos] = "P";
}

bool Map::detect(){
    if (pos[abs(ypos)][xpos] == "T"){
        status += "You lose";
        return false;
    }
    else if (pos[abs(ypos)][xpos] == "G"){
        status += "You win";
        return false;
    }
    return true;
}

Map::~Map(){
    delete [] map;
    delete [] pos;
}