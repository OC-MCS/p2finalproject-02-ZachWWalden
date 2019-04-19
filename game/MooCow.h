#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;

struct WindowBounds
{
	float xRadius;
	float xWindow;
};


class MooCow
{
// data
private:
	// Sprite for display the player controlled cow
	Sprite cow;
	// texture of the cow
	Texture cowTexture;
	// holds the size of the window
	WindowBounds bounds;
public:
//functions
private:
public:
	// see implementation file for detailed explanation
	MooCow(RenderWindow &win);
	// see implementation file for detailed explanation
	void moveCow();
	// see implementation file for detailed explanation
	void draw(RenderWindow &win);
	// see implementation file for detailed explanation
	Vector2f getPos();
	// see implementation file for detailed explanation
	FloatRect getGlobalBounds();
	
};