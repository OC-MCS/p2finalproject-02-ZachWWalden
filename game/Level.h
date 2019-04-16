#pragma once

class Level
{
// data
private:
	int dropRate;
	float moveSpeed;
	int levelNumber;
public:

// functions
private:
public:
	Level(int, float, int);
	int getDropRate();
	float getMoveSpeed();
	int getLevelNumber();

};