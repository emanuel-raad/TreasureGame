/* 
 * File:   main.cpp
 * Author: emanuel
 *
 * Created on December 5, 2014, 3:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "MAP.h"
#include "PLAYER.h"
using namespace std;



int main(int argc, char** argv) {

    Map newMap;
    newMap.welcome();
    newMap.setupMap();
    newMap.printMap();
    do {
        newMap.move();
        newMap.hotOrCold();
        newMap.clear();
        newMap.printMap();
    } while (newMap.detect());
    
    newMap.clear();
    newMap.printAnswers();
    
    return 0;
}