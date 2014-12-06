/* 
 * File:   Map.h
 * Author: emanuel
 *
 * Created on December 5, 2014, 3:52 PM
 */

#ifndef MAP_H
#define	MAP_H

class Map {
    int row, col, xpos, ypos, xposOld, yposOld;
    std::string ** map;
    std::string ** pos;
    bool firstRun;
    public:
        Map();
        void setupMap();
        void printMap();
        void welcome();
        void move();
        void setPosition();
        bool detect();
        //void printAnswers();
        ~Map();
};

#endif	/* MAP_H */