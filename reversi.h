//***************************************************************************
// File:    reversi.h - reversi class declarations
// Purpose: This is the reversi class declarations
// Author:  Sergio Gonzalez
// Date:    11/14/11
//***************************************************************************
#include "game.h"
#include <string>
#include <queue>
#include "pieces.h"
#include "colors.h"
#ifndef REVERSI_H
#define REVERSI_H

using namespace main_savitch_14;

class reversi : public game
{
  public:
	reversi();
	virtual void display_status() const;
	virtual void restart();
	virtual void make_move(const std::string& move);
	virtual bool is_legal(const std::string& move) const;
	virtual bool is_game_over( ) const;
	virtual int evaluate( ) const;
	virtual void compute_moves(std::queue<std::string>& moves) const;
	virtual game* clone( ) const;
	int get_moves() const { return (moves); }
    	void winning( );


  private:
	pieces board[8][8];
	int moves;
	int piece_count;
};
#endif
