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
	Sprite cow;
	Texture cowTexture;
	WindowBounds bounds;
public:
//functions
private:
public:
	MooCow(RenderWindow &win);
	void moveCow();
	void draw(RenderWindow &win);
	Vector2f getPos();
	FloatRect getGlobalBounds();
	
};