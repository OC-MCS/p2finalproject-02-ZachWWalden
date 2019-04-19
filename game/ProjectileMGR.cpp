#pragma once
#include "ProjectileMGR.h"
#include "CortezMGR.h"

/*===================================================================
	handleBombing - psuedo randomly selects a wether a bomb should or should not be dropped from each alien
	Parameters: none
	Return Type: void
=====================================================================*/
void ProjectileMGR::handleBombing()
{
	// holds the position for the new bomb
	Vector2f newBombPos;
	// get pointer to the list of enemies
	list<OcasioCortez*>* listPtr = cortezMgr->getCortezPtr();
	// create iterator to run through the list of enemies
	list<OcasioCortez*>::iterator cortezIter;
	// create end check iterator
	list<OcasioCortez*>::iterator cortezEND = listPtr->end();
	for (cortezIter = listPtr->begin(); cortezIter != cortezEND; cortezIter++)
	{
		// randomly see if a bomb should be dropped
		if (((rand() % gameMGR->getCurLevel()->getDropRate()) + 1) == 1L)
		{
			// intialize bomb position the the location of the enemy we are currently looking at
			newBombPos = (*cortezIter)->getPosition();
			// set the state of the current enemy to bombing (for animation purposes)
			(*cortezIter)->setState(BOMBING);
			// increment the new bombs x position in relation to the current enemy
			newBombPos.x += 25.0f;
			// increment the new bombs y position in relation to the current enemy
			newBombPos.y += 35.0f;
			// call function to add the new bomb to the list of bombs
			addProjectile(newBombPos, COMMUNISTTURD);
		}
	}

}
/*===================================================================
	deelteProjectiles - runs through the list of projectiles, deleting them all
	Parameters: - none
	Return Type: - void
=====================================================================*/
void ProjectileMGR::deleteProjectiles()
{
	// create iterator to run through the list of projectiles
	list<Projectile*>::iterator iter;
	// loop through the list of projectiles, deleting each one
	for (iter = projectileList.begin(); iter != projectileList.end();)
	{
		// delete dynamically allocated projectile
		delete (*iter);
		// delete pointer to just deleted projectile from the list
		iter = projectileList.erase(iter);
	}
}
/*===================================================================
	ProjectileMGR - Constructor, loads in projectile textures, seeds the rand function, initializes pointers
	Parameters:	CortezMGR* cortezPtr - pointer for acess to the enemy list and functions used to control the level
				GameMgr* gameMgr - pointer to the gameMGR for stats and states control
	Return Type: - none
=====================================================================*/
ProjectileMGR::ProjectileMGR(CortezMGR* cortezPtr, GameMgr* gameMgr)
{
	// load cow fart texture
	if (!cowFart.loadFromFile("cow_fart.png"))
	{
		// error
	}
	// load communist turd texture
	if (!communistTurd.loadFromFile("communist_turd.png"))
	{
		// error
	}
	// seed rand with the current time
	srand(time(0));
	// intialize enemy manager pointer
	cortezMgr = cortezPtr;
	// initialize the current level pointer
	curLevel = cortezMgr->getLevel();
	// initalize pointer to the game manager
	gameMGR = gameMgr;
}
/*===================================================================
	addProjectile - add a new projectile to the list
	Parameters: Vector2f startPos - starting position of the new projectile
				ProjectileEnum protType - type of projectile you wish to add
	Return Type: - void
=====================================================================*/
void ProjectileMGR::addProjectile(Vector2f startPos, ProjectileEnum protType)
{
	// if the projectile is to be a communist turd do this
	if (protType == COMMUNISTTURD)
	{
		// dynamically allocate the new turd
		CommunistTurd* c = new CommunistTurd(startPos, communistTurd, protType);
		// add pointer to the dynamically allocated turd to the list
		projectileList.push_back(c);
	}
	// if the projectile is to be a cow fart do this
	else if (protType == COWFART)
	{
		// dynamically allocate the new fart
		CowFart* c = new CowFart(startPos, cowFart, protType);
		// push pointer to the dynamically allocated new fart to the end of the list
		projectileList.push_back(c);
	}
	
}
/*=======================================================================================
	checkCollision - checks for projectile collisions;
	Parameters: - MooCow& cow - reference to the player controlled cow
	Return Type: - void
========================================================================================*/
void ProjectileMGR::checkCollision(MooCow& cow)
{
	// flag for if any deletion from either list was performed
	bool deleted = false;
	// flag fo if the projectile list is empty
	bool protlistEmpty = false;
	// iterator to loop through the projectile list
	list<Projectile*>::iterator iter;
	// initialize projectile end of list iterator
	list<Projectile*>::iterator iterEND = projectileList.end();
	// loop through the list of projectiles, if there are any and if we have not reached the end
	for (iter = projectileList.begin(); !protlistEmpty && iter != iterEND;)
	{
		// if the current projectile is a communist turd check for a collision with the plyer controlled cow
		if ((*iter)->getProtType() == COMMUNISTTURD)
		{
			// check if the current projectile hit the cow
			if (cow.getGlobalBounds().intersects((*iter)->getGlobalBounds()))
			{
				// if the player has run out of lives
				if (gameMGR->getLives() == 0)
				{
					// set the game state to over
					gameMGR->setGameState(OVER);
					// reset the level
					gameMGR->resetLevel();
				}
				// decrement lives counter
				gameMGR->decrementLives();
				// delete the offending projectile
				delete (*iter);
				// delete the offending projectile's pointer from the list
				iter = projectileList.erase(iter);
				// set deletion flag
				deleted = true;
				// reset the enemies to their starting position
				cortezMgr->initializeLevel(gameMGR->getCurLevel());
				// delete all the projectiles
				deleteProjectiles();
				// set flag telling the loop there are no longer any projectiles
				protlistEmpty = true;
			}
		}
		// if the projectile is a cow fart, run through the list of enemies to check for collisions
		else if ((*iter)->getProtType() == COWFART)
		{
			// initialize pointer to the list of enemies
			list<OcasioCortez*>* listPtr = cortezMgr->getCortezPtr();
			// create iterator to run through the list of enemies
			list<OcasioCortez*>::iterator cortezIter;
			// intialize end check iterator
			list<OcasioCortez*>::iterator cortezEND = listPtr->end();
			// loop trough the list of enemies if there are projectiles, and the end of the list has not been reached
			for (cortezIter = listPtr->begin(); cortezIter != cortezEND && !protlistEmpty;)
			{
				// check for collision between the current projectile and enemy
				if ((*cortezIter)->getGlobalBounds().intersects((*iter)->getGlobalBounds()))
				{
					//delete the victorious projectile
					delete (*iter);
					// delete that projectile;s pointer from the lsit
					iter = projectileList.erase(iter);

					// if there are no more projectiles in the list, set flag that the projectile list is empty
					if (iter == iterEND)
						protlistEmpty = true;

					// delete the defeated enemy
					delete (*cortezIter);
					// delete the dead enemy's pointer from the list
					cortezIter = listPtr->erase(cortezIter);
					// flip the deletion flag
					deleted = true;
					// handle the score
					gameMGR->handleScore();
				}
				// if nno deleting occurred increment the enemy list iterator
				if (!deleted)
					cortezIter++;
				// flip deletion flag to false
				deleted = false;
			}
			// if the list of enemies is empty, handle level transition
			if (listPtr->begin() == listPtr->end())
			{
				// set the game state to nextlevel
				gameMGR->setGameState(NEXTLEVEL);
				// check to see if the last level was completed, if so set the game state to over
				if(gameMGR->getCurLevel()->getLevelNumber() == 3)
					gameMGR->setGameState(OVER);
				// if the game state is not over, increment the level iterator in gameMGR
				if (gameMGR->getCurState() != OVER)
					gameMGR->incrementLevel();
				// reset the level
				gameMGR->resetLevel();
				// reset the enemies to their starting position
				cortezMgr->initializeLevel(gameMGR->getCurLevel());
				// delete the list of projectiles
				deleteProjectiles();
				//increment the number of lives for completeing the level
				gameMGR->incrementLives();
				// set flag for an empty list of projectiles
				protlistEmpty = true;
			}
		}
		// if there are projectiles left, and none were deleted on the last iteration of the loop, increment the projectile list iterator
		if (!deleted && !protlistEmpty)
			iter++;
		// set deleted flag false for next iteration trough the loop
		deleted = false;

	}
}
/*===================================================================
	getProjPtr - returns a pointer to the list of projectiles
	Parameters: - none
	Return Type: list<Projectile*>*
=====================================================================*/
list<Projectile*>* ProjectileMGR::getProjPtr()
{
	return &projectileList;
}
/*===================================================================
	moveProjectiles - moves the projectiles in their respective directions
	Parameters: - none
	Return Type: - void
=====================================================================*/
void ProjectileMGR::moveProjectiles()
{
	// initialize deletion flag to false
	bool deleted = false;
	// create iterator to loop through the list of projectiles
	list<Projectile*>::iterator iter;
	// loop through the list of projectiles
	for (iter = projectileList.begin(); iter != projectileList.end();)
	{
		// create a variable to hold the new position of the current projectile, and intialize it to that projectile's current position
		Vector2f newPos = (*iter)->getPos();
		// if the projectile is a cow fart
		if ((*iter)->getProtType() == COWFART)
		{
			// move it up 10 pixels
			newPos.y -= 10.0f;
			// set the new position
			(*iter)->setPos(newPos);
			// if the current cow fart has left the screen, delete it
			if (newPos.y < -30.0f)
			{
				// delete dynamically allocated projectile
				delete (*iter);
				// delete its pointer from the list
				iter = projectileList.erase(iter);
				// set the deletion flag
				deleted = true;
			}
		}
		// if the projectile is a communist turd
		else
		{
			// move the communist turd down the screen two pixels
			newPos.y += 2.0f;
			// set the new position
			(*iter)->setPos(newPos);
			// if the turd went off the screen, delete it
			if (newPos.y > 630.0f)
			{
				// delete dynamically allocated projectile
				delete (*iter);
				// delete pointer from the lsit
				iter = projectileList.erase(iter);
				// set deletion flag true
				deleted = true;
			}
		}
		// if no projectiles were deleted, increment the list iterator
		if (!deleted)
			iter++;
		// set the deletion flag false for next runthrough of the loop
		deleted = false;
		
	}
	// handle the dropping of bombs by the enemies
	handleBombing();
}