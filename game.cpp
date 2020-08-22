#include "game.h"

Space::Space()
{
	this->mark = '\0';
	this->square.setSize(sf::Vector2f(100.f, 100.f));
	this->square.setOutlineColor(sf::Color::Red);
	this->square.setOutlineThickness(5.f);
	this->square.setFillColor(sf::Color::Yellow);
}


void Game::initData()
{
	// window
	initWindow();

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

void Game::initFont()
{
	if (!this->scoreTextFont.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cerr << "ERROR::GAME::INITFONT: Failed to load font!" << std::endl;
	}
}

void Game::initText()
{
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
	this->score_player1 = 0;
	this->score_player2 = 0;
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

void Game::updateText()
{
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

	updateText();
}

void Game::render()
{
	this->window->clear();

	this->renderGrid(*this->window);
	this->renderText(*this->window);

	this->window->display();
}
