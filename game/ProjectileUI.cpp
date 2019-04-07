#include "ProjectileUI.h"

ProjectileUI::ProjectileUI()
{
}

ProjectileUI::ProjectileUI(ProjectileMGR* mgr)
{
	mgrPtr = mgr;
}

void ProjectileUI::draw(RenderWindow & win)
{
	list<Projectile*>* listPtr = mgrPtr->getProjPtr();
	list<Projectile*>::iterator iter;
	for (iter = listPtr->begin(); iter != listPtr->end(); iter++)
	{
		(*iter)->draw(win);
	}
	mgrPtr->moveProjectiles();
}
