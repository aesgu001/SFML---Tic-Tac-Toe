#pragma once

#include <SFML/Graphics.hpp>

class Tile
{
private:
	char mark;
	sf::RectangleShape square;

public:
	Tile();
};

class Board
{
private:
	Tile* tiles;
	char mk_player1;
	char mk_player2;

public:
	Board();
	~Board();
};