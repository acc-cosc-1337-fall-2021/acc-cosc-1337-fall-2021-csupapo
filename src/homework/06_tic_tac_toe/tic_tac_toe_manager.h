//h
#include "tic_tac_toe.h"
#include<iostream>
#include<memory>

using std::unique_ptr; using std::make_unique; using std::move;

#ifndef TICTACTOE_MANAGER_H
#define TICTACTOE_MANAGER_H

class TicTacToeManager 
{
public:
    void save_game(unique_ptr<TicTacToe>& tictactoe);
    friend ostream& operator<<(ostream & out, const TicTacToeManager& manager);
    void get_winner_total(int& o, int& w, int& t);

private:
    vector<unique_ptr<TicTacToe>> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(string winner);

};

#endif
