#pragma once
#include "CortezMGR.h"

class CortezUI
{
// data
public:
private:
	// pointer for acess to enemy list
	CortezMGR* mgrPtr;
// functions
public:
	// see implementation file for detailed explanation
	CortezUI(CortezMGR *MGR);
	// see implementation file for detailed explanation
	void draw(RenderWindow& win);

private:
};