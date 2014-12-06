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
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Map newMap;
    newMap.setupMap();
    newMap.welcome();
    while (true) {
        newMap.move();
        newMap.printMap();
        if (newMap.detect())
            break;
    }
    
    cout << "Thank you!" << endl;
    
    return 0;
}

//Add function that prints map with traps and gold
