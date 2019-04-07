#pragma once
#include "ProjectileMGR.h"

class ProjectileUI
{
// data
private:
	ProjectileMGR* mgrPtr;
public:
// functions
private:
public:
	ProjectileUI();
	ProjectileUI(ProjectileMGR* mgr);
	void draw(RenderWindow& win);
};