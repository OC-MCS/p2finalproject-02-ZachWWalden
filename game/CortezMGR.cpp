#include "CortezMGR.h"

CortezMGR::CortezMGR(Level* newLevel)
{
	if (!cortezTextOne.loadFromFile("cortez_texture_one.png"))
	{
		// error
	}
	if (!cortezTextTwo.loadFromFile("cortez_texture_two.png"))
	{
		// error
	}
	curLevel = newLevel;

	OcasioCortez* ptr;
	//intialize list of cortez enemies
	for (int i = 0; i < 10; i++)
	{
		ptr = new OcasioCortez(this, Vector2f(i * 80.0f, 50.0f));
		cortezList.push_back(ptr);
	}
}

Texture &CortezMGR::getTextOne()
{
	return cortezTextOne;
}

Texture &CortezMGR::getTextTwo()
{
	return cortezTextTwo;
}

void CortezMGR::moveCortez()
{
	Vector2f newPos;
	list<OcasioCortez*>::iterator iter;
	for (iter = cortezList.begin(); iter != cortezList.end(); iter++)
	{
		newPos = (*iter)->getPosition();
		newPos.y += curLevel->getMoveSpeed();
		(*iter)->setPosition(newPos);
	}
}

list<OcasioCortez*>* CortezMGR::getCortezPtr()
{
	return &cortezList;
}

void CortezMGR::setLevel(Level* newLevel)
{
	curLevel = newLevel;
}

Level * CortezMGR::getLevel()
{
	return curLevel;
}
