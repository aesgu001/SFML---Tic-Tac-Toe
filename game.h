#pragma once

#include "resources.h"

class Tile
{
private:
	sf::Font textFont;

public:
	sf::RectangleShape space;
	sf::Text markText;
	char mark;

	Tile();
	bool initTile(const std::string& fontFile);
};

class Button
{
private:
	sf::Font textFont;

public:
	sf::RectangleShape space;
	sf::Text buttonText;

	bool initButton(const std::string& fontFile);
};

class Game
{
private:
	// window
	sf::RenderWindow* window;
	sf::Vector2i windowSize;
	sf::String windowTitle;
	sf::Event event;

	// mouse
	sf::Vector2f mousePosition;
	bool mouseHeld;

	// resources
	sf::Font textFont;

	// texts
	sf::Text promptText;
	sf::Text scoreText;

	// game elements
	Tile* grid;
	Button restartButton;
	char mark_player1;
	char mark_player2;
	char mark_next_player;
	size_t score_player1;
	size_t score_player2;
	bool gameOver;
	bool draw;

	// game data checker
	bool gameDataLoaded;

	// game functions
	void nextPlayer();
	void addWinnerScore();
	void restartGame();
	const bool checkMatch(const char& current_player);
	const bool horizontalMatch(const char& current_player);
	const bool verticalMatch(const char& current_player);
	const bool diagonalMatch(const char& current_player);
	const bool noMatch() const;

	// initialization functions
	bool initData();
	void initWindow();
	void initMouse();
	bool initFont(const std::string& fontFile);
	void initText();
	bool initGameElements(const std::string& fontFile);

	// create functions
	void createWindow();
	void createText();
	void createGrid();
	void createButton();

	// update functions
	void pollEvents();
	void updateMousePosition();
	void updateMouseHover();
	void updateHoverRestart();
	void updateHoverGrid();
	void updateMouseInput();
	void updateInputRestart();
	void updateInputGrid();
	void updateText();

	// render functions
	void renderGrid(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);

public:
	Game();
	~Game();

	// public game functions
	const bool loaded() const;
	const bool running() const;
	void update();
	void render();
};