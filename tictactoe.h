#pragma once

#include <vector>
#include <iostream>

class Tictactoe
{
private:
	std::vector<std::vector<char> > board;
	char player1;
	char player2;

public:
	Tictactoe();

	void initBoard();
	void initPlayers();
	void displayBoard();
};