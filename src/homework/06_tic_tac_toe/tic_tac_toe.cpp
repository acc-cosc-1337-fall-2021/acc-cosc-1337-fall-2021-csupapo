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
    return false;
    
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
    for (auto& peg: pegs)
    {
        peg = " ";
    }
}

//Access to private variable(winner) for main and other free functions
string TicTacToe::get_winner() const
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
    /*if (pegs[0] == "X" && pegs [3] == "X" && pegs[6] == "X" ||
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
    }*/

    return false;
}

//Determines if game is won by rows
bool TicTacToe::check_row_win()
{
    /*if (pegs[0] == "X" && pegs [1] == "X" && pegs[2] == "X" ||
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
    } */

    return false;
}

//Determines if game is won diagonally 
bool TicTacToe::check_diagonal_win()
{
    /*if (pegs[0] == "X" && pegs [4] == "X" && pegs[8] == "X" ||
        pegs[2] == "X" && pegs [4] == "X" && pegs[6] == "X")
    {
        return true;
    }
    else if (pegs[0] == "O" && pegs [4] == "O" && pegs[8] == "O" ||
             pegs[2] == "O" && pegs [4] == "O" && pegs[6] == "O")
    {
        return true;
    } */

    return false;
}

//Display list in 3x3 format
ostream& operator<<(ostream& out, const TicTacToe& tictactoe)
{
    /*if (tictactoe.pegs.size() == 3)
    {
        out<< tictactoe.pegs[0] << " | " << tictactoe.pegs[1] << " | " << tictactoe.pegs[2] << "\n";
        out<< tictactoe.pegs[3] << " | " << tictactoe.pegs[4] << " | " << tictactoe.pegs[5] << "\n";
        out<< tictactoe.pegs[6] << " | " << tictactoe.pegs[7] << " | " << tictactoe.pegs[8] << "\n";
    }
    else if (tictactoe.pegs.size() == 4)
    {
        out<< tictactoe.pegs[0] << " | " << tictactoe.pegs[1] << " | " << tictactoe.pegs[2] << " | " << tictactoe.pegs[3] << "\n";
        out<< tictactoe.pegs[4] << " | " << tictactoe.pegs[5] << " | " << tictactoe.pegs[6] << " | " << tictactoe.pegs[7] << "\n";
        out<< tictactoe.pegs[8] << " | " << tictactoe.pegs[9] << " | " << tictactoe.pegs[10] << " | " << tictactoe.pegs[11] << "\n";
        out<< tictactoe.pegs[12] << " | " << tictactoe.pegs[13] << " | " << tictactoe.pegs[14] << " | " << tictactoe.pegs[15] << "\n";
    }
         return out; */

    for(std::size_t i=0; i < tictactoe.pegs.size(); i += std::sqrt(tictactoe.pegs.size()))
    {
        out<<tictactoe.pegs[i] <<" | "<<tictactoe.pegs[i+1]<<" | "<<tictactoe.pegs[i+2];
        
        if(tictactoe.pegs.size() == 16) {out<<" | "<<tictactoe.pegs[i+3];}
        {
            out<<"\n";
        }

    }
    return out;

}

//Overload cin operator to input positions into tictactoe instance
istream& operator>>(istream& in, TicTacToe& tictactoe)
{
    int position = 0;


        if (tictactoe.get_player() == "X")
        {
            cout<<"\nPlayer 'X's Turn \n";
        }

        if (tictactoe.get_player() == "O")
        {
            cout<<"\n\nPlayer 'O's Turn \n";
        }

        while (position < 1 || position > tictactoe.pegs.size())
        {
        cout<<"Enter a position from 1 to " <<tictactoe.pegs.size()<< ": " ;
        in>>position;
        cout<<"\n";
        }
        tictactoe.mark_board(position); 
        return in;
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
    return prompt;
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
        return exit_option;
    }
}
