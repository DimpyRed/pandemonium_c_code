//
// Created by Nicholas on 4/27/2020.
//

#ifndef PANDEMONIUM_C_CODE_CONTROLLER_H
#define PANDEMONIUM_C_CODE_CONTROLLER_H

#include "GameState.h"
#include "move.h"

class controller{
public:
    controller(GameState* game);
    void endTurn();
    void applyMove();
    void moveRequest();
    void undoRequest();


private:
    GameState* curGame;
    int numPlayers;
    int playerTurn; //value can range from 0 to numPlayers-1, corresponding to the player whose turn it is
};




#endif //PANDEMONIUM_C_CODE_CONTROLLER_H
