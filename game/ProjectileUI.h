#pragma once
#include "ProjectileMGR.h"

class ProjectileUI
{
// data
private:
	// pointer for access to projectile list for drawing
	ProjectileMGR* mgrPtr;
public:
// functions
private:
public:
	// see implementation file for detailed explanation
	ProjectileUI();
	// see implementation file for detailed explanation
	ProjectileUI(ProjectileMGR* mgr);
	// see implementation file for detailed explanation
	void draw(RenderWindow& win);
};