//
// Created by david on 4/9/20.
//

#include "GameState.h"

void GameState::addPiece(int pos_x, int pos_y, int team) {
    pieces.push_back(Piece(pos_x, pos_x, team, Piece_type::standard));
}


void GameState::addPiece(int pos_x, int pos_y, int team, int type) {

}
