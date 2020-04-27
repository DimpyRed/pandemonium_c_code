//
// Created by david on 4/9/20.
//

#ifndef PANDEMONIUM_C_CODE_GAMESTATE_H
#define PANDEMONIUM_C_CODE_GAMESTATE_H


#include "Piece.h"
#include <vector>
#include "Position.h"
#include <iostream>


//organized in counter-clockwise direction for your convenience
const int ADJACENT_VECTORS[6][2] = {{1,0}, {0,1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}};


/*
 * 'pieces' should be the only permanent date structure used.
 *
 */


class GameState{
public:
    GameState();
    GameState(const GameState& other);
    ~GameState();
    void addPiece(int pos_x, int pos_y, int team, int type);
    void addPiece(int pos_x, int pos_y, int team);
    void removePiece(Piece *p);
    bool position_empty(int pos_x, int pos_y);
    void movePieceAbsolute(Piece *p, int pos_x, int pos_y);
    void movePieceRelative(Piece *p, int move_x, int move_y);
    std::vector<Position> getAdjacentSpaces(int pos_x, int pos_y);
    bool areAdjacent(Position pos_1, Position Pos_2);
    bool pieceExists(Piece *p);

    std::vector<Piece*> pieceList();
    bool onBoard(int x, int y);
    Piece* atLocation(int x, int y);
    Piece* correspondingPiece(Piece *p, GameState other);
    std::string GameStateToStringConverter();
    void printBoardInText();

private:
    std::vector<Piece *> pieces;

};



#endif //PANDEMONIUM_C_CODE_GAMESTATE_H
