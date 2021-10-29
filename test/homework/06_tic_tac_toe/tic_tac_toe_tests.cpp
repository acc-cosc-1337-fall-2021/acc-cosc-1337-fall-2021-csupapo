#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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
	tictactoe.mark_board(5);
	REQUIRE(tictactoe.game_over() == (true)); 
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
	tictactoe.mark_board(9);
	REQUIRE(tictactoe.game_over() == (true)); 
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
	tictactoe.mark_board(4);
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
	tictactoe.mark_board(8);
	REQUIRE(tictactoe.game_over() == (true)); 
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
	tictactoe.mark_board(9);
	REQUIRE(tictactoe.game_over() == (true)); 
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
	tictactoe.mark_board(4);
	REQUIRE(tictactoe.game_over() == (true)); 
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
	tictactoe.mark_board(7);
	REQUIRE(tictactoe.game_over() == (true)); 
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
	tictactoe.mark_board(4);
	REQUIRE(tictactoe.game_over() == (true)); 
}