/* 
 * File:   player.h
 * Author: emanuel
 *
 * Created on December 6, 2014, 2:21 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

class player {
    public:
        /*
         * xpos and ypos keep track of the player's current postition
         * on the map. xpos = columns, ypos = rows.
         * xposOld and yposOld are where the player was before moving.
         */
        
        int xpos, ypos, xposOld, yposOld, moveCount;
        player();
};

#endif	/* PLAYER_H */