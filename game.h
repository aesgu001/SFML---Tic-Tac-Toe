#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

struct Space
{
	sf::RectangleShape square;
	sf::Font markTextFont;
	sf::Text markText;
	char mark;
	Space();
};

class Game
{
private:
	// window
	sf::RenderWindow* window;
	sf::Vector2i window2D;
	sf::String title;
	sf::Event event;

	// mouse
	sf::Vector2f mousePosition;
	bool mouseHeld;

	// resources
	sf::Font textFont;

	// texts
	sf::Text promptText;
	sf::Text scoreText;
	sf::Text restartText;

	// game objects
	Space* grid;
	sf::RectangleShape restartButton;
	char mk_player1;
	char mk_player2;
	char mk_current_player;
	size_t score_player1;
	size_t score_player2;
	bool gameOver;
	bool tie;

	// game functions
	void changeCurrentPlayer();
	void changePlayerScore();
	void restartGame();
	const bool checkMatch(const char& current_player);
	const bool horizontalMatch(const char& current_player) const;
	const bool verticalMatch(const char& current_player) const;
	const bool diagonalMatch(const char& current_player) const;
	const bool noMatch() const;

	// initialization functions
	void initData();
	void initWindow();
	void initMouse();
	void initFont();
	void initText();
	void initGameObjects();
	void createWindow();
	void createGrid();

	// update functions
	void pollEvents();
	void updateMousePosition();
	void updateRestart();
	void updateGrid();
	void updateText();

	// render functions
	void renderGrid(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);

public:
	Game();
	~Game();

	// game loop functions
	const bool running() const;
	void update();
	void render();
};