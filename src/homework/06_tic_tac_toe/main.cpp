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
	char exit_prompt;
	bool exit_option = false;


	//Program flow
	do
	{
		cout<<"Please select X or O: ";
    	cin>>first_player;
		player_validation(first_player);
		tictactoe.start_game(first_player);
		cout<<"\n";
		tictactoe.display_board();
	
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
			cout<<"\n";
			tictactoe.display_board();
			tictactoe.game_over();
		} while (tictactoe.game_over() != true);

		cout<<"\nGame over.\n";
		string winner = tictactoe.get_winner();
		cout<<"The winner is " << winner << "!\n";
		tictactoe.start_game(first_player);
		cout<<"\nDo you want to play again? (y/n): ";
		cin>>exit_prompt;
		exit_option = exit_validation(exit_prompt);

	}while (exit_option != false);
	
}