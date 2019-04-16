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
	Texture cortezTextOne, cortezTextTwo;
	list<OcasioCortez*> cortezList;
	Level* curLevel;
public:
// functions
private:
	void deleteOcasios();
public:
	CortezMGR(Level* newLevel);
	Texture &getTextOne();
	Texture &getTextTwo();
	void moveCortez();

	list<OcasioCortez*>* getCortezPtr();

	void setLevel(Level* newLevel);
	Level* getLevel();
	void initializeLevel(Level* newLevel);
};