#pragma once
#include "MooCow.h"

/*===================================================================
	MooCow - Constructor, loads cow texture from the file, intializes cow sprite, and stores the window size
	Parameters: RenderWindow &win - reference to the render window
	Return Type: none
=====================================================================*/
MooCow::MooCow(RenderWindow &win)
{
	// load cow texture
	if (!cowTexture.loadFromFile("cow_text.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// set the cow texture
	cow.setTexture(cowTexture);
	//set the cow's position
	cow.setPosition(Vector2f(400.0f, 500.0f));
	// initialize the size of the window, and width of the cow
	bounds.xWindow = win.getSize().x;
	bounds.xRadius = 20.0f;
}
/*===================================================================
	moveCow - moves the cow based on user input
	Parameters: none
	Return Type: void
=====================================================================*/
void MooCow::moveCow()
{
	// stores the new position of the cow, initializes it to the current  position of the cow
	Vector2f cowPos = cow.getPosition();
	// float for cow move speed
	const float DISTANCE = 10.0;
	// check is the cow has gone off the left side of the screen
	if (cowPos.x < 0)
	{
		// reset the cow's x coordinate to zero
		cowPos.x = 0;
		// reset the cow's position
		cow.setPosition(cowPos);
	}
	// check if the cow is off of the right side of the window
	else if (cowPos.x > (bounds.xWindow - (2.0f * bounds.xRadius)))
	{
		// reset the cow's x coordinate to bbe back within the window
		cowPos.x = bounds.xWindow - (2.0f * bounds.xRadius) - 1.0f;
		// set the new position
		cow.setPosition(cowPos);
	}

	
	// if the left arrow key was pressed, move the cow left
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
/*===================================================================
	draw - draws the cow on the screen
	Parameters: RenderWindow & win - reference to the render window
	Return Type: void
=====================================================================*/
void MooCow::draw(RenderWindow & win)
{
	win.draw(cow);
}
/*===================================================================
	getPos - wrapper around the Sprite class's getPosition function
	Parameters: none
	Return Type: Vector2f
=====================================================================*/
Vector2f MooCow::getPos()
{
	// return the position of the internal sprite
	return cow.getPosition();
}
/*===================================================================
	getGlobalBounds - wrapper around the sprite class' getGlobalBounds function
	Parameters: none
	Return Type: FloatRect
=====================================================================*/
FloatRect MooCow::getGlobalBounds()
{
	return cow.getGlobalBounds();
}