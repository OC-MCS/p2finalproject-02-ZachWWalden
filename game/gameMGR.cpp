#pragma once
#include "gameMGR.h"

/*===================================================================
	GameMgr - Constructor, intializes game state, level data, and level iterator
	Parameters: GameStateEnum newState - the default game state
	Return Type:
=====================================================================*/
GameMgr::GameMgr(GameStateEnum newState)
{
	// intialize game state
	gameState = newState;
	// initialize levels
	Level* harbertLevel = new Level(1000L, .1f, 0, 2);
	Level* levelOne = new Level(500L, .3f, 1, 4);
	Level* levelTwo = new Level(340L, .5f,2, 6);
	Level* levelThree = new Level(200L,.9f,3, 10);
	// add levels to the list
	addLevel(harbertLevel);
	addLevel(levelOne);
	addLevel(levelTwo);
	addLevel(levelThree);
	//intialize the level iterator
	levelIter = levelList.begin();
}
/*===================================================================
	setGameState - sets the game state to the passed game state
	Parameters:	GameStateEnum newState - new game state
	Return Type: void
=====================================================================*/
void GameMgr::setGameState(GameStateEnum newState)
{
	// set new state
	gameState = newState;
}
/*===================================================================
	getCurState - gets the current state
	Parameters: none
	Return Type: GameStateEnum
=====================================================================*/
GameStateEnum GameMgr::getCurState()
{
	// return current state
	return gameState;
}
/*===================================================================
	addLevel - adds a level to the back of the level list 
	Parameters: Level* newLevel - pointer to the new level
	Return Type: void
=====================================================================*/
void GameMgr::addLevel(Level * newLevel)
{
	// add new level to the list
	levelList.push_back(newLevel);
}
/*===================================================================
	getCurLevel - gets a pointer to the current level
	Parameters: none
	Return Type: Level*
=====================================================================*/
Level * GameMgr::getCurLevel()
{
	// return current level
	return (*levelIter);
}
/*===================================================================
	decrementLives - decrements lives
	Parameters: none
	Return Type: void
=====================================================================*/
void GameMgr::decrementLives()
{
	// decrement lives
	livesLeft--;
	// if the number of lives left is zero, set the game state to over
	if (livesLeft == 0)
		//set game state to over
		gameState = OVER;
}
/*===================================================================
	getLives - returns the number of lives left
	Parameters: none
	Return Type: int
=====================================================================*/
int GameMgr::getLives()
{
	return livesLeft;
}
/*===================================================================
	incrementLevel - increments level iterator to the next level in the level list
	Parameters: none
	Return Type: void
=====================================================================*/
void GameMgr::incrementLevel()
{
	// increment if iterator is not at the end of the list
	if(levelIter != levelList.end())
		levelIter++;
}
/*===================================================================
	incrementLives - increment the number of lives
	Parameters: none
	Return Type: void
=====================================================================*/
void GameMgr::incrementLives()
{
	// increment lives
	livesLeft++;
}
/*===================================================================
	resetlevel - if the game state is over, reset the level list to the beginning
	Parameters: none
	Return Type: void
=====================================================================*/
void GameMgr::resetLevel()
{
	// check game state
	if (gameState == OVER)
	{
		//reset lives
		livesLeft = 3;
		// reset iterator to the beginnign of the list
		levelIter = levelList.begin();
	}
}
/*===================================================================
	handleScore - handle the player's score
	Parameters: none
	Return Type: void
=====================================================================*/
void GameMgr::handleScore()
{
	score += 1 * getCurLevel()->getPoints();
}
/*===================================================================
	getScore - returns the total score
	Parameters: none
	Return Type: int
=====================================================================*/
int GameMgr::getScore()
{
	return score;
}
/*===================================================================
	resetScore - resets the score
	Parameters: none
	Return Type: int
=====================================================================*/
void GameMgr::resetScore()
{
	// reset the score
	score = 0;
}