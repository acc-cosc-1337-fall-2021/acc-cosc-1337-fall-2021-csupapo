#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
// #include <memory>
#include <iostream>
#include <string>



using std::cout; using std::cin; using std::string; using std::unique_ptr; using std::make_unique;

int main() 
{
	// TicTacToe tictactoe;
	unique_ptr<TicTacToe> tictactoe; //save memory region for a game
	TicTacToeManager tictactoe_manager;

	//Declare instances and variables (if any)
	string first_player = "X";
	int position;
	char exit_prompt;
	bool exit_option = false;
	int x_win;
	int o_win;
	int ties;

	//Program flow
	do
	{
		auto game_choice = 1;
		
		while (game_choice != 3 && game_choice !=4)
		{
			cout<<"\nWhich tictactoe board would you like to play with?\n";
			cout<<"\t3: 3 x 3 board\n";

			cout<<"\t4: 4 x 4 board\n";
			cout<<"Your Choice: \n";
			cin>>game_choice;
		}
		if (game_choice == 3)
		{
			tictactoe = make_unique<TicTacToe_3>();
		}
		else if (game_choice == 4)
		{
			tictactoe = make_unique<TicTacToe_4>();
		}
		
		cout<<"Please select X or O: ";
    	cin>>first_player;
		player_validation(first_player);
		tictactoe->start_game(first_player);
		cout<<"\n";
		
		while (tictactoe->game_over() != true)
		{
			cin>>*tictactoe;	
			cout << *tictactoe;
		} 
		cout<<"\nGame over.\n";
		string winner = tictactoe->get_winner();
		cout<<"The winner is " << winner << "!\n";
		tictactoe_manager.save_game(tictactoe);
		tictactoe_manager.get_winner_total(x_win, o_win, ties); // gets total winner , x_win in main gets value from x_win inside function - and etc.
		cout<<"\nDo you want to play again? (y/n): ";
		cin>>exit_prompt;
		exit_option = exit_validation(exit_prompt);

	}while (exit_option != false);
	
	cout<<tictactoe_manager;
	cout<<"\n";
	cout<<"X wins: " << x_win << "\n";
    cout<<"O wins: " << o_win << "\n";
    cout<<"Ties: " << ties << "\n";
	
}