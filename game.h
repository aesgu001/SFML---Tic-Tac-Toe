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
	sf::Font scoreTextFont;

	// texts
	sf::Text promptText;
	sf::Text scoreText;

	// game objects
	Space* grid;
	char mk_player1;
	char mk_player2;
	char mk_current_player;
	size_t score_player1;
	size_t score_player2;

	// game functions
	void changeCurrentPlayer(const char& current_player);

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