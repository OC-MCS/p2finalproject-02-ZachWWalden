#include "Projectile.h"
#include "ProjectileMGR.h"

Projectile::Projectile()
{
}

Projectile::Projectile(ProjectileEnum newProtType)
{
	protType = newProtType;
}

ProjectileEnum Projectile::getProtType()
{
	return protType;
}

CowFart::CowFart()
{
}

CowFart::CowFart(Vector2f pos, Texture& cowFartText, ProjectileEnum protType) : Projectile(protType)
{
	cowFart.setTexture(cowFartText);
	cowFart.setPosition(pos);
}

void CowFart::draw(RenderWindow & win)
{
	win.draw(cowFart);
}

void CowFart::setPos(Vector2f newPos)
{
	cowFart.setPosition(newPos);
}

Vector2f CowFart::getPos()
{
	return cowFart.getPosition();
}

FloatRect CowFart::getGlobalBounds()
{
	return cowFart.getGlobalBounds();
}

CommunistTurd::CommunistTurd()
{
}

CommunistTurd::CommunistTurd(Vector2f pos, Texture& comTurd, ProjectileEnum protType) : Projectile(protType)
{
	commieTurd.setTexture(comTurd);
	commieTurd.setPosition(pos);
}

void CommunistTurd::draw(RenderWindow & win)
{
	win.draw(commieTurd);
}

void CommunistTurd::setPos(Vector2f newPos)
{
	commieTurd.setPosition(newPos);
}

Vector2f CommunistTurd::getPos()
{
	return commieTurd.getPosition();
}

FloatRect CommunistTurd::getGlobalBounds()
{
	return commieTurd.getGlobalBounds();
}
