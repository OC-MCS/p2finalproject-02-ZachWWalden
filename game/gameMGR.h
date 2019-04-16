#pragma once
#include "Level.h"
#include <list>
using namespace std;
enum GameStateEnum{INPROGRESS, PAUSED, STARTUP, OVER, RESESTNOW};
class GameMgr
{
// data
private:
	list<Level*> levelList;
	list<Level*>::iterator levelIter;
	GameStateEnum gameState;
	int livesLeft = 3;
public:

// functions
private:
public:
	GameMgr(GameStateEnum);
	void setGameState(GameStateEnum);
	GameStateEnum getCurState();
	void addLevel(Level *newLevel);
	Level* getCurLevel();
	void decrementLives();
	int getLives();
	void incrementLevel();
	void resetLevel();

};