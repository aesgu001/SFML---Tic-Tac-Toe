#include "tictactoe.h"

const bool Tictactoe::horizontalMatch(const char& player) const
{
	return (this->board[0][0] == player && this->board[0][1] == player && this->board[0][2] == player)
		|| (this->board[1][0] == player && this->board[1][1] == player && this->board[1][2] == player)
		|| (this->board[2][0] == player && this->board[2][1] == player && this->board[2][2] == player);
}

const bool Tictactoe::verticalMatch(const char& player) const
{
	return (this->board[0][0] == player && this->board[1][0] == player && this->board[2][0] == player)
		|| (this->board[0][1] == player && this->board[1][1] == player && this->board[2][1] == player)
		|| (this->board[0][2] == player && this->board[1][2] == player && this->board[2][2] == player);
}

const bool Tictactoe::diagonalMatch(const char& player) const
{
	return (this->board[0][0] == player && this->board[1][1] == player && this->board[2][2] == player)
		|| (this->board[2][0] == player && this->board[1][1] == player && this->board[0][2] == player);
}

const bool Tictactoe::noMatch()
{
	for (size_t i = 0; i < this->board.size(); i++)
	{
		for (size_t j = 0; j < this->board[i].size(); j++)
		{
			if (this->board[i][j] == static_cast<char>(49 + (i * 3) + j))
				return false;
		}
	}

	this->tieGame = true;
	return true;
}


Tictactoe::Tictactoe()
{
	initBoard();
	initPlayers();
	this->tieGame = false;
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


const char Tictactoe::getNextPlayer(const char& currentPlayer) const
{
	if (currentPlayer == '\0' || currentPlayer == this->player2)
		return this->player1;

	else
		return this->player2;
}

const bool Tictactoe::setPlayerPos(const char& player, const size_t& pos)
{
	if (pos < 1 || pos > 9)
	{
		std::cout << "Invalid position!" << std::endl << std::endl;
		return false;
	}

	size_t boardPosI = (pos - 1) / 3;
	size_t boardPosJ = (pos - 1) % 3;
	if (this->board[boardPosI][boardPosJ] == this->player1
		|| this->board[boardPosI][boardPosJ] == this->player2)
	{
		std::cout << "Position already taken!" << std::endl << std::endl;
		return false;
	}
	else
	{
		this->board[boardPosI][boardPosJ] = player;
		std::cout << std::endl << std::endl;
		return true;
	}
}

const bool Tictactoe::gameOver(const char& player)
{
	return (horizontalMatch(player)
		|| verticalMatch(player)
		|| diagonalMatch(player)) || noMatch();
}

const bool Tictactoe::getTieGame() const
{
	return this->tieGame;
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

	std::cout << std::endl;
}
