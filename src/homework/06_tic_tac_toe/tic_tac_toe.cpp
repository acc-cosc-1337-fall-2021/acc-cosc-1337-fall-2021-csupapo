//cpp
#include "tic_tac_toe.h"
#include <iostream>

using std::cout; using std::cin; using std::string;

//Access to private function check_board_full;
bool TicTacToe::game_over()
{
    return check_board_full();
}

//Assign free variable(first_player) to private variable(player) and call clear_board function 
void TicTacToe::start_game(string first_player)
{   
    player = first_player;
    clear_board();
}

//Ask user for position and place mark on 3x3
void TicTacToe::mark_board(int position)
{
    int grid = position - 1;
    pegs[grid] = player; //marks position
    set_next_player(); //swaps player from X to O
}

//Access to private variable(player) for main and other free functions
string TicTacToe::get_player() const
{
    return player;
}

//Display list in 3x3 format
void TicTacToe::display_board() const
{
        cout<< pegs[0] << " | " << pegs[1] << " | " << pegs[2] << "\n";
        cout<< pegs[3] << " | " << pegs[4] << " | " << pegs[5] << "\n";
        cout<< pegs[6] << " | " << pegs[7] << " | " << pegs[8] << "\n";
}

//Swap Player from X to O and vice versa
void TicTacToe::set_next_player()
{
    if (player == "X" || player == "x")
    {
        player = "O";
    }
    else if (player == "O" || player == "o")
    {
        player = "X";
    }
}

//Iterate over vector until no space is found 
bool TicTacToe::check_board_full()
{
    for (auto i : pegs)
    {
        if (i == " ")
        {
            return 1;
        }
    }
}

//Set all elements to spaces
void TicTacToe::clear_board()
{
    pegs[0,8] = " ";
}