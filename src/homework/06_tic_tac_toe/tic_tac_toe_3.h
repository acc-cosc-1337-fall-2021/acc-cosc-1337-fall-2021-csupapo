//h
#include "tic_tac_toe.h"

#ifndef TICTACTOE_3_H
#define TICTACTOE_3_H


class TicTacToe_3 : public TicTacToe
{

public:
    TicTacToe_3() : TicTacToe(3){}
    TicTacToe_3(vector<string> p, string win): TicTacToe(p, win){}

private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;

};

#endif