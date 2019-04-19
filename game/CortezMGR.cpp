#pragma once
#include "CortezMGR.h"

/*===================================================================
	CortezMGR - Constructor, loads in textures, initializes game manager pointer, and initializes the first level
	Parameters:	Level* newLevel - pointer to the current level
				GameMgr* mgr - pointer to the game manager
=====================================================================*/
CortezMGR::CortezMGR(Level* newLevel, GameMgr* mgr)
{
	if (!cortezTextOne.loadFromFile("cortez_texture_one.png"))
	{
		// error
	}
	if (!cortezTextTwo.loadFromFile("cortez_texture_two.png"))
	{
		// error
	}
	gameMGR = mgr;
	initializeLevel(newLevel);
}
/*===================================================================
	getTextOne - returns a reference to the standard enemy texture
	Parameters: none
	Return Type: Texture&
=====================================================================*/
Texture &CortezMGR::getTextOne()
{
	return cortezTextOne;
}
/*===================================================================
	getTextTwo - returns a reference to bombing texture for the enemy
	Parameters: none
	Return Type: Texture&
=====================================================================*/
Texture &CortezMGR::getTextTwo()
{
	return cortezTextTwo;
}
/*===================================================================
	moveCortez - moves the enemies down the screen toward the player.
	Parameters: none
	Return Type: void
=====================================================================*/
void CortezMGR::moveCortez()
{
	// stores the new position for 
	Vector2f newPos;
	// flag for is the enemies reach the level of the player
	bool bottomOut = false;
	// list iterator for iterating trought the list of enemies
	list<OcasioCortez*>::iterator iter;
	// This loop runs through the list of enemies and moves eac one down the screen, if and only if they have not reached the level of the player
	for (iter = cortezList.begin(); !bottomOut && iter != cortezList.end();)
	{
		//sets newPos equal to the current position of the current enemy
		newPos = (*iter)->getPosition();
		// increments the current ememy's y coordinate by its movement speed
		newPos.y += curLevel->getMoveSpeed();
		// sets the position of the current enemy to the incremented position
		(*iter)->setPosition(newPos);
		// checks to see if one of the enemies has reached the level of the player
		if (newPos.y > 430.0f)
		{
			// resets the level
			initializeLevel(curLevel);
			// decrement lives count 
			gameMGR->decrementLives();
			// set flag for if the ememies reached the player
			bottomOut = true;
		}
		// if the enemies are not at the level of the player, increment the list iterator
		else
			// increment iterator
			iter++;
	}
}
/*===================================================================
	getCortezPointer - returns a pointer to the list of enemies
	Parameters: none
	Return Type: list<OcasioCortez*>*
=====================================================================*/
list<OcasioCortez*>* CortezMGR::getCortezPtr()
{
	return &cortezList;
}
/*===================================================================
	setLevel - sets the current level in the emeny manager class
	Parameters: Level* newLevel - pointer to the new level
	Return Type: void
=====================================================================*/
void CortezMGR::setLevel(Level* newLevel)
{
	curLevel = newLevel;
}
/*===================================================================
	getLevel - gets a pointer to the current level
	Parameters: none
	Return Type: Level*
=====================================================================*/
Level * CortezMGR::getLevel()
{
	return curLevel;
}
/*===================================================================
	initializeLevel - intializes enemies to their starting locations
	Parameters: Level* newLevel - pointer to the new level
	Return Type: void
=====================================================================*/
void CortezMGR::initializeLevel(Level* newLevel)
{
	curLevel = newLevel;

	deleteOcasios();

	OcasioCortez* ptr;
	//intialize list of cortez enemies
	for (int i = 0; i < 10; i++)
	{
		ptr = new OcasioCortez(this, Vector2f(i * 80.0f, 90.0f));
		cortezList.push_back(ptr);
	}
}
/*===================================================================
	deleteOcasios - deletes all enemies in the list of enemies
	Parameters: none
	Return Type: void
=====================================================================*/
void CortezMGR::deleteOcasios()
{
	list<OcasioCortez*>::iterator iter;
	for (iter = cortezList.begin(); iter != cortezList.end();)
	{
		delete (*iter);
		iter = cortezList.erase(iter);
	}
}