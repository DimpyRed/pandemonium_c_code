//
// Created by david on 4/9/20.
//

#include "Piece.h"


Piece::Piece(int pos_x, int pos_y, int my_team, int my_type) {
    x = pos_x;
    y = pos_y;

    team = my_team;
    type = my_type;
}