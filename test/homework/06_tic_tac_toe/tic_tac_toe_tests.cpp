#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
// #include<string>    <--- already included in tic_tac_toe.h


TEST_CASE("Verify Test Configuration", "verification") 
{
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X", "verification") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	REQUIRE(tictactoe.get_player() == "X");
}

TEST_CASE("Test second player set to O", "verification") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("O");
	REQUIRE(tictactoe.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected", "verification") 
{
	TicTacToe tictactoe;
	string first_player = "X";
	tictactoe.start_game(first_player);
	tictactoe.mark_board(1); // X's turn
	REQUIRE(tictactoe.game_over() == (false)); 

	tictactoe.mark_board(2); 
	REQUIRE(tictactoe.game_over() == (false));

	tictactoe.mark_board(3); // X's turn
	REQUIRE(tictactoe.game_over() == (false)); 

	tictactoe.mark_board(5);
	REQUIRE(tictactoe.game_over() == (false));

	tictactoe.mark_board(4); // X's turn
	REQUIRE(tictactoe.game_over() == (false)); 

	tictactoe.mark_board(6);
	REQUIRE(tictactoe.game_over() == (false)); 

	tictactoe.mark_board(8); // X's turn
	REQUIRE(tictactoe.game_over() == (false)); 

	tictactoe.mark_board(7);
	REQUIRE(tictactoe.game_over() == (false)); 

	tictactoe.mark_board(9); // X's turn
	REQUIRE(tictactoe.game_over() == (true));

	REQUIRE(tictactoe.get_winner() == "C"); 
} 

TEST_CASE("Test win by first column", "1st column winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(1); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(4); // X's turn
	tictactoe.mark_board(3);
	tictactoe.mark_board(7); // X's turn
	REQUIRE(tictactoe.game_over() == (true)); 
	REQUIRE(tictactoe.get_winner() == "X"); 
}

TEST_CASE("Test win by second column", "2nd column winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(2); // X's turn
	tictactoe.mark_board(3);
	tictactoe.mark_board(5); // X's turn
	tictactoe.mark_board(1);
	tictactoe.mark_board(8); // X's turn
	REQUIRE(tictactoe.game_over() == (true));
	REQUIRE(tictactoe.get_winner() == "X"); 
}

TEST_CASE("Test win by third column", "3rd column winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(3); // X's turn
	tictactoe.mark_board(1);
	tictactoe.mark_board(6); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(9); // X's turn
	REQUIRE(tictactoe.game_over() == (true)); 
}

TEST_CASE("Test win by first row", "1st row winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(1); // X's turn
	tictactoe.mark_board(4);
	tictactoe.mark_board(2); // X's turn
	tictactoe.mark_board(7);
	tictactoe.mark_board(3); // X's turn
	REQUIRE(tictactoe.game_over() == (true)); 
	REQUIRE(tictactoe.get_winner() == "X"); 
}

TEST_CASE("Test win by second row", "2nd row winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(4); // X's turn
	tictactoe.mark_board(1);
	tictactoe.mark_board(5); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(6); // X's turn
	REQUIRE(tictactoe.game_over() == (true));
	REQUIRE(tictactoe.get_winner() == "X");  
}

TEST_CASE("Test win by third row", "3rd row winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(7); // X's turn
	tictactoe.mark_board(1);
	tictactoe.mark_board(8); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(9); // X's turn
	REQUIRE(tictactoe.game_over() == (true));
	REQUIRE(tictactoe.get_winner() == "X");  
} 

TEST_CASE("Test win diagonally from top left", "Top left diagonal winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(1); // X's turn
	tictactoe.mark_board(3);
	tictactoe.mark_board(5); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(9); // X's turn
	REQUIRE(tictactoe.game_over() == (true));
	REQUIRE(tictactoe.get_winner() == "X");  
}

TEST_CASE("Test win diagonally from bottom left", "Bottom left diagonal winner : X") 
{
	TicTacToe tictactoe;
	tictactoe.start_game("X");
	tictactoe.mark_board(7); // X's turn
	tictactoe.mark_board(1);
	tictactoe.mark_board(5); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(3); // X's turn
	REQUIRE(tictactoe.game_over() == (true));
	REQUIRE(tictactoe.get_winner() == "X");  
}

TEST_CASE("Test get_winner_total function from TicTacToe_Manager", "") 
{
	/*---------- GAME 1 ----------*/ 
	TicTacToe tictactoe;
	TicTacToeManager tictactoe_manager;
	int x_win;
	int o_win;
	int ties;
	
	tictactoe.start_game("X");
	tictactoe.mark_board(1); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(4); // X's turn
	tictactoe.mark_board(3);
	tictactoe.mark_board(7); // X's turn
	REQUIRE(tictactoe.game_over() == (true));

	tictactoe_manager.save_game(tictactoe); //saves game to vector
	tictactoe_manager.get_winner_total(x_win, o_win, ties); //tallys winner totals
	
	//Verify get_winner_total() contains correct tally
	REQUIRE(x_win == 1); // X win total: 1
	REQUIRE(o_win == 0); // O win total: 0
	REQUIRE(ties == 0); // Ties total: 0

	/*---------- GAME 2 ----------*/ 

	tictactoe.start_game("O");
	tictactoe.mark_board(1); // O's turn
	tictactoe.mark_board(3);
	tictactoe.mark_board(5); // O's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(9); // O's turn
	REQUIRE(tictactoe.game_over() == (true));

	tictactoe_manager.save_game(tictactoe); //saves game to vector
	tictactoe_manager.get_winner_total(x_win, o_win, ties); //tallys winner totals
	
	//Verify get_winner_total() contains correct tally
	REQUIRE(x_win == 1); // X win total: 1
	REQUIRE(o_win == 1); // O win total: 1 
	REQUIRE(ties == 0); // Ties total: 0


	/*---------- GAME 3 ----------*/ 
	tictactoe.start_game("X");
	tictactoe.mark_board(1); // X's turn
	tictactoe.mark_board(2); 
	tictactoe.mark_board(3); // X's turn
	tictactoe.mark_board(5);
	tictactoe.mark_board(4); // X's turn
	tictactoe.mark_board(6);
	tictactoe.mark_board(8); // X's turn
	tictactoe.mark_board(7);
	tictactoe.mark_board(9); // X's turn
	REQUIRE(tictactoe.game_over() == (true));

	tictactoe_manager.save_game(tictactoe); //saves game to vector
	tictactoe_manager.get_winner_total(x_win, o_win, ties); //tallys winner totals
	
	//Verify get_winner_total() contains correct tally
	REQUIRE(x_win == 1); // X win total: 1
	REQUIRE(o_win == 1); // O win total: 1 
	REQUIRE(ties == 1); // Ties total: 1


	/*---------- GAME 4 ----------*/ 
	
	tictactoe.start_game("X");
	tictactoe.mark_board(1); // X's turn
	tictactoe.mark_board(2);
	tictactoe.mark_board(4); // X's turn
	tictactoe.mark_board(3);
	tictactoe.mark_board(7); // X's turn
	REQUIRE(tictactoe.game_over() == (true));

	tictactoe_manager.save_game(tictactoe); //saves game to vector
	tictactoe_manager.get_winner_total(x_win, o_win, ties); //tallys winner totals
	
	//Verify get_winner_total() contains correct tally
	REQUIRE(x_win == 2); // X win total: 2
	REQUIRE(o_win == 1); // O win total: 1 
	REQUIRE(ties == 1); // Ties total: 1

} 