
//
// Created by david on 4/11/20.
//

#ifndef PANDEMONIUM_C_CODE_POSITION_H
#define PANDEMONIUM_C_CODE_POSITION_H

/*
 * I only recommend using this data structure when dealing with arrays.
 *
 */


class Position{
public:
    int x;
    int y;

    Position() {
        x = 0; y = 0;
    }
    Position(int pos_x, int pos_y){
        x = pos_x; y = pos_y;
    };
    Position&operator=(const Position& other) {
        x = other.x;
        y = other.y;
        return *this;
    }
};

#endif //PANDEMONIUM_C_CODE_POSITION_H