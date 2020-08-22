#pragma once

#include <SFML/Graphics.hpp>

struct Space
{
	sf::RectangleShape square;
	char mark;
	Space();
};

class Game
{
private:
	// window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::String title;
	sf::Event event;

	// game objects
	Space* grid;
	char mk_player1;
	char mk_player2;

	// initialization functions
	void initData();
	void initWindow();
	void initGameObjects();
	void createWindow();
	void createGrid();

	// update functions
	void pollEvents();

	// render functions
	void renderGrid(sf::RenderTarget& target);

public:
	Game();
	~Game();

	// game loop functions
	const bool running() const;
	void update();
	void render();
};