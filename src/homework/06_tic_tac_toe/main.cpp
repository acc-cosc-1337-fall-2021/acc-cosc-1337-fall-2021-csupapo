#include "tic_tac_toe.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string;

int main() 
{
	//Declare instances and variables (if any)
	TicTacToe tictactoe;
	string first_player;
	int position;

	//Program flow
	cout<<"Please select X or O: ";
    cin>>first_player;
	tictactoe.start_game(first_player);

	do
	{
		if (tictactoe.get_player() == "X")
		{
			cout<<"\nPlayer 'X's Turn \n";
		}

		if (tictactoe.get_player() == "O")
		{
			cout<<"\n\nPlayer 'O's Turn \n";
		}
		cout<<"Enter a position from 1 to 9: ";
		cin>>position;
		tictactoe.mark_board(position);
		tictactoe.display_board();
		tictactoe.game_over();
		
	} while (tictactoe.game_over() != 0);

	cout<<"\nGame over.";
	tictactoe.start_game(first_player);
	
}