#include "game.h"

Tile::Tile()
{
	// init mark
	this->mark = '\0';
}

bool Tile::initTile(const std::string& fontFile)
{
	// load font file
	if (!this->textFont.loadFromFile(fontFile))
	{
		std::cerr << "ERROR: Tile::initTile: Failed to load " << fontFile << "!" << std::endl;
		return false;
	}

	// init mark text
	this->markText.setFont(this->textFont);
	this->markText.setCharacterSize(100);
	this->markText.setFillColor(sf::Color::Black);
	this->markText.setString("");

	// init space
	this->space.setSize(sf::Vector2f(100.f, 100.f));
	this->space.setFillColor(TILE_COLOR);
	this->space.setOutlineColor(TILE_OUTLINE);
	this->space.setOutlineThickness(5.f);

	return true;
}


bool Button::initButton(const std::string& fontFile)
{
	// load font file
	if (!this->textFont.loadFromFile(fontFile))
	{
		std::cerr << "ERROR: Button::initButton: Failed to load " << fontFile << "!" << std::endl;
		return false;
	}

	// init button text
	this->buttonText.setFont(this->textFont);
	this->buttonText.setCharacterSize(30);
	this->buttonText.setFillColor(sf::Color::Black);
	this->buttonText.setString("");

	// init space
	this->space.setSize(sf::Vector2f(150.f, 50.f));
	this->space.setFillColor(BUTTON_COLOR);
	this->space.setOutlineColor(BUTTON_OUTLINE);
	this->space.setOutlineThickness(5.f);

	return true;
}


Game::Game()
{
	if (!initData())
	{
		this->gameDataLoaded = false;
		return;
	}
	createWindow();
	createText();
	createGrid();
	createButton();

	this->gameDataLoaded = true;
}

Game::~Game()
{
	delete this->window;
	delete[] this->grid;
}

bool Game::initData()
{
	// window
	initWindow();

	// mouse
	initMouse();

	// resources
	if (!initFont(FONT_FILE))
		return false;

	// text
	initText();

	// game elements
	if (!initGameElements(FONT_FILE))
		return false;

	return true;
}

void Game::initWindow()
{
	// initialize window variables
	this->window = nullptr;
	this->windowSize = sf::Vector2i(800, 600);
	this->windowTitle = "Tic Tac Toe";
}

void Game::initMouse()
{
	this->mouseHeld = false;
}

bool Game::initFont(const std::string& fontFile)
{
	// font for score and prompt texts
	if (!this->textFont.loadFromFile(fontFile))
	{
		std::cerr << "ERROR: Game::initFont: Failed to load " << fontFile << "!" << std::endl;
		return false;
	}
	return true;
}

void Game::initText()
{
	// init prompt text
	this->promptText.setFont(this->textFont);
	this->promptText.setCharacterSize(30);
	this->promptText.setFillColor(sf::Color::White);
	this->promptText.setString("");

	// init score text
	this->scoreText.setFont(this->textFont);
	this->scoreText.setCharacterSize(30);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setString("");
}

bool Game::initGameElements(const std::string& fontFile)
{
	// initialize each new tile
	this->grid = new Tile[9];
	for (int i = 0; i < 9; i++)
	{
		if (!this->grid[i].initTile(fontFile))
			return false;
	}

	// initialize restart button
	if (!this->restartButton.initButton(fontFile))
		return false;

	// player 1 will always take first turn
	this->mark_player1 = 'X';
	this->mark_player2 = 'O';
	this->mark_next_player = this->mark_player1;

	// reset player scores to zero
	this->score_player1 = 0;
	this->score_player2 = 0;

	// game over if a match is found or if all tiles are marked
	this->gameOver = false;
	this->draw = false;

	return true;
}


void Game::createWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(this->windowSize.x, this->windowSize.y),
		this->windowTitle, sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::createText()
{
	// prompt text
	this->promptText.setPosition(30.f, 30.f);

	// score text
	this->scoreText.setPosition(this->windowSize.x - 270.f, 30.f);
}

void Game::createGrid()
{
	// create a 3x3 grid
	for (size_t i = 0; i < 9; i++)
	{
		sf::Vector2f spaceSize = grid[i].space.getSize();
		grid[i].space.setPosition(spaceSize.x + ((i % 3) * (spaceSize.x + 10.f)), spaceSize.y + ((i / 3) * (spaceSize.y + 10.f)));
		grid[i].markText.setPosition(spaceSize.x + 25 + ((i % 3) * (spaceSize.x + 10.f)),
			spaceSize.y - 15 + ((i / 3) * (spaceSize.y + 10.f)));
	}
}

void Game::createButton()
{
	this->restartButton.space.setPosition(this->windowSize.x - 260.f, 330.f);
	this->restartButton.buttonText.setPosition(this->windowSize.x - 240.f, 335.f);
}


const bool Game::loaded() const
{
	return this->gameDataLoaded;
}