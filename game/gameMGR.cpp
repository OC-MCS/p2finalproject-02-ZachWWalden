#include "gameMGR.h"

GameMgr::GameMgr(GameStateEnum newState)
{
	gameState = newState;

	Level* harbertLevel = new Level(1000L, .1f, 0);
	Level* levelOne = new Level(300L, .5f, 1);
	Level* levelTwo = new Level(200L, .8f,2);
	Level* levelThree = new Level(200L,1.2f,3);

	addLevel(harbertLevel);
	addLevel(levelOne);
	addLevel(levelTwo);
	addLevel(levelThree);

	levelIter = levelList.begin();
}

void GameMgr::setGameState(GameStateEnum newState)
{
	gameState = newState;
}

GameStateEnum GameMgr::getCurState()
{
	return gameState;
}

void GameMgr::addLevel(Level * newLevel)
{
	levelList.push_back(newLevel);
}

Level * GameMgr::getCurLevel()
{
	return (*levelIter);
}

void GameMgr::decrementLives()
{
	livesLeft--;
	if (livesLeft == 0)
		gameState = OVER;
}

int GameMgr::getLives()
{
	return livesLeft;
}

void GameMgr::incrementLevel()
{
	if(levelIter != levelList.end())
		levelIter++;
}

void GameMgr::resetLevel()
{
	if(gameState == OVER)
		livesLeft = 3;
	if((*levelIter)->getLevelNumber() == 3 && gameState == OVER)
		levelIter = levelList.begin();
}
