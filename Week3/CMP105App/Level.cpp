#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(50);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(0, 300);
	circleSpeed = 500.f;
	circleDiameter = circle.getRadius() * 2;
	

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)

{
	circle.move(circleSpeed * dt, 0);
	if (circle.getPosition().x  < 0)
	{
		circleSpeed = fabs(circleSpeed);
	}
	
	else if (circle.getPosition().x + circleDiameter > window->getSize().x)
	{
		circleSpeed *= -1;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}