#pragma once
#include "Projectile.h"
#include "MooCow.h"
#include "OcasioCortez.h"
#include "gameMGR.h"
#include <list>
#include <iostream>
using namespace std;

class ProjectileMGR
{
// data
private:
	// linked list for projectiles
	list<Projectile*> projectileList;
	// texture for the cowfart
	Texture cowFart;
	// texture for communist turds
	Texture communistTurd;
	// used to access enemy list and other funcitons
	CortezMGR* cortezMgr;
	// pointer to the game manager for control of lives, game states and the score
	GameMgr* gameMGR;
	// pointer to the current level
	Level* curLevel;
public:
// functions
private:
	// see implementation file for detailed explanation
	void handleBombing();
	// see implementation file for detailed explanation
	void deleteProjectiles();
public:
	// see implementation file for detailed explanation
	ProjectileMGR(CortezMGR* cortezPtr, GameMgr* gameMgr);
	// see implementation file for detailed explanation
	void addProjectile(Vector2f startPos, ProjectileEnum protType);
	// see implementation file for detailed explanation
	void checkCollision(MooCow& cow);
	// see implementation file for detailed explanation
	list<Projectile*>* getProjPtr();
	// see implementation file for detailed explanation
	void moveProjectiles();
};