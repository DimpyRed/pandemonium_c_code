//
// Created by david on 4/9/20.
//

#include "GameState.h"

void GameState::addPiece(int pos_x, int pos_y, int team) {
    pieces.emplace_back(pos_x, pos_x, team, Piece_type::standard);
}


void GameState::addPiece(int pos_x, int pos_y, int team, int type) {
    pieces.emplace_back(pos_x, pos_y, team, type);
}


bool GameState::position_empty(int pos_x, int pos_y) {

    for (Piece p : pieces){
        if ((p.x == pos_x) && (p.y == pos_y)){
            return true;
        }
    }

    return false;
}
