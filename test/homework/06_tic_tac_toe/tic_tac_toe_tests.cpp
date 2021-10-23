#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Game Over Function", "verification") 
{
	TicTacToe tictactoe;
	string first_player = "X";
	tictactoe.start_game(first_player);
	tictactoe.mark_board(1);
	REQUIRE(tictactoe.game_over() == (true)); 

	tictactoe.mark_board(2);
	REQUIRE(tictactoe.game_over() == (true));

	tictactoe.mark_board(3);
	REQUIRE(tictactoe.game_over() == (true)); 

	tictactoe.mark_board(4);
	REQUIRE(tictactoe.game_over() == (true));

	tictactoe.mark_board(5);
	REQUIRE(tictactoe.game_over() == (true)); 

	tictactoe.mark_board(6);
	REQUIRE(tictactoe.game_over() == (true)); 

	tictactoe.mark_board(7);
	REQUIRE(tictactoe.game_over() == (true)); 

	tictactoe.mark_board(8);
	REQUIRE(tictactoe.game_over() == (true)); 

	tictactoe.mark_board(9);
	REQUIRE(tictactoe.game_over() == (false)); 

}