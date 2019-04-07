#pragma once
#include "CortezMGR.h"

class CortezUI
{
// data
public:
private:
	CortezMGR* mgrPtr;
// functions
public:
	CortezUI(CortezMGR *MGR);
	void draw(RenderWindow& win);

private:
};