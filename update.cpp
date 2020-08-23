#include "game.h"

void Game::update()
{
	pollEvents();

	updateMousePosition();
	
	updateMouseHover();

	updateMouseInput();

	updateText();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void Game::updateMousePosition()
{
	this->mousePosition = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Game::updateMouseHover()
{
	updateHoverRestart();
	if (!this->gameOver)
		updateHoverGrid();
}

void Game::updateHoverRestart()
{
	// add transparency to button if hovered
	if (this->restartButton.space.getGlobalBounds().contains(this->mousePosition))
	{
		sf::Color transparentColor = BUTTON_COLOR;
		transparentColor.a = static_cast<sf::Uint8>(transparentColor.a * 0.75f);
		sf::Color transparentOutlineColor = BUTTON_OUTLINE;
		transparentOutlineColor.a = static_cast<sf::Uint8>(transparentOutlineColor.a * 0.75f);

		this->restartButton.space.setFillColor(transparentColor);
		this->restartButton.space.setOutlineColor(transparentOutlineColor);
	}
	else
	{
		this->restartButton.space.setFillColor(BUTTON_COLOR);
		this->restartButton.space.setOutlineColor(BUTTON_OUTLINE);
	}
}

void Game::updateHoverGrid()
{
	// add transparency to unmarked tile if hovered
	for (size_t i = 0; i < 9; i++)
	{
		if (this->grid[i].space.getGlobalBounds().contains(this->mousePosition)
			&& this->grid[i].mark == '\0')
		{
			sf::Color transparentColor = TILE_COLOR;
			transparentColor.a = static_cast<sf::Uint8>(transparentColor.a * 0.75f);
			sf::Color transparentOutlineColor = TILE_OUTLINE;
			transparentOutlineColor.a = static_cast<sf::Uint8>(transparentOutlineColor.a * 0.75f);

			this->grid[i].space.setFillColor(transparentColor);
			this->grid[i].space.setOutlineColor(transparentOutlineColor);
		}
		else
		{
			this->grid[i].space.setFillColor(TILE_COLOR);
			this->grid[i].space.setOutlineColor(TILE_OUTLINE);
		}
	}
}

void Game::updateMouseInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->mouseHeld)
		{
			this->mouseHeld = true;
			updateInputRestart();
			if (!this->gameOver)
				updateInputGrid();
		}
	}
	else
		this->mouseHeld = false;
}

void Game::updateInputRestart()
{
	if (this->restartButton.space.getGlobalBounds().contains(this->mousePosition))
		restartGame();
}

void Game::updateInputGrid()
{
	bool gridUpdated = false;
	for (size_t i = 0; i < 9 && !gridUpdated; i++)
	{
		if (this->grid[i].space.getGlobalBounds().contains(this->mousePosition)
			&& this->grid[i].mark == '\0')
		{
			gridUpdated = true;
			this->grid[i].mark = mark_next_player;
			this->grid[i].space.setFillColor(TILE_COLOR);
			this->grid[i].space.setOutlineColor(TILE_OUTLINE);
			if (checkMatch(mark_next_player))
			{
				this->gameOver = true;
				if (!draw)
					addWinnerScore();
			}
			else
				nextPlayer();
		}
	}
}

void Game::updateText()
{
	std::stringstream textS; // stream gets flushed after each text element

	// write corresponding marks on each marked tile
	for (size_t i = 0; i < 9; i++)
	{
		textS << this->grid[i].mark;
		this->grid[i].markText.setString(textS.str());
		textS.clear();
		textS.str(std::string());
	}

	// write game condition at prompt text
	if (this->gameOver)
	{
		if (this->draw)
			textS << "It's a DRAW" << std::endl;
		else
			textS << "Player " << mark_next_player << " WINS" << std::endl;
	}
	else
		textS << "Player " << this->mark_next_player << "'s Turn" << std::endl;
	this->promptText.setString(textS.str());
	textS.clear();
	textS.str(std::string());

	// write player scores
	textS << "Player " << this->mark_player1 << "'s score: " << this->score_player1 << std::endl
		<< "Player " << this->mark_player2 << "'s score: " << this->score_player2 << std::endl;
	this->scoreText.setString(textS.str());
	textS.clear();
	textS.str(std::string());

	// label restart button
	textS << "RESTART" << std::endl;
	this->restartButton.buttonText.setString(textS.str());
	textS.clear();
	textS.str(std::string());
}