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
	Texture cortezTextOne, cortezTextTwo, cortezTextThree;
	list<OcasioCortez*> cortezList;
	ProjectileMGR* protMgrPtr;
public:
// functions
private:
public:
	CortezMGR();
	void addProjectile();
	Texture &getTextOne();
	Texture &getTextTwo();
	Texture &getTextThree();

	list<OcasioCortez*>* getCortezPtr();

};