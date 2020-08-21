#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
	// window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::String title;
	sf::Event event;

	// initialization functions
	void initWindow();

	// update functions
	void pollEvents();

public:
	Game();
	~Game();

	// game loop functions
	const bool running() const;
	void update();
	void render();
};