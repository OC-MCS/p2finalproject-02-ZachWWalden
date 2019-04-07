#pragma once
#include "Projectile.h"
#include <list>
using namespace std;

class ProjectileMGR
{
// data
private:
	list<Projectile*> projectileList;
	Texture cowFartOne, cowFartTwo, cowFartThree;
	Texture communistTurdOne, communistTurdTwo;
public:
// functions
private:
	void handleCollision();
public:
	ProjectileMGR();
	void addProjectile(Vector2f startPos, ProjectileEnum protType);
	void checkCollision();
};