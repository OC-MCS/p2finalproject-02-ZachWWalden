#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class BarrierMGR;
/*========================================================
	Ran out of time disregard code.
==========================================================*/
class Barrier
{
// data
private:
	int livesUsed = 0;
	Sprite barrier;
public:
// functions
private:
public:
	Barrier(BarrierMGR*);
	FloatRect getGlobalBounds();
	void setTexture(Texture& newText);
	void setPosition(Vector2f);
	void draw(RenderWindow& win);
	void incrementLives();
	int getLives();

};