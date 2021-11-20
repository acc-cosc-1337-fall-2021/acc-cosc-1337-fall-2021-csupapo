#include <string>
#include <vector>
#include <math.h>
#include <iostream>



#ifndef TICTACTOE_H
#define TICTACTOE_H


using std::string; using std::vector; using std::ostream; using std::istream;



class TicTacToe
{
public:
    TicTacToe(){}
    TicTacToe(int size) : pegs(size * size, " "){}
    TicTacToe(vector<string> p, string win) : pegs(p), winner(win){};
    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const; 
    string get_winner() const;
    vector<string> get_pegs() const{return pegs;}
    friend ostream& operator<<(ostream& out, const TicTacToe& tictactoe);
    friend istream& operator>>(istream& in, TicTacToe& tictactoe);

protected:
    vector<string> pegs; 
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private: 
    string player;
    string winner;
    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner();

};

#endif

//Free Functions
bool exit_validation(char exit_prompt);
string player_validation(string &prompt);