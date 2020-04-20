//
// Created by david on 4/20/20.
//

#include "move.h"
#include "Piece.h"
#include "Position.h"
#include "GameState.h"
#include <algorithm>


/*
 * Accepts a well-formed Gamestate and Move, and applies the move. If the move is illegal, it returns back the
 * origional gameState and give a reason why the move is illegal.
might want to add an fstream as an output later. I'm not good with those though
*/
GameState applyMove(GameState inputState, Move move){
    GameState outputState = inputState;

    Piece *movingPiece = move.piece();
    Piece *targetPiece = outputState.atLocation(move.position().x, move.position().y);

    switch(move.code()){
        case MOVE_CODE::regular_movement:
            if ( !outputState.areAdjacent( Position(movingPiece->x, movingPiece->y), move.position() )  )
                break;
            if ( !outputState.pieceExists(movingPiece) )
                break;
            if ( !outputState.position_empty(move.position().x, move.position().y)  )
                break;

            outputState.movePieceAbsolute(move.piece(), move.position().x, move.position().y);
            break;
        case MOVE_CODE::regular_push:
            if ( !outputState.areAdjacent( Position(movingPiece->x, movingPiece->y), move.position() )  )
                break;
            if ( !outputState.pieceExists(movingPiece) )
                break;
            if ( outputState.position_empty(move.position().x, move.position().y) )
                break;
            outputState.movePieceRelative( targetPiece, targetPiece->x - movingPiece->x,
                                                        targetPiece->y - movingPiece->y);
            break;

    }


    return outputState;
}