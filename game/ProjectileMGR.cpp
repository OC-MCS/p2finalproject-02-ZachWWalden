#include "ProjectileMGR.h"
#include "CortezMGR.h"

void ProjectileMGR::handleBombing()
{
	Vector2f newBombPos;
	list<OcasioCortez*>* listPtr = cortezMgr->getCortezPtr();
	list<OcasioCortez*>::iterator cortezIter;
	list<OcasioCortez*>::iterator cortezEND = listPtr->end();
	for (cortezIter = listPtr->begin(); cortezIter != cortezEND; cortezIter++)
	{
		if (((rand() %  curLevel->getDropRate()) + 1) == 57L)
		{
			newBombPos = (*cortezIter)->getPosition();
			(*cortezIter)->setState(BOMBING);
			newBombPos.x += 25.0f;
			newBombPos.y += 35.0f;
			addProjectile(newBombPos, COMMUNISTTURD);
		}
	}

}

ProjectileMGR::ProjectileMGR(CortezMGR* cortezPtr)
{
	if (!cowFart.loadFromFile("cow_fart.png"))
	{
		// error
	}
	if (!communistTurd.loadFromFile("communist_turd.png"))
	{
		// error
	}
	srand(time(0));
	cortezMgr = cortezPtr;
	curLevel = cortezMgr->getLevel();
}

void ProjectileMGR::addProjectile(Vector2f startPos, ProjectileEnum protType)
{
	if (protType == COWFART)
	{
		CowFart* c = new CowFart(startPos, cowFart, protType);
		projectileList.push_back(c);
	}
	else
	{
		CommunistTurd* c = new CommunistTurd(startPos, communistTurd, protType);
		projectileList.push_back(c);
	}
}

void ProjectileMGR::checkCollision(MooCow& cow)
{
	bool deleted = false;
	bool protlistEmpty = false;
	list<Projectile*>::iterator iter;
	list<Projectile*>::iterator iterEND = projectileList.end();

	for (iter = projectileList.begin(); iter != iterEND;)
	{
		Vector2f newPos = (*iter)->getPos();
		if ((*iter)->getProtType() == COMMUNISTTURD)
		{
			if (cow.getGlobalBounds().intersects((*iter)->getGlobalBounds()))
			{
				delete (*iter);
				iter = projectileList.erase(iter);
				deleted = true;
			}
		}
		else 
		{
			list<OcasioCortez*>* listPtr = cortezMgr->getCortezPtr();
			list<OcasioCortez*>::iterator cortezIter;
			list<OcasioCortez*>::iterator cortezEND = listPtr->end();
			for (cortezIter = listPtr->begin(); cortezIter != cortezEND && !protlistEmpty;)
			{
				if ((*cortezIter)->getGlobalBounds().intersects((*iter)->getGlobalBounds()))
				{
					delete (*iter);
					iter = projectileList.erase(iter);

					if (iter == iterEND)
						protlistEmpty = true;

					delete (*cortezIter);
					cortezIter = listPtr->erase(cortezIter);
					deleted = true;
				}
				if (!deleted)
					cortezIter++;
				deleted = false;
			}
		}
		if (!deleted && !protlistEmpty)
			iter++;
		deleted = false;

	}
}

list<Projectile*>* ProjectileMGR::getProjPtr()
{
	return &projectileList;
}

void ProjectileMGR::moveProjectiles()
{
	bool deleted = false;
	list<Projectile*>::iterator iter;
	for (iter = projectileList.begin(); iter != projectileList.end();)
	{
		Vector2f newPos = (*iter)->getPos();
		if ((*iter)->getProtType() == COWFART)
		{
			newPos.y -= 10.0f;
			(*iter)->setPos(newPos);
			if (newPos.y < -30.0f)
			{
				delete (*iter);
				iter = projectileList.erase(iter);
				deleted = true;
			}
		}
		else
		{
			newPos.y += 2.0f;
			(*iter)->setPos(newPos);
			if (newPos.y > 630.0f)
			{
				delete (*iter);
				iter = projectileList.erase(iter);
				deleted = true;
			}
		}
		if (!deleted)
			iter++;
		deleted = false;
		
	}
	handleBombing();
}
