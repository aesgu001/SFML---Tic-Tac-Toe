#pragma once

#include <vector>
#include <iostream>

class Tictactoe
{
private:
	std::vector<std::vector<char> > board;

public:
	Tictactoe();

	void initBoard();
	void displayBoard();
};