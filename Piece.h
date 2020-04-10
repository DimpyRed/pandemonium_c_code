//
// Created by david on 4/9/20.
//

#ifndef UNTITLED_PIECE_H
#define UNTITLED_PIECE_H


enum Piece_type{
    standard,
};



class Piece{
public:
    int x; //position
    int y; //position
    Piece(int pos_x, int pos_y, int my_team, int my_type);

private:
    int team; //enumerated
    int type; //enumerated,
};



#endif //UNTITLED_PIECE_H
