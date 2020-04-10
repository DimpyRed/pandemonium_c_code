//
// Created by david on 4/9/20.
//

#ifndef PANDEMONIUM_C_CODE_GAMESTATE_H
#define PANDEMONIUM_C_CODE_GAMESTATE_H


#include "Piece.h"
#include <vector>



class GameState{
public:
    void addPiece(int pos_x, int pos_y, int team, int type);
    void addPiece(int pos_x, int pos_y, int team);
    bool position_empty(int pos_x, int pos_y);


private:
    std::vector<Piece> pieces;
};



#endif //PANDEMONIUM_C_CODE_GAMESTATE_H
