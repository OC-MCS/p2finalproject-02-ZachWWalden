#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;



enum ProjectileEnum{COWFART, COMMUNISTTURD};
class ProjectileMGR;

class Projectile
{
// data
private:
	// keeps track of which type of projectile this is
	ProjectileEnum protType;
public:
// functions
private:
public:
	// see implementation file for detailed explanation
	Projectile();
	// see implementation file for detailed explanation
	Projectile(ProjectileEnum);
	// see implementation file for detailed explanation
	ProjectileEnum getProtType();
	// pure virtual function for drawing the projectiles
	virtual void draw(RenderWindow &win) = 0;
	// pure virtual function for setting position
	virtual void setPos(Vector2f newPos) = 0;
	// pure virtual function for getting projectileposition
	virtual Vector2f getPos() = 0;
	// pure virtual function for getting global bounds of this projectile
	virtual FloatRect getGlobalBounds() = 0;
};


class CowFart : public Projectile
{
// data
private:
	// sprite for displaying cow farts
	Sprite cowFart;
public:
// functions
private:
public:
	// see implementation file for detailed explanation
	CowFart();
	// see implementation file for detailed explanation
	CowFart(Vector2f pos, Texture&, ProjectileEnum);
	// see implementation file for detailed explanation
	void draw(RenderWindow &win);
	// see implementation file for detailed explanation
	void setPos(Vector2f newPos);
	// see implementation file for detailed explanation
	Vector2f getPos();
	// see implementation file for detailed explanation
	FloatRect getGlobalBounds();
};

class CommunistTurd : public Projectile
{
// data
private:
	// sprite for displaying this commie turd
	Sprite commieTurd;
public:
// functions
private:
public:
	// see implementation file for detailed explanation
	CommunistTurd();
	// see implementation file for detailed explanation
	CommunistTurd(Vector2f pos, Texture&, ProjectileEnum);
	// see implementation file for detailed explanation
	void draw(RenderWindow &win);
	// see implementation file for detailed explanation
	void setPos(Vector2f newPos);
	// see implementation file for detailed explanation
	Vector2f getPos();
	// see implementation file for detailed explanation
	FloatRect getGlobalBounds();
};