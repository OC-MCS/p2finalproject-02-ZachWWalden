#include "Level.h"

Level::Level(int newDropRate, float newMoveSpeed, int levNum)
{
	dropRate = newDropRate;
	moveSpeed = newMoveSpeed;
	levelNumber = levNum;
}

int Level::getDropRate()
{
	return dropRate;
}

float Level::getMoveSpeed()
{
	return moveSpeed;
}

int Level::getLevelNumber()
{
	return levelNumber;
}
