#pragma once
#include "ProjectileUI.h"

/*===================================================================
	ProjectileUI, default constructor
	Parameters: none
	Return Type: none
=====================================================================*/
ProjectileUI::ProjectileUI()
{
}
/*===================================================================
	ProjectileUI - Constructor, intializes pointer to the projectile manager for drawing purposes
	Parameters: ProjectileMGR* mgr - pointer to the projectile manager
	Return Type: none
=====================================================================*/
ProjectileUI::ProjectileUI(ProjectileMGR* mgr)
{
	// initialize manager pointer
	mgrPtr = mgr;
}
/*===================================================================
	draw - render the projectiles in the game window
	Parameters: RenderWindow & win - refeerence to the render window
	Return Type: void
=====================================================================*/
void ProjectileUI::draw(RenderWindow & win)
{
	// intialize projectile list pointer
	list<Projectile*>* listPtr = mgrPtr->getProjPtr();
	// create iterator to run through the projectile loop
	list<Projectile*>::iterator iter;
	//loop throught the projectiles
	for (iter = listPtr->begin(); iter != listPtr->end(); iter++)
	{
		//d draw the current projectile
		(*iter)->draw(win);
	}
	// move the projectiles
	mgrPtr->moveProjectiles();
}