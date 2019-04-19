/*========================================================
	Ran out of time disregard code.
==========================================================*/
#pragma once
#include "barrierMGR.h"

Barrier::Barrier(BarrierMGR *)
{
}

FloatRect Barrier::getGlobalBounds()
{
	return barrier.getGlobalBounds();
}

void Barrier::setTexture(Texture & newText)
{
	barrier.setTexture(newText);
}

void Barrier::setPosition(Vector2f newPos)
{
	barrier.setPosition(newPos);
}

void Barrier::draw(RenderWindow & win)
{
	win.draw(barrier);
}

void Barrier::incrementLives()
{
	livesUsed++;
}

int Barrier::getLives()
{
	return livesUsed;
}
