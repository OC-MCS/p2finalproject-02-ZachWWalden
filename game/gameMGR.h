#pragma once
#include "Level.h"
#include <list>
using namespace std;
enum GameStateEnum{INPROGRESS, PAUSED, STARTUP};
class GameMgr
{
// data
private:
	list<Level*> levelList;
	int currentLevel = 1;
	GameStateEnum gameState = STARTUP;
public:

// functions
private:
public:
	GameMgr();

};