//***************************************************************************
// File:    reversi.cc - reversi class definitions
// Purpose: This is the reversi class definitions
// Author:  Sergio Gonzalez
// Date:    11/14/11
//***************************************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
#include "game.h"
#include "colors.h"
#include "reversi.h"
#include "pieces.h"

using namespace main_savitch_14;


reversi :: reversi()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			board[row][col].set_empty();
		}
	}

	board[3][3].set_white();
	board[4][4].set_white();
	board[4][3].set_black();
	board[3][4].set_black();

	piece_count = 4;
}

void reversi :: restart()
{
	reversi();
}

void reversi :: display_status() const
{
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << WHITE << B_GREEN << "|     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |" << RESET << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  A  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][0].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  B  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][1].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  C  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][2].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  D  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][3].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  E  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][4].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  F  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][5].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  G  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][6].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
	cout << B_GREEN << WHITE << "|  H  |" << RESET;
		for (int row = 0; row < 8; row++)
		{
			cout << "  " << board[row][7].show_piece()<< "  |";
		}
	cout << endl;
	cout << B_GREEN << WHITE << "-------------------------------------------------------" << RESET <<endl;
}

bool reversi :: is_legal(const std::string& move) const
{
	int x, y;
	bool flag;

	x = (move[1]) - '1';
	y = toupper(move[0]) - 'A';

	if (get_moves() % 2 == 0)
	{
		flag = 0;

		if (x > 0)
		{
			if ((board[x - 1][y].is_white()) && (board[x][y].is_empty()))
			{
				for (int row = y; row >= 0; row--)
				{
					if (board[y][row].is_black())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x > 0) && (y > 0))
		{
			if ((board[x - 1][y - 1].is_white()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row >= 0) && (col >= 0); (row--) && (col--))
				{
					if (board[row][col].is_black())
					{
						flag = 1;
					}
				}
			}
		}
		if (y > 0)
		{
			if ((board[x][y - 1].is_white()) && (board[x][y].is_empty()))
			{
				for (int col = y; col >= 0; col--)
				{
					if (board[x][col].is_black())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x < 7) && (y > 0))
		{
			if ((board[x + 1][y - 1].is_white()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row < 8) && (col >= 0); (row++) && (col--))
				{
					if (board[row][col].is_black())
					{
						flag = 1;
					}
				}
			}
		}
		if (x < 7)
		{
			if ((board[x + 1][y].is_white()) && (board[x][y].is_empty()))
			{
				for (int row = x; row < 8; row++)
				{
					if (board[row][y].is_black())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x < 7) && (y < 7))
		{
			if ((board[x + 1][y + 1].is_white()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row < 8) && (col < 8); (row++) && (col++))
				{
					if (board[row][col].is_black())
					{
						flag = 1;
					}
				}
			}
		}
		if (y < 7)
		{
			if ((board[x][y + 1].is_white()) && (board[x][y].is_empty()))
			{
				for (int col = y; col < 8; col++)
				{
					if (board[x][col].is_black())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x > 0) && (y < 7))
		{
			if ((board[x - 1][y + 1].is_white()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row >= 0) && (col < 8); (row--) && (col++))
				{
					if (board[row][col].is_black())
					{
						flag = 1;
					}
				}
			}
		}

		return (flag);
	}

	else if (get_moves() % 2 == 1)
	{
		flag = 0;

		if (x > 0)
		{
			if ((board[x - 1][y].is_black()) && (board[x][y].is_empty()))
			{
				for (int row = y; row >= 0; row--)
				{
					if (board[y][row].is_white())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x > 0) && (y > 0))
		{
			if ((board[x - 1][y - 1].is_black()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row >= 0) && (col >= 0); (row--) && (col--))
				{
					if (board[row][col].is_white())
					{
						flag = 1;
					}
				}
			}
		}
		if (y > 0)
		{
			if ((board[x][y - 1].is_black()) && (board[x][y].is_empty()))
			{
				for (int col = y; col >= 0; col--)
				{
					if (board[x][col].is_white())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x < 7) && (y > 0))
		{
			if ((board[x + 1][y - 1].is_black()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row < 8) && (col >= 0); (row++) && (col--))
				{
					if (board[row][col].is_white())
					{
						flag = 1;
					}
				}
			}
		}
		if (x < 7)
		{
			if ((board[x + 1][y].is_black()) && (board[x][y].is_empty()))
			{
				for (int row = x; row < 8; row++)
				{
					if (board[row][y].is_white())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x < 7) && (y < 7))
		{
			if ((board[x + 1][y + 1].is_black()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row < 8) && (col < 8); (row++) && (col++))
				{
					if (board[row][col].is_white())
					{
						flag = 1;
					}
				}
			}
		}
		if (y < 7)
		{
			if ((board[x][y + 1].is_black()) && (board[x][y].is_empty()))
			{
				for (int col = y; col < 8; col++)
				{
					if (board[x][col].is_white())
					{
						flag = 1;
					}
				}
			}
		}
		if ((x > 0) && (y < 7))
		{
			if ((board[x - 1][y + 1].is_black()) && (board[x][y].is_empty()))
			{
				int row, col;
				for ((row = x) && (col = y); (row >= 0) && (col < 8); (row--) && (col++))
				{
					if (board[row][col].is_white())
					{
						flag = 1;
					}
				}
			}
		}

		return (flag);
	}
}

