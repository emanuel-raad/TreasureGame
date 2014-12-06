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
    int row, col;
    bool firstRun;
    std::string status;
    
    public:
        std::string ** map;
        std::string ** pos;
        std::string coords[6];
        Map();
        void setupMap();
        void printMap();
        void setPosition();
        void welcome();
        void move();
        bool detect();
        void printAnswers();
        virtual ~Map();
};

#endif	/* MAP_H */