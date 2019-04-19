#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
using namespace std;
#include "ProjectileMGR.h"
#include "OcasioCortez.h"



class CortezMGR
{
// data
private:
	// Enemy textures
	Texture cortezTextOne, cortezTextTwo;
	//list of enemies
	list<OcasioCortez*> cortezList;
	//pointer to the current level
	Level* curLevel;
	// pointer the the game manager
	GameMgr* gameMGR;
public:
// functions
private:
	// see implementation file for detailed explanation
	void deleteOcasios();
public:
	// see implementation file for detailed explanation
	CortezMGR(Level* newLevel, GameMgr* mgr);
	// see implementation file for detailed explanation
	Texture &getTextOne();
	// see implementation file for detailed explanation
	Texture &getTextTwo();
	// see implementation file for detailed explanation
	void moveCortez();
	// see implementation file for detailed explanation
	list<OcasioCortez*>* getCortezPtr();
	// see implementation file for detailed explanation
	void setLevel(Level* newLevel);
	// see implementation file for detailed explanation
	Level* getLevel();
	// see implementation file for detailed explanation
	void initializeLevel(Level* newLevel);
};