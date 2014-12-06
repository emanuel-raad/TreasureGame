/* 
 * File:   main.cpp
 * Author: emanuel
 *
 * Created on December 5, 2014, 3:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Map.h"
#include "player.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Map newMap;
    
    newMap.setupMap();
    newMap.printMap();
    //newMap.welcome();
    while (true) {
        newMap.move();
        newMap.printMap();
        if (newMap.detect())
            break;
    }
    newMap.printAnswers();
    
    return 0;
}