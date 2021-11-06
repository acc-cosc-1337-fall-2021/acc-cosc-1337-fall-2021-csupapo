#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
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
		cout<<tictactoe;

		do
		{
			cin>>tictactoe;	
			cout<<"\n";
			/*The program doesn't execute with mark_board here but also the rest of the program
			  doesn't execute after the loop inside istream.*/
			tictactoe.mark_board(position); 
			cout<<"\n";
    		tictactoe.start_game(first_player);
			cout<<"\nDo you want to play again? (y/n): ";
			cin>>exit_prompt;
			exit_option = exit_validation(exit_prompt);
			// tictactoe.game_over();
		} 
		while (tictactoe.game_over() != true);

			cout<<"\nGame over.\n";
			string winner = tictactoe.get_winner();
			cout<<"The winner is " << winner << "!\n";
			tictactoe.start_game(first_player);
			cout<<"\nDo you want to play again? (y/n): ";
			cin>>exit_prompt;
			exit_option = exit_validation(exit_prompt);
		
		
	}while (exit_option != false);
	
}