//h
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

#ifndef TICTACTOE_4_H
#define TICTACTOE_4_H


class TicTacToe_4 : public TicTacToe
{

public:
    TicTacToe_4() : TicTacToe(4){}
    TicTacToe_4(vector<string> p, string win): TicTacToe(p, win){}
    
private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;

};

#endif