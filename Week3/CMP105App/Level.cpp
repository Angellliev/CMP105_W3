#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	//first circle
	circle.setRadius(50);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(0, 300);
	circleSpeed = 500.f;
	circleDiameter = circle.getRadius() * 2;

	//second circle
	secondCircle.setRadius(30);
	secondCircle.setFillColor(sf::Color::Yellow);
	secondCircle.setPosition(0, 0);
	secondCircleSpeedX = 250.f;
	secondCircleSpeedY = 250.f;
	secondCircleDiameter = secondCircle.getRadius() * 2;

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

{//first circle movement
	circle.move(circleSpeed * dt, 0);
	if (circle.getPosition().x  < 0)
	{
		circleSpeed = fabs(circleSpeed);
	}
	
	else if (circle.getPosition().x + circleDiameter > window->getSize().x)
	{
		circle.setPosition(window->getSize().x - circleDiameter, circle.getPosition().y );
		circleSpeed *= -1;
	}

	//second circle movement
	secondCircle.move(secondCircleSpeedX * dt, secondCircleSpeedY * dt);
		if (secondCircle.getPosition().x < 0)
		{
			secondCircleSpeedX = fabs(secondCircleSpeedX);
		}

		else if (secondCircle.getPosition().x + secondCircleDiameter > window->getSize().x)
		{
			secondCircle.setPosition(window->getSize().x - secondCircleDiameter, secondCircle.getPosition().y);
			secondCircleSpeedX *= -1;
		}

		if (secondCircle.getPosition().y  < 0)
		{
			secondCircleSpeedY = fabs(secondCircleSpeedY);
		}

		else if (secondCircle.getPosition().y + secondCircleDiameter > window->getSize().y)
		{
			secondCircleSpeedX = fabs(secondCircleSpeedX);
			secondCircleSpeedY *= -1;
		}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(secondCircle);
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