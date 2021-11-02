//cpp
#include "tic_tac_toe.h"
#include <iostream>


using std::cout; using std::cin; using std::string;

//Access to private function check_board_full;
bool TicTacToe::game_over()
{
    if (check_column_win() == true)
    {
        set_winner();
        return true;
    }
    else if(check_row_win() == true)
    {
        set_winner();
        return true;
    }
    else if(check_diagonal_win() == true)
    {
        set_winner();
        return true;
    }

    else if (check_board_full() == true)
    {
        winner = "C";
        return true;
    }
    
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
    bool value = true;
    for (auto i : pegs)
    {
        if (i == " ")
        {
            value = false;
        }    
    }
    return value;
}

//Set all elements to spaces
void TicTacToe::clear_board()
{
    pegs.assign(9, " ");
}

//Access to private variable(winner) for main and other free functions
string TicTacToe::get_winner()
{
    return winner;
}

//Swap Player from X to O to determine correct winner 
void TicTacToe::set_winner()
{
    if (player == "X")
    {
        winner = "O";
    }

    if (player == "O")
    {
        winner = "X";
    }
}

// Determines if game is won by columns
bool TicTacToe::check_column_win()
{
    if (pegs[0] == "X" && pegs [3] == "X" && pegs[6] == "X" ||
        pegs[1] == "X" && pegs [4] == "X" && pegs[7] == "X" || 
        pegs[2] == "X" && pegs [5] == "X" && pegs[8] == "X")
    {
        return true;
    }
    else if (pegs[0] == "O" && pegs [3] == "O" && pegs[6] == "O" ||
             pegs[1] == "O" && pegs [4] == "O" && pegs[7] == "O" || 
             pegs[2] == "O" && pegs [5] == "O" && pegs[8] == "O")
    {
        return true;
    }
}

//Determines if game is won by rows
bool TicTacToe::check_row_win()
{
    if (pegs[0] == "X" && pegs [1] == "X" && pegs[2] == "X" ||
        pegs[3] == "X" && pegs [4] == "X" && pegs[5] == "X" || 
        pegs[6] == "X" && pegs [7] == "X" && pegs[8] == "X")
    {
        return true;
    }
    else if (pegs[0] == "O" && pegs [1] == "O" && pegs[2] == "O" ||
             pegs[3] == "O" && pegs [4] == "O" && pegs[5] == "O" || 
             pegs[6] == "O" && pegs [7] == "O" && pegs[8] == "O")
    {
        return true;
    }
}

//Determines if game is won diagonally 
bool TicTacToe::check_diagonal_win()
{
    if (pegs[0] == "X" && pegs [4] == "X" && pegs[8] == "X" ||
        pegs[2] == "X" && pegs [4] == "X" && pegs[6] == "X")
    {
        return true;
    }
    else if (pegs[0] == "O" && pegs [4] == "O" && pegs[8] == "O" ||
             pegs[2] == "O" && pegs [4] == "O" && pegs[6] == "O")
    {
        return true;
    }
}


/* ----------------------------  Free Functions ---------------------------- */

//Validation for player input (X's and O's) - uses reference parameter 
string player_validation(string &prompt)
{
    
    while(prompt != "X" && prompt != "O")
    {
        cout<<"\nDon't forget to use uppercase X or O.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        cout<<"Please select X or O: ";
        cin>>prompt;
    }
    // return prompt;
}

//Validation for exiting program 
bool exit_validation(char exit_prompt)
{
    bool exit_option;
    {   
        while (exit_prompt != 'y' && exit_prompt != 'Y' &&
               exit_prompt != 'n' && exit_prompt != 'N' )
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            cout<<"Invalid input. Please enter (y/n) to restart or exit the game. : ";
            cin>>exit_prompt;
        }

        if (exit_prompt == 'n' || exit_prompt == 'N')
        {
            exit_option = false;
            return exit_option;
        }
        else if (exit_prompt == 'y' || exit_prompt == 'Y')
        {
            exit_option = true;
            return exit_option;
        }
    }
}
