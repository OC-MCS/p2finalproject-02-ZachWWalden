#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

enum CortexEnum { NORMAL, BOMBING, DEAD };

class CortezMGR;

class OcasioCortez
{
// data
private:
	Sprite cortez;
	Texture cortezTexture;
	int animationCount = 0;
	CortezMGR *mgrPtr;
	CortexEnum state = NORMAL;
public:
// functions
private:
	void handleAnimation();
public:
	OcasioCortez(CortezMGR *, Vector2f);
	void draw(RenderWindow &win);
	

};
