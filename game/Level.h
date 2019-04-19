#pragma once

class Level
{
// data
private:
	// relative enemy drop rate for bombs
	int dropRate;
	// movespeed for enemies
	float moveSpeed;
	// number to characterize what level this is
	int levelNumber;
	// number of points given for killing each enemy
	int points;
public:

// functions
private:
public:
	// see implementation file for detailed explanation
	Level(int, float, int, int);
	// see implementation file for detailed explanation
	int getDropRate();
	// see implementation file for detailed explanation
	float getMoveSpeed();
	// see implementation file for detailed explanation
	int getLevelNumber();
	// see implementation file for detailed explanation
	int getPoints();

};