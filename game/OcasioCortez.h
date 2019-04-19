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
	// sprite for displaying enemy
	Sprite cortez;
	// counter for animating the bomb drop sequence
	int animationCount = 40;
	// pointer to access textures stored in the manager
	CortezMGR *mgrPtr;
	// keeps track of the state of this enemy
	CortexEnum state = NORMAL;
public:
// functions
private:
	// see implementation file for detailed explanation
	void handleAnimation();
public:
	// see implementation file for detailed explanation
	OcasioCortez(CortezMGR *, Vector2f);
	// see implementation file for detailed explanation
	void draw(RenderWindow &win);
	// see implementation file for detailed explanation
	FloatRect getGlobalBounds();
	// see implementation file for detailed explanation
	void setState(CortexEnum);
	// see implementation file for detailed explanation
	Vector2f getPosition();
	// see implementation file for detailed explanation
	void setPosition(Vector2f newPos);
	

};