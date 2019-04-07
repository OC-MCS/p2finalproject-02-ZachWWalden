#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;



enum ProjectileEnum{CowFart, CommunistTurd};
class ProjectileMGR;

class Projectile
{
// data
private:
	ProjectileEnum protType;
public:
// functions
private:
public:
	Projectile();
	ProjectileEnum getProtType();
	virtual void draw(RenderWindow &win) = 0;
};


class CowFart : public Projectile
{
// data
private:
	Texture fart;
public:
// functions
private:
public:
	CowFart();
	CowFart(ProjectileMGR *mgr);
	void draw(RenderWindow &win);
};

class CommunistTurd : public Projectile
{
// data
private:
	Texture commieTurd;
public:
// functions
private:
public:
	CommunistTurd();
	CommunistTurd(ProjectileMGR* mgr);
	void draw(RenderWindow &win);
};