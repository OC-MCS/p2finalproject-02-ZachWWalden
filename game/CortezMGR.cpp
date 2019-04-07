#include "CortezMGR.h"

CortezMGR::CortezMGR()
{
	if (!cortezTextOne.loadFromFile("cortez_texture_one.png"))
	{
		// error
	}
	if (!cortezTextTwo.loadFromFile("cortez_texture_two.png"))
	{
		// error
	}
	if (!cortezTextThree.loadFromFile("cortez_texture_three.png"))
	{
		// error
	}

	OcasioCortez* ptr;
	//intialize list of cortez enemies
	for (int i = 0; i < 10; i++)
	{
		ptr = new OcasioCortez(this, Vector2f(i * 80.0f, 50.0f));
		cortezList.push_back(ptr);
	}
}

void CortezMGR::addProjectile()
{
}

Texture &CortezMGR::getTextOne()
{
	return cortezTextOne;
}

Texture &CortezMGR::getTextTwo()
{
	return cortezTextTwo;
}

Texture &CortezMGR::getTextThree()
{
	return cortezTextThree;
}

list<OcasioCortez*>* CortezMGR::getCortezPtr()
{
	return &cortezList;
}
