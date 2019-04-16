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
	list<Projectile*> projectileList;
	Texture cowFart;
	Texture communistTurd;
	CortezMGR* cortezMgr;
	GameMgr* gameMGR;
	Level* curLevel;
public:
// functions
private:
	void handleBombing();
	void deleteProjectiles();
public:
	ProjectileMGR(CortezMGR* cortezPtr, GameMgr* gameMgr);
	void addProjectile(Vector2f startPos, ProjectileEnum protType);
	void checkCollision(MooCow& cow);
	list<Projectile*>* getProjPtr();
	void moveProjectiles();
};