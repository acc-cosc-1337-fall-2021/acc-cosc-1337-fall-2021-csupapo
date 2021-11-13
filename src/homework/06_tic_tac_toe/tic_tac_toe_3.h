//h
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

#ifndef TICTACTOE_3
#define TICTACTOE_3


class TicTacToe_3 : public TicTacToe
{

public:
    TicTacToe_3() : TicTacToe(3){}

private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;

};

#endif