#include "board.h"

Tile::Tile()
{
	this->mark = '\0';

	this->square.setSize(sf::Vector2f(100.f, 100.f));
	this->square.setOutlineColor(sf::Color::Red);
	this->square.setOutlineThickness(5.f);
	this->square.setFillColor(sf::Color::Yellow);
}


Board::Board()
{
	this->tiles = new Tile[9];
	this->mk_player1 = 'X';
	this->mk_player2 = 'O';
}

Board::~Board()
{
	delete[] this->tiles;
}
