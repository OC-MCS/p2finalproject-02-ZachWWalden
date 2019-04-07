#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;



enum ProjectileEnum{COWFART, COMMUNISTTURD};
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
	Projectile(ProjectileEnum);
	ProjectileEnum getProtType();
	virtual void draw(RenderWindow &win) = 0;
	virtual void setPos(Vector2f newPos) = 0;
	virtual Vector2f getPos() = 0;
	virtual FloatRect getGlobalBounds() = 0;
};


class CowFart : public Projectile
{
// data
private:
	Sprite cowFart;
public:
// functions
private:
public:
	CowFart();
	CowFart(Vector2f pos, Texture&, ProjectileEnum);
	void draw(RenderWindow &win);
	void setPos(Vector2f newPos);
	Vector2f getPos();
	FloatRect getGlobalBounds();
};

class CommunistTurd : public Projectile
{
// data
private:
	Sprite commieTurd;
public:
// functions
private:
public:
	CommunistTurd();
	CommunistTurd(Vector2f pos, Texture&, ProjectileEnum);
	void draw(RenderWindow &win);
	void setPos(Vector2f newPos);
	Vector2f getPos();
	FloatRect getGlobalBounds();
};