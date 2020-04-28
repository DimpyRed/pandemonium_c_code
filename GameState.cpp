//
// Created by david on 4/9/20.
//

#include "GameState.h"

GameState::GameState() {}

GameState::GameState(const GameState &other) {
    for(int i = 0; i < other.pieces.size(); i++) {
        this->pieces.emplace_back(new Piece(
                other.pieces[i]->x,
                other.pieces[i]->y,
                other.pieces[i]->getTeam(),
                other.pieces[i]->getType())
                );
    }
}

GameState::~GameState() {
    for(auto iter = pieces.begin(); iter != pieces.end(); iter++) {
        delete *iter;
    }
    pieces.clear();
}

void GameState::addPiece(int pos_x, int pos_y, int team) {
    pieces.emplace_back(
            new Piece(pos_x, pos_y, team, Piece_type::standard)
            );
}


void GameState::addPiece(int pos_x, int pos_y, int team, int type) {
    pieces.emplace_back(
            new Piece( pos_x, pos_y, team, type)
            );
}


bool GameState::position_empty(int pos_x, int pos_y) {

    for (Piece *p : pieces){
        if ((p->x == pos_x) && (p->y == pos_y)){
            return false;
        }
    }

    return true;
}

void GameState::movePieceAbsolute(Piece *p, int pos_x, int pos_y) {
    p->x = pos_x;
    p->y = pos_y;
}

void GameState::movePieceRelative(Piece *p, int move_x, int move_y) {
    p->x += move_x;
    p->y += move_y;
}



std::vector<Position> GameState::getAdjacentSpaces(int pos_x, int pos_y) {

    std::vector<Position> adjacencies;

    for (auto &v: ADJACENT_VECTORS) {
        adjacencies.emplace_back(Position(v[0], v[1]));
    }

    return adjacencies;
}


std::vector<Piece*> GameState::pieceList() {
    return pieces;
}

bool GameState::onBoard(int x, int y) {
    return (x >= 1 && y >= 1 && x + y <= 6); //corners are at (1,1), (1,5), (5,1)
}

Piece* GameState::atLocation(int x, int y) {
    for(int i = 0; i < pieces.size(); i++) {
        if(pieces[i]->x == x && pieces[i]->y == y)
            return pieces[i];
    }
    return nullptr;
}

void GameState::removePiece(Piece *p) {
    for(int i = 0; i < pieces.size(); i++) {
        if(pieces[i] == p) {
            delete pieces[i];
            pieces[i] = nullptr;
            pieces.erase(pieces.begin() + i);
            return;
        }
    }
}

bool GameState::pieceExists(Piece *p) {
    for(int i = 0; i < pieces.size(); i++) {
        if(pieces[i] == p) {
            return true;
        }
    }
    return false;
}

bool GameState::areAdjacent(Position pos_1, Position Pos_2) {
    int dif = (pos_1.x + pos_1.y) - (Pos_2.x + Pos_2.y);
    return (dif > -2 && dif < 2);
}

Piece* GameState::correspondingPiece(Piece *p, GameState other) {
    for(int i = 0; i < other.pieces.size(); i++) {
        if(other.pieces[i]->x == p->x && other.pieces[i]->y == p->y && other.pieces[i]->getType() == p->getType()
            && other.pieces[i]->getTeam() == p->getTeam())
            return other.pieces[i];
    }
    return nullptr;
}