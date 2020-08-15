#include "tictactoe.h"

Tictactoe::Tictactoe()
{
	initBoard();
	initPlayers();
}

void Tictactoe::initBoard()
{
	for (size_t i = 0; i < 3; i++)
	{
		this->board.push_back(std::vector<char>(3));

		for (size_t j = 0; j < this->board[i].size(); j++)
		{
			this->board[i][j] = static_cast<char>(49 + (i * 3) + j);
		}
	}
}

void Tictactoe::initPlayers()
{
	this->player1 = 'X';
	this->player2 = 'O';
}

void Tictactoe::displayBoard()
{
	for (size_t i = 0; i < this->board.size(); i++)
	{
		for (size_t j = 0; j < this->board[i].size(); j++)
		{
			std::cout << " " << this->board[i][j];

			if (j + 1 < this->board[i].size())
				std::cout << " |";
		}
		std::cout << std::endl;

		if (i + 1 < this->board.size())
			std::cout << "-----------" << std::endl;
	}
}
