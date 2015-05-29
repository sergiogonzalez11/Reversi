//***************************************************************************
// File:    reversi.h - reversiclass declarations
// Purpose: This is the reversi class declarations
// Author:  Sergio Gonzalez
// Date:    11/14/11
//***************************************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#ifndef PIECES_H
#define PIECES_H

using namespace std;

class pieces
{
  public:
	pieces();
	void set_white();
	void set_black();
	void set_empty();
	bool is_white() const;
	bool is_black() const;
	bool is_empty() const;
	void flip();
	string show_piece() const;
	

  private:
	string piece;
};

#endif
