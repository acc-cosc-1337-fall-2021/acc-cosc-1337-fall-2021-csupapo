#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <string>


using std::cout; using std::cin; using std::string; 

int main() 
{
	//Declare instances and variables (if any)
	TicTacToe tictactoe;
	TicTacToeManager tictactoe_manager;
	string first_player;
	int position;
	char exit_prompt;
	bool exit_option = false;
	int x_win;
	int o_win;
	int ties;


	//Program flow
	do
	{
		cout<<"Please select X or O: ";
    	cin>>first_player;
		player_validation(first_player);
		tictactoe.start_game(first_player);
		cout<<"\n";
		
		while (tictactoe.game_over() != true)
		{
			cin>>tictactoe;	
			cout<<"\n";
			cout << tictactoe;
			cout<<"\n";
		} 
			tictactoe_manager.save_game(tictactoe);
			tictactoe_manager.get_winner_total(x_win, o_win, ties); // gets total winner , x_win in main gets value from x_win inside function - and etc.
			cout<<"\nGame over.\n";
			string winner = tictactoe.get_winner();
			if (winner == "C")
			{
				cout<<"It's a tie"<< "!\n";
			}
			else
			{
			cout<<"The winner is " << winner << "!\n";
			}
			tictactoe.start_game(first_player);
			cout<<"\nDo you want to play again? (y/n): ";
			cin>>exit_prompt;
			exit_option = exit_validation(exit_prompt);

	}while (exit_option != false);
	
	cout<<tictactoe_manager;
	cout<<"\n";
	cout<<"O wins: "<<x_win<<"\n";
    cout<<"X wins: "<<o_win<<"\n";
    cout<<"Ties: "<<ties<<"\n";
	
}