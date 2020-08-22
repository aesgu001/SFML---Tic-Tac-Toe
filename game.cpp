#include "game.h"

void Game::nextPlayer()
{
	if (this->mark_next_player == this->mark_player1)
		this->mark_next_player = this->mark_player2;
	else
		this->mark_next_player = this->mark_player1;
}

void Game::addWinnerScore()
{
	if (this->mark_next_player == this->mark_player1)
		this->score_player1 += 1;
	else
		this->score_player2 += 1;
}

void Game::restartGame()
{
	// reset all data except for player scores
	this->mark_next_player = this->mark_player1;
	for (size_t i = 0; i < 9; i++)
	{
		this->grid[i].space.setFillColor(sf::Color::Yellow);
		this->grid[i].space.setOutlineColor(sf::Color::Red);
		this->grid[i].mark = '\0';
	}
	this->gameOver = false;
	this->draw = false;
}

const bool Game::checkMatch(const char& current_player)
{
	if (horizontalMatch(current_player) || verticalMatch(current_player) || diagonalMatch(current_player))
		return true;
	else if (noMatch())
	{
		this->draw = true;
		return true;
	}
	else
		return false;
}

const bool Game::horizontalMatch(const char& current_player) 
{
	if (this->grid[0].mark == current_player && this->grid[1].mark == current_player && this->grid[2].mark == current_player)
	{
		this->grid[0].space.setFillColor(sf::Color::Green);
		this->grid[0].space.setOutlineColor(sf::Color::Cyan);

		this->grid[1].space.setFillColor(sf::Color::Green);
		this->grid[1].space.setOutlineColor(sf::Color::Cyan);

		this->grid[2].space.setFillColor(sf::Color::Green);
		this->grid[2].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else if (this->grid[3].mark == current_player && this->grid[4].mark == current_player && this->grid[5].mark == current_player)
	{
		this->grid[3].space.setFillColor(sf::Color::Green);
		this->grid[3].space.setOutlineColor(sf::Color::Cyan);

		this->grid[4].space.setFillColor(sf::Color::Green);
		this->grid[4].space.setOutlineColor(sf::Color::Cyan);

		this->grid[5].space.setFillColor(sf::Color::Green);
		this->grid[5].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else if (this->grid[6].mark == current_player && this->grid[7].mark == current_player && this->grid[8].mark == current_player)
	{
		this->grid[6].space.setFillColor(sf::Color::Green);
		this->grid[6].space.setOutlineColor(sf::Color::Cyan);

		this->grid[7].space.setFillColor(sf::Color::Green);
		this->grid[7].space.setOutlineColor(sf::Color::Cyan);

		this->grid[8].space.setFillColor(sf::Color::Green);
		this->grid[8].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else
		return false;
}

const bool Game::verticalMatch(const char& current_player) 
{
	if (this->grid[0].mark == current_player && this->grid[3].mark == current_player && this->grid[6].mark == current_player)
	{
		this->grid[0].space.setFillColor(sf::Color::Green);
		this->grid[0].space.setOutlineColor(sf::Color::Cyan);

		this->grid[3].space.setFillColor(sf::Color::Green);
		this->grid[3].space.setOutlineColor(sf::Color::Cyan);

		this->grid[6].space.setFillColor(sf::Color::Green);
		this->grid[6].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else if (this->grid[1].mark == current_player && this->grid[4].mark == current_player && this->grid[7].mark == current_player)
	{
		this->grid[1].space.setFillColor(sf::Color::Green);
		this->grid[1].space.setOutlineColor(sf::Color::Cyan);

		this->grid[4].space.setFillColor(sf::Color::Green);
		this->grid[4].space.setOutlineColor(sf::Color::Cyan);

		this->grid[7].space.setFillColor(sf::Color::Green);
		this->grid[7].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else if (this->grid[2].mark == current_player && this->grid[5].mark == current_player && this->grid[8].mark == current_player)
	{
		this->grid[2].space.setFillColor(sf::Color::Green);
		this->grid[2].space.setOutlineColor(sf::Color::Cyan);

		this->grid[5].space.setFillColor(sf::Color::Green);
		this->grid[5].space.setOutlineColor(sf::Color::Cyan);

		this->grid[8].space.setFillColor(sf::Color::Green);
		this->grid[8].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else
		return false;
}

const bool Game::diagonalMatch(const char& current_player) 
{
	if (this->grid[0].mark == current_player && this->grid[4].mark == current_player && this->grid[8].mark == current_player)
	{
		this->grid[0].space.setFillColor(sf::Color::Green);
		this->grid[0].space.setOutlineColor(sf::Color::Cyan);

		this->grid[4].space.setFillColor(sf::Color::Green);
		this->grid[4].space.setOutlineColor(sf::Color::Cyan);

		this->grid[8].space.setFillColor(sf::Color::Green);
		this->grid[8].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else if (this->grid[6].mark == current_player && this->grid[4].mark == current_player && this->grid[2].mark == current_player)
	{
		this->grid[6].space.setFillColor(sf::Color::Green);
		this->grid[6].space.setOutlineColor(sf::Color::Cyan);

		this->grid[4].space.setFillColor(sf::Color::Green);
		this->grid[4].space.setOutlineColor(sf::Color::Cyan);

		this->grid[2].space.setFillColor(sf::Color::Green);
		this->grid[2].space.setOutlineColor(sf::Color::Cyan);
		return true;
	}
	else
		return false;
}

const bool Game::noMatch() const
{
	for (size_t i = 0; i < 9; i++)
	{
		if (this->grid[i].mark == '\0')
			return false;
	}
	return true;
}


const bool Game::running() const
{
	return this->window->isOpen();
}
