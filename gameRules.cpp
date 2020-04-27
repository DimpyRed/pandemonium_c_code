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

    Piece *movingPiece = outputState.correspondingPiece(move.piece(), inputState);
    Piece *targetPiece = outputState.atLocation(move.position().x, move.position().y); //can be null

    switch(move.code()){
        case MOVE_CODE::regular_movement:
            if ( !outputState.areAdjacent( Position(movingPiece->x, movingPiece->y), move.position() )  )
                break;
            if ( !outputState.pieceExists(movingPiece) )
                break;
            if ( !outputState.position_empty(move.position().x, move.position().y)  )
                break;

            outputState.movePieceAbsolute(movingPiece, move.position().x, move.position().y);
            if (!outputState.onBoard(movingPiece->x, movingPiece->y) ){
                outputState.removePiece(movingPiece);
                break;
            }
            break;
        case MOVE_CODE::regular_push:
            if ( !outputState.areAdjacent( Position(movingPiece->x, movingPiece->y), move.position() )  )
                break;
            if ( !outputState.pieceExists(movingPiece) )
                break;
            if ( outputState.position_empty(move.position().x, move.position().y))
                break;

            Position pushTo( targetPiece->x + (targetPiece->x - movingPiece->x),
                             targetPiece->y + (targetPiece->y - movingPiece->y));
            if ( !outputState.position_empty(pushTo.x, pushTo.y ))
                break;

            outputState.movePieceAbsolute(targetPiece, pushTo.x, pushTo.y );
            if (!outputState.onBoard(movingPiece->x, movingPiece->y)){
                outputState.removePiece(targetPiece);
                break;
            }
            break;
    }


    return outputState;
}