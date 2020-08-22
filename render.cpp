#include "game.h"

void Game::render()
{
	// clear previous frame
	this->window->clear();

	// draw game objects
	this->renderGrid(*this->window);
	this->renderText(*this->window);

	// display at current frame
	this->window->display();
}

void Game::renderGrid(sf::RenderTarget& target)
{
	for (size_t i = 0; i < 9; i++)
	{
		target.draw(this->grid[i].space);
	}
	target.draw(this->restartButton.space);
}

void Game::renderText(sf::RenderTarget& target)
{
	for (size_t i = 0; i < 9; i++)
	{
		if (this->grid[i].mark != '\0')
		{
			target.draw(this->grid[i].markText);
		}
	}
	target.draw(this->promptText);
	target.draw(this->scoreText);
	target.draw(this->restartButton.buttonText);
}