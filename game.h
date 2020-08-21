#pragma once

// #include "board.h"

#include <SFML/Graphics.hpp>

class Game
{
private:
	// window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::String title;
	sf::Event event;

	void initWindow();

	void pollEvents();

public:
	Game();
	~Game();

	const bool running() const;

	void update();
	void render();
};