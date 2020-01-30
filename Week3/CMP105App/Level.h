#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.

	//first shape
	sf::RenderWindow* window;
	Input* input;
	sf::CircleShape circle;
	float circleSpeed;
	float circleDiameter;

	//second shape
	sf::CircleShape secondCircle;
	float secondCircleSpeedX;
	float secondCircleSpeedY;
	float secondCircleDiameter;
	
};