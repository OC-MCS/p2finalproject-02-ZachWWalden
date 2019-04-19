#pragma once
#include "Level.h"
#include <list>
using namespace std;
enum GameStateEnum{INPROGRESS, PAUSED, STARTUP, OVER, NEXTLEVEL};
class GameMgr
{
// data
private:
	//list of levels
	list<Level*> levelList;
	//iterator for level list
	list<Level*>::iterator levelIter;
	//current game state
	GameStateEnum gameState;
	// lives left
	int livesLeft = 3;
	//score
	int score = 0;
public:

// functions
private:
public:
	// see implementation file for detailed explanation
	GameMgr(GameStateEnum);
	// see implementation file for detailed explanation
	void setGameState(GameStateEnum);
	// see implementation file for detailed explanation
	GameStateEnum getCurState();
	// see implementation file for detailed explanation
	void addLevel(Level *newLevel);
	// see implementation file for detailed explanation
	Level* getCurLevel();
	// see implementation file for detailed explanation
	void decrementLives();
	// see implementation file for detailed explanation
	int getLives();
	// see implementation file for detailed explanation
	void incrementLevel();
	// see implementation file for detailed explanation
	void incrementLives();
	// see implementation file for detailed explanation
	void resetLevel();
	// see implementation file for detailed explanation
	void handleScore();
	// see implemntation file for detailed explanation
	int getScore();
	// see implemntation file for detailed explanation
	void resetScore();

};