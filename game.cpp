#include "game.h"

void Game::initWindow()
{
	this->videoMode.width = 800;
	this->videoMode.height = 600;

	this->title = "Tic Tac Toe";

	this->window = new sf::RenderWindow(this->videoMode, this->title, sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
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


Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete this->window;
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

	// draw game objects

	this->window->display();
}