void reversi :: make_move(const std::string& move)
{
	int x, y;

	x = (move[1]) - '1';
	y = toupper(move[0]) - 'A';

	if (get_moves() % 2 == 0)
	{
		board[x][y].set_black();

		//traverses right across the cols
		for (int row = x; row < 8; row++)
		{
			if (board[row][y].is_black())
			{
				for (int a = x; a < row; a++)
				{
					board[a][y].set_black();
				}
			}
		}
		//left across cols
		for (int row = x; row >= 0; row--)
		{
			if (board[row][y].is_black())
			{
				for (int a = x; a > row; a--)
				{
					board[a][y].set_black();
				}
			}
		}
		//down the rows
		for (int col = y; col < 8; col++)
		{
			if (board[x][col].is_black())
			{
				for (int b = y; b < col; b++)
				{
					board[x][b].set_black();
				}
			}
		}
		//up the rows
		for (int col = y; col >= 0; col--)
		{
			if (board[x][col].is_black())
			{
				for (int b = y; b > col; b--)
				{
					board[x][b].set_black();
				}
			}
		}
		//down and right
		for (int row = x, col = y; row < 8 && col < 8; row++, col++)
		{
			if (board[row][col].is_black())
			{
				int a, b;
				for ((a = x) && (b = y); (a < row) && (b < col); (a++) && (b++))
				{
					board[a][b].set_black();
				}	
			}
		}
		//down and left
		for (int row = x, col = y; row < 8 && col >= 0; row++, col--)
		{
			if (board[row][col].is_black())
			{
				int a, b;
				for ((a = x) && (b = y); (a < row) && (b > col); (a++) && (b--))
				{
					board[a][b].set_black();
				}	
			}
		}
		//up and right
		for (int row = x, col = y; row >= 0 && col < 8; row--, col++)
		{
			int a, b;
			if (board[row][col].is_black())
			{
				for ((a = x) && (b = y); (a < row) && (b < col); (a--) && (b++))
				{
					board[a][b].set_black();
				}	
			}
		}
		//up and left
		for (int row = x, col = y; row >= 0 && col >= 0; row--, col--)
		{
			if (board[row][col].is_black())
			{
				int a, b;
				for ((a = x) && (b = y); (a > row) && (b > col); (a--) && (b--))
				{
					board[a][b].set_black();
				}	
			}
		}

		//board[x][y].set_black();
	}

	else if (get_moves() % 2 == 1)
	{
		board[x][y].set_white();
		//right across cols
		for (int row = x; row < 8; row++)
		{
			if (board[row][y].is_white())
			{
				for (int a = x; a < row; a++)
				{
					board[a][y].set_white();
				}
			}
		}		
		//left across cols	
		for (int row = x; row >= 0; row--)
		{
			if (board[row][y].is_white())
			{
				for (int a = x; a > row; a--)
				{
					board[a][y].set_white();
				}
			}
		}
		//down rows
		for (int col = y; col < 8; col++)
		{
			if (board[x][col].is_white())
			{
				for (int b = y; b < col; b++)
				{
					board[x][b].set_white();
				}
			}
		}
		//up rows
		for (int col = y; col >= 0; col--)
		{
			if (board[x][col].is_white())
			{
				for (int b = y; b > col; b--)
				{
					board[x][b].set_white();
				}
			}
		}
		//down and right
		for (int row = x, col = y; row < 8 && col < 8; row++, col++)
		{
			if (board[row][col].is_white())
			{
				int a, b;
				for ((a = x) && (b = y); (a < row) && (b < col); (a++) && (b++))
				{
					board[a][b].set_white();
				}	
			}
		}
		//down and left
		for (int row = x, col = y; row < 8 && col >= 0; row++, col--)
		{
			if (board[row][col].is_white())
			{
				int a, b;
				for ((a = x) && (b = y); (a < row) && (b > col); (a++) && (b--))
				{
					board[a][b].set_white();
				}	
			}
		}
		//up and right
		for (int row = x, col = y; row >= 0 && col < 8; row--, col++)
		{
			int a, b;
			if (board[row][col].is_white())
			{
				for ((a = x) && (b = y); (a < row) && (b < col); (a--) && (b++))
				{
					board[a][b].set_white();
				}	
			}
		}
		//up and left
		for (int row = x, col = y; row >= 0 && col >= 0; row--, col--)
		{
			if (board[row][col].is_white())
			{
				int a, b;
				for ((a = x) && (b = y); (a > row) && (b > col); (a--) && (b--))
				{
					board[a][b].set_white();
				}	
			}
		}

		//board[x][y].set_white();
	}

	moves++;
	game::make_move(move);
	piece_count++;

}

bool reversi :: is_game_over( ) const
{
	if (piece_count == 64 || get_skipped() == 2)
		return (1);
	else
		return (0);
}

void reversi :: compute_moves(std::queue<std::string>& moves) const
{
	string move = ("A1");

	for (char c = 'A'; c < 'I'; c++)
	{
		for (int r = 49; r < 57; r++)
		{
			if (is_legal(move))
			{
				moves.push(move);
			}

			move[0] = c;
			move[1] = r;
		}
	}
}

int reversi :: evaluate() const
{
	int b = 0;
	int w = 0;
	int x, y;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (board[x][y].is_black())
				b++;
			if (board[x][y].is_white())
				w++;
		}
	}
	//positive value good for computer
	return (w - b);
}

game* reversi :: clone( ) const
{
return new reversi(*this);
}

void reversi :: winning( )
{
	int value = evaluate();

	if (value > 0)
		cout << "The computer wins!" << endl << endl;
	else if (value < 0)
		cout << "You win!" << endl << endl;
	else
		cout << "It's a tie." << endl << endl;
}








