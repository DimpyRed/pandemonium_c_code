//
// Created by Okabi on 4/27/2020.
//
#include "GameState.h"
#include "Piece.h"
#include <iostream>
//This should print the board
std::string GameStateToStringConverter(GameState g) {
    std::string str = "";
    std::vector<char> vec;
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j <= 6 - i; j++) {
            if (g.atLocation(i, j) != nullptr) {
                if (g.atLocation(i, j)->getTeam() == 1) {
                    vec.push_back('B');
                } else if (g.atLocation(i, j)->getTeam() == 2) {
                    vec.push_back('R');
                } else if (g.atLocation(i, j)->getTeam() == 3)
                    vec.push_back('Y');
            } else
                vec.push_back('-');
        }
    }
    for (int i = 0; i < vec.size(); i++)
        str += vec[i];
   // std::cout << str << std::endl;
    return str;
}
//This prints the board in text format
void printBoardInText(GameState g) {
    std::vector<char> vec;
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j <= 6 - i; j++) {
            if (g.atLocation(i, j) != nullptr) {
                if (g.atLocation(i, j)->getTeam() == 1) {
                    vec.push_back('B');
                } else if (g.atLocation(i, j)->getTeam() == 2) {
                    vec.push_back('R');
                } else if (g.atLocation(i, j)->getTeam() == 3)
                    vec.push_back('Y');
            } else
                vec.push_back('-');
        }
    }
    //std::cout << vec.size();
    ///Everything up to this point should have been needed to make a baord
    //Printing it in the format people want
    std::cout << " " << " " << " " << " " << vec[4] << std::endl;
    std::cout << " " << " " << " " << vec[3] << " " << vec[8] << std::endl;
    std::cout << " " << " " << vec[2] << " " << vec[7] << " " << vec[11] << std::endl;
    std::cout << " " << vec[1] << " " << vec[6] << " " << vec[10] << " " << vec[13] << std::endl;
    std::cout << vec[0] << " " << vec[5] << " " << vec[9] << " " << vec[12] << " " << vec[14] << std::endl;
}
int main(){
    ///Feel free to change these later
    std::vector<char> vec;
    //Team 1 is Blue
    //Team 2 is Red
    //Team 3 is Yellow
    //Type 1 is basic Unit
    GameState g = GameState();
    //g.addPiece(1,1,1,1);
    g.addPiece(1,1,1,1);
    g.addPiece(2,1,1,1);
    g.addPiece(1,2,1,1);

    g.addPiece(1,5,2,1);
    g.addPiece(1,4,2,1);
    g.addPiece(2,4,2,1);

    g.addPiece(5,1,3,1);
    g.addPiece(4,1,3,1);
    g.addPiece(4,2,3,1);

    g.printBoardInText();
    std::cout << g.GameStateToStringConverter();
    /*
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j <= 6 - i; j++) {
            if (g.atLocation(i, j) != nullptr) {
                if (g.atLocation(i, j)->getTeam() == 1) {
                    vec.push_back('B');
                } else if (g.atLocation(i, j)->getTeam() == 2) {
                    vec.push_back('R');
                } else if (g.atLocation(i, j)->getTeam() == 3)
                    vec.push_back('Y');
            } else
                vec.push_back('-');
        }
    }
    //std::cout << vec.size();
    ///Everything up to this point should have been needed to make a baord
    //Printing it in the format people want
    std::cout << " " << " " << " " << " " << vec[4] << std::endl;
    std::cout << " " << " " << " " << vec[3] << " " << vec[8] << std::endl;
    std::cout << " " << " " << vec[2] << " " << vec[7] << " " << vec[11] << std::endl;
    std::cout << " " << vec[1] << " " << vec[6] << " " << vec[10] << " " << vec[13] << std::endl;
    std::cout << vec[0] << " " << vec[5] << " " << vec[9] << " " << vec[12] << " " << vec[14] << std::endl;

    GameStateToStringConverter(g);*/

}

