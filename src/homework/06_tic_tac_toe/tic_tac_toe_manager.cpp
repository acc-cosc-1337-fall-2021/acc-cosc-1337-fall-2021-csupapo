//cpp
#include "tic_tac_toe_manager.h"


void TicTacToeManager::save_game(unique_ptr<TicTacToe>& tictactoe)
{
    update_winner_count(tictactoe->get_winner());
    games.push_back(move(tictactoe));
}
//Tally up total points of wins while program is executed | Gets x, o, and ties values from parameters in main
void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;                                                                                                                           
}

ostream& operator<<(ostream & out, const TicTacToeManager& manager)
{
    for (auto& game : manager.games)
    {
        out<<*game<<"\n"; // de-reference the vector of unique pointers in games
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
