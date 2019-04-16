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
		if (((rand() % gameMGR->getCurLevel()->getDropRate()) + 1) == 1L)
		{
			newBombPos = (*cortezIter)->getPosition();
			(*cortezIter)->setState(BOMBING);
			newBombPos.x += 25.0f;
			newBombPos.y += 35.0f;
			addProjectile(newBombPos, COMMUNISTTURD);
		}
	}

}

void ProjectileMGR::deleteProjectiles()
{
	list<Projectile*>::iterator iter;
	for (iter = projectileList.begin(); iter != projectileList.end();)
	{
		delete (*iter);
		iter = projectileList.erase(iter);
	}
}

ProjectileMGR::ProjectileMGR(CortezMGR* cortezPtr, GameMgr* gameMgr)
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
	gameMGR = gameMgr;
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

	for (iter = projectileList.begin(); !protlistEmpty && iter != iterEND;)
	{
		Vector2f newPos = (*iter)->getPos();
		if ((*iter)->getProtType() == COMMUNISTTURD)
		{
			if (cow.getGlobalBounds().intersects((*iter)->getGlobalBounds()))
			{
				if (gameMGR->getLives() == 0 && gameMGR->getCurLevel()->getLevelNumber() == 3)
				{
					gameMGR->resetLevel();
					gameMGR->setGameState(OVER);
				}
				gameMGR->decrementLives();
				delete (*iter);
				iter = projectileList.erase(iter);
				deleted = true;
				cortezMgr->initializeLevel(gameMGR->getCurLevel());
				deleteProjectiles();
				protlistEmpty = true;
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
			if (listPtr->begin() == listPtr->end())
			{
				if(gameMGR->getCurLevel()->getLevelNumber() == 3)
					gameMGR->setGameState(OVER);
				if (gameMGR->getCurState() != OVER)
					gameMGR->incrementLevel();
				cortezMgr->initializeLevel(gameMGR->getCurLevel());
				deleteProjectiles();
				gameMGR->resetLevel();
				protlistEmpty = true;
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
