//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::make_unique; using std::ifstream; using std::ofstream;
using std::unique_ptr; using std::vector;


void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{
    ofstream out_file;
    out_file.open(file_name);

    for(auto&game: games)
    {
        for(auto peg: game->get_pegs())
        {
            out_file<<peg;
        }

        out_file<<game->get_winner()<<"\n";
    }
}


vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    vector<unique_ptr<TicTacToe>> games;

    ifstream in_file;
    in_file.open(file_name);

    string line; 
    vector<string> pegs;
    
    while(getline(in_file, line))
    {
        for(int i=0; i<line.size() - 1; ++i)
        {
            pegs.push_back(string(1, line[i]));
        }
        string winner = pegs[pegs.size() - 1];
        unique_ptr<TicTacToe> game;

        if(pegs.size() == 9)
        {
            game = make_unique<TicTacToe_3>(pegs,winner);
        } 
        else if(pegs.size() == 16)
        {
            game = make_unique<TicTacToe_4>(pegs,winner);
        }

        games.push_back(std::move(game)); 
        pegs.clear();
        
    }
    return games;
}