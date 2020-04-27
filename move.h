//
// Created by david on 4/20/20.
//

#ifndef PANDEMONIUM_C_CODE_MOVE_H
#define PANDEMONIUM_C_CODE_MOVE_H




#include "Piece.h"
#include "Position.h"


//signifies the possible move codes for a piece
enum MOVE_CODE{
    regular_movement,
    regular_push
};


class Move{
public:
    Move(Piece *moving_piece, Position target_position, int move_code, Position position) : _position(position) {
        _piece = moving_piece;
        _position = target_position;
        _code = move_code;
    }

    Piece *piece(){return _piece;}
    Position position(){ return  _position;}
    int code(){return _code;}


private:
    Piece *_piece;
    Position _position;
    int _code;
};

#endif //PANDEMONIUM_C_CODE_MOVE_H
