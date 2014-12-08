/* 
 * File:   Map.h
 * Author: emanuel
 *
 * Created on December 5, 2014, 3:52 PM
 */

#ifndef MAP_H
#define	MAP_H

#include "PLAYER.h"

class Map : public player {
    int row, col;  //Size of the map
    int numberOfTraps;
    int goldPosX, goldPosY;
    bool firstRun; //Not used yet. Determines if it's the first time the program 
                   //is run.
    std::string status; //String storing whether the player has won or lost.
    std::string hiddenTile;  //Letters for drawing the map
    std::string blankTile;
    std::string trap;
    std::string gold;
    std::string player;
    std::string distance;
    
    public:
        std::string ** map; //Map that will be displayed to the player.
        std::string ** pos; //Map with the traps and gold
        int ** coords; //Used for debugging. Coords for the traps and gold.
        Map(); //constructor
        void setupMap();
        void printMap();
        void setPosition();
        void welcome();
        void move();
        bool detect();
        void printAnswers();
        void hotOrCold();
        void clear();
        virtual ~Map();
};

#endif	/* MAP_H */