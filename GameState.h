//
// Created by david on 4/9/20.
//

#ifndef PANDEMONIUM_C_CODE_GAMESTATE_H
#define PANDEMONIUM_C_CODE_GAMESTATE_H


#include "Piece.h"
#include <vector>


/*
 * 'pieces' should be the only permanent date structure used.
 *
 */


class GameState{
public:
    GameState(const GameState& other);
    ~GameState();
    void addPiece(int pos_x, int pos_y, int team, int type);
    void addPiece(int pos_x, int pos_y, int team);
    bool position_empty(int pos_x, int pos_y);
    void movePieceAbsolute(Piece *p, int pos_x, int pos_y);
    void movePieceRelative(Piece *p, int move_x, int move_y);
    std::vector<Piece*> pieceList();
    bool onBoard(int x, int y);
    Piece* atLocation(int x, int y);

private:
    std::vector<Piece *> pieces;
};



#endif //PANDEMONIUM_C_CODE_GAMESTATE_H
