#pragma once
#include "Level.h"

/*===================================================================
	Level - Constructor, intializes drop rate, move speed, which level it is, and the point value
	Parameters: int newDropRate - drop rate
				float newMoveSpeed - movement speed
				int levNum - level identifier
				int pointValue - point value
	Return Type: none
=====================================================================*/
Level::Level(int newDropRate, float newMoveSpeed, int levNum, int pointValue)
{
	dropRate = newDropRate;
	moveSpeed = newMoveSpeed;
	levelNumber = levNum;
	points = pointValue;
}
/*===================================================================
	getDropRate - returns the drop rate for enemy projectiels
	Parameters: none
	Return Type: int
=====================================================================*/
int Level::getDropRate()
{
	return dropRate;
}
/*===================================================================
	getMoveSpeed - returns the movements speed for the enemies
	Parameters: none
	Return Type: float
=====================================================================*/
float Level::getMoveSpeed()
{
	return moveSpeed;
}
/*===================================================================
	getLevelNumber - returns the level number
	Parameters: none
	Return Type: int
=====================================================================*/
int Level::getLevelNumber()
{
	return levelNumber;
}
/*===================================================================
	getPoints - get the number of points received for killing one enemy
	Parameters: none
	Return Type: int
=====================================================================*/
int Level::getPoints()
{
	return points;
}