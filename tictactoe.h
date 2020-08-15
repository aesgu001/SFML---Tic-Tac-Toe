#pragma once

#include <vector>
#include <iostream>

class Tictactoe
{
private:
	std::vector<std::vector<char> > board;
	char player1;
	char player2;
	bool tieGame;

	const bool horizontalMatch(const char& player) const;
	const bool verticalMatch(const char& player) const;
	const bool diagonalMatch(const char& player) const;
	const bool noMatch();

public:
	Tictactoe();

	void initBoard();
	void initPlayers();

	const char getNextPlayer(const char& currentPlayer) const;
	const bool setPlayerPos(const char& player, const size_t& pos);
	const bool gameOver(const char& player);
	const bool getTieGame() const;

	void displayBoard();
};