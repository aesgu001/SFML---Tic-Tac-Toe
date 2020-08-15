#include "tictactoe.h"

Tictactoe::Tictactoe()
{
	initBoard();
}

void Tictactoe::initBoard()
{
	for (int i = 0; i < 3; i++)
	{
		this->board.push_back(std::vector<char>(3));

		for (int j = 0; j < this->board[i].size(); j++)
		{
			this->board[i][j] = static_cast<char>(49 + (i * 3) + j);
		}
	}
}

void Tictactoe::displayBoard()
{
	for (int i = 0; i < this->board.size(); i++)
	{
		for (int j = 0; j < this->board[i].size(); j++)
		{
			std::cout << this->board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
