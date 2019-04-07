#pragma once
#include "Level.h"

#include <SFML/Graphics.hpp>
using namespace sf;

enum CortexEnum { NORMAL, BOMBING, DEAD };

class CortezMGR;

class OcasioCortez
{
// data
private:
	Sprite cortez;
	int animationCount = 40;
	CortezMGR *mgrPtr;
	CortexEnum state = NORMAL;
public:
// functions
private:
	void handleAnimation();
public:
	OcasioCortez(CortezMGR *, Vector2f);
	void draw(RenderWindow &win);
	FloatRect getGlobalBounds();
	void setState(CortexEnum);
	Vector2f getPosition();
	void setPosition(Vector2f newPos);
	

};
