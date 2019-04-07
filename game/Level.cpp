#include "Level.h"

Level::Level(int newDropRate, float newMoveSpeed)
{
	dropRate = newDropRate;
	moveSpeed = newMoveSpeed;
}

int Level::getDropRate()
{
	return dropRate;
}

float Level::getMoveSpeed()
{
	return moveSpeed;
}
