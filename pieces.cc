//***************************************************************************
// File:    pieces.cc - pieces class definitions
// Purpose: This is the pieces class definitions
// Author:  Sergio Gonzalez
// Date:    11/14/11
//***************************************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "pieces.h"

using namespace std;

pieces :: pieces()
{

}

void pieces :: set_white()
{
	piece = "W";
}

void pieces :: set_black()
{
	piece = "B";
}

void pieces :: set_empty()
{
	piece = " ";
}

bool pieces :: is_white() const
{
	if (piece == "W")
		return (1);
}

bool pieces :: is_black() const
{
	if (piece == "B")
		return (1);
}

bool pieces :: is_empty() const
{
	if (piece == " ")
		return (1);
}

string pieces :: show_piece() const
{
	return (piece);
}

void pieces :: flip()
{
	if (piece == "W")
		piece = "B";

	else if (piece == "B")
		piece = "W";

}







