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
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->title = "Tic Tac Toe";
}

void Game::initFont()
{
	
}

void Game::initText()
{

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
	this->window = new sf::RenderWindow(this->videoMode, this->title, sf::Style::Titlebar | sf::Style::Close);
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


void Game::renderGrid(sf::RenderTarget& target)
{
	for (int i = 0; i < 9; i++)
	{
		target.draw(grid[i].square);
	}
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
}

void Game::render()
{
	this->window->clear();

	this->renderGrid(*this->window);

	this->window->display();
}
