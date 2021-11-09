//cpp
#include "tic_tac_toe_manager.h"


void TicTacToeManager::save_game(TicTacToe tictactoe)
{
    games.push_back(tictactoe);
    update_winner_count(tictactoe.get_winner());
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
}

ostream& operator<<(ostream & out, const TicTacToeManager & tictactoe_manager)
{
    for (auto game: tictactoe_manager.games)
    {
        out<<game<<"\n";
    }
    
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
