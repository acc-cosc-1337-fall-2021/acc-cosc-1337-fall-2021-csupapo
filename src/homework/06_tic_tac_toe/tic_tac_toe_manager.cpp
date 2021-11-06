//cpp
#include "tic_tac_toe_manager.h"


void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
}

ostream& operator<<(ostream & out, const TicTacToeManager & manager)
{
    for (auto game: manager.games)
    {
        out<<game<<"\n";
    }

    out<<"O wins: "<<manager.o_win<<"\n";
    out<<"X wins: "<<manager.o_win<<"\n";
    out<<"Ties: "<<manager.o_win<<"\n";
    
    return out;

}

void TicTacToeManager::update_winner_count(string winner)
    {
        if(winner == "X")
        {
            x_win += 1;
        }

        else if (winner == "O")
        {
            o_win += 1;
        }

        else
        {
            ties += 1;
        }
    }
