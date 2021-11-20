//h
#include "tic_tac_toe.h"
#include<memory>
#include<fstream>
#include<iostream>

#ifndef TICTACTOE_DATA_H
#define TICTACTOE_DATA_H

class TicTacToeData
{
public:
    void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games);
    vector<std::unique_ptr<TicTacToe>> get_games();

private:
    string file_name{"games.data"};

};




#endif