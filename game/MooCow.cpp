#include "MooCow.h"

MooCow::MooCow(RenderWindow &win)
{
	if (!cowTexture.loadFromFile("cow_text.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}

	cow.setTexture(cowTexture);

	cow.setPosition(Vector2f(400.0f, 500.0f));

	bounds.xWindow = win.getSize().x;
	bounds.xRadius = 20.0f;
}

void MooCow::moveCow()
{
	Vector2f cowPos = cow.getPosition();
	const float DISTANCE = 5.0;
	
	if (cowPos.x < 0)
	{
		cowPos.x = 0;
		cow.setPosition(cowPos);
	}
	else if (cowPos.x > (bounds.xWindow - (2.0f * bounds.xRadius)))
	{
		cowPos.x = bounds.xWindow - (2.0f * bounds.xRadius) - 1.0f;
		cow.setPosition(cowPos);
	}

	

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		cow.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		cow.move(DISTANCE, 0);
	}
}

void MooCow::draw(RenderWindow & win)
{
	win.draw(cow);
}

Vector2f MooCow::getPos()
{
	return cow.getPosition();
}

FloatRect MooCow::getGlobalBounds()
{
	return cow.getGlobalBounds();
}
