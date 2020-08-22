#include "game.h"

Space::Space()
{
	this->mark = '\0';

	if (!this->markTextFont.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cerr << "ERROR::GAME::INITFONT: Failed to load font!" << std::endl;
	}
	this->markText.setFont(this->markTextFont);
	this->markText.setCharacterSize(100);
	this->markText.setFillColor(sf::Color::Black);
	this->markText.setString("");

	this->square.setSize(sf::Vector2f(100.f, 100.f));
	this->square.setOutlineColor(sf::Color::Red);
	this->square.setOutlineThickness(5.f);
	this->square.setFillColor(sf::Color::Yellow);
}


void Game::changeCurrentPlayer()
{
	if (this->mk_current_player == this->mk_player1)
		this->mk_current_player = mk_player2;
	else
		this->mk_current_player = mk_player1;
}

void Game::changePlayerScore()
{
	if (this->mk_current_player == mk_player1)
		this->score_player1 += 1;
	else
		this->score_player2 += 1;
}

const bool Game::checkMatch(const char& current_player)
{
	if (horizontalMatch(current_player) || verticalMatch(current_player) || diagonalMatch(current_player))
		return true;
	else if (noMatch())
	{
		this->tie = true;
		return true;
	}
	else
		return false;
}

const bool Game::horizontalMatch(const char& current_player) const
{
	return (this->grid[0].mark == current_player && this->grid[1].mark == current_player && this->grid[2].mark == current_player)
		|| (this->grid[3].mark == current_player && this->grid[4].mark == current_player && this->grid[5].mark == current_player)
		|| (this->grid[6].mark == current_player && this->grid[7].mark == current_player && this->grid[8].mark == current_player);
}

const bool Game::verticalMatch(const char& current_player) const
{
	return (this->grid[0].mark == current_player && this->grid[3].mark == current_player && this->grid[6].mark == current_player)
		|| (this->grid[1].mark == current_player && this->grid[4].mark == current_player && this->grid[7].mark == current_player)
		|| (this->grid[2].mark == current_player && this->grid[5].mark == current_player && this->grid[8].mark == current_player);
}

const bool Game::diagonalMatch(const char& current_player) const
{
	return (this->grid[0].mark == current_player && this->grid[4].mark == current_player && this->grid[8].mark == current_player)
		|| (this->grid[6].mark == current_player && this->grid[4].mark == current_player && this->grid[2].mark == current_player);
}

const bool Game::noMatch() const
{
	for (int i = 0; i < 9; i++)
	{
		if (this->grid[i].mark == '\0')
			return false;
	}
	return true;
}


void Game::initData()
{
	// window
	initWindow();

	// mouse
	initMouse();

	// resources
	initFont();

	// text
	initText();

	// game objects
	initGameObjects();
}

void Game::initWindow()
{
	this->window = nullptr;
	this->window2D = sf::Vector2i(800, 600);
	this->title = "Tic Tac Toe";
}

void Game::initMouse()
{
	this->mouseHeld = false;
}

void Game::initFont()
{
	if (!this->scoreTextFont.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cerr << "ERROR::GAME::INITFONT: Failed to load font!" << std::endl;
	}
}

void Game::initText()
{
	// prompt text
	this->promptText.setFont(this->scoreTextFont);
	this->promptText.setCharacterSize(30);
	this->promptText.setPosition(30.f, 30.f);
	this->promptText.setFillColor(sf::Color::White);
	this->promptText.setString("NONE");

	// score text
	this->scoreText.setFont(this->scoreTextFont);
	this->scoreText.setCharacterSize(30);
	this->scoreText.setPosition(this->window2D.x - 270.f, 30.f);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setString("NONE");
}

void Game::initGameObjects()
{
	this->grid = new Space[9];
	this->mk_player1 = 'X';
	this->mk_player2 = 'O';
	this->mk_current_player = mk_player1;
	this->score_player1 = 0;
	this->score_player2 = 0;
	this->gameOver = false;
	this->tie = false;
}

void Game::createWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(this->window2D.x, this->window2D.y),
		this->title, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::createGrid()
{
	for (int i = 0; i < 9; i++)
	{
		sf::Vector2f squareSize = grid[i].square.getSize();
		grid[i].markText.setPosition(squareSize.x + 24 + ((i % 3) * squareSize.x), squareSize.y - 15 + ((i / 3) * squareSize.y));
		grid[i].square.setPosition(squareSize.x + ((i % 3) * squareSize.x), squareSize.y + ((i / 3) * squareSize.y));
	}
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

void Game::updateGrid()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->mouseHeld)
		{
			this->mouseHeld = true;
			bool playerSet = false;
			for (int i = 0; i < 9 && !playerSet; i++)
			{
				if (this->grid[i].square.getGlobalBounds().contains(this->mousePosition)
					&& this->grid[i].mark == '\0')
				{
					playerSet = true;
					this->grid[i].mark = mk_current_player;
					if (checkMatch(mk_current_player))
					{
						this->gameOver = true;
						if (!tie)
							changePlayerScore();
					}
					else
						changeCurrentPlayer();
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game::updateText()
{
	for (int i = 0; i < 9; i++)
	{
		if (this->grid[i].mark != '\0')
		{
			std::stringstream markS;
			markS << this->grid[i].mark;
			this->grid[i].markText.setString(markS.str());
		}
	}

	std::stringstream promptS;
	if (this->gameOver)
	{
		if (this->tie)
			promptS << "It's a DRAW" << std::endl;
		else
			promptS << "Player " << mk_current_player << " WINS" << std::endl;
	}
	else
		promptS << "Player " << this->mk_current_player << "'s Turn" << std::endl;
	this->promptText.setString(promptS.str());

	std::stringstream scoreS;
	scoreS << "Player " << this->mk_player1 << "'s score: " << this->score_player1 << std::endl
		<< "Player " << this->mk_player2 << "'s score: " << this->score_player2 << std::endl;
	this->scoreText.setString(scoreS.str());
}


void Game::renderGrid(sf::RenderTarget& target)
{
	for (int i = 0; i < 9; i++)
	{
		target.draw(grid[i].square);
	}
}

void Game::renderText(sf::RenderTarget& target)
{
	for (int i = 0; i < 9; i++)
	{
		if (this->grid[i].mark != '\0')
		{
			target.draw(this->grid[i].markText);
		}
	}
	target.draw(this->promptText);
	target.draw(this->scoreText);
}


Game::Game()
{
	initData();
	createWindow();
	createGrid();
}

Game::~Game()
{
	delete this->window;
	delete[] this->grid;
}


const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::update()
{
	pollEvents();

	updateMousePosition();

	if (!this->gameOver)
	{
		updateGrid();
		updateText();
	}
}

void Game::render()
{
	this->window->clear();

	this->renderGrid(*this->window);
	this->renderText(*this->window);

	this->window->display();
}
