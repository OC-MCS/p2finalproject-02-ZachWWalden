#pragma once
#include "Projectile.h"
#include "ProjectileMGR.h"

/*===================================================================
	Projectile - default constructor
	Parameters: none
	Return Type: void
=====================================================================*/
Projectile::Projectile()
{
}
/*===================================================================
	Projectile - Constructor, sets the projectile type to the passed enum
	Parameters: ProjectileEnum newProtType - type of new projectile
	Return Type: none
=====================================================================*/
Projectile::Projectile(ProjectileEnum newProtType)
{
	// intialize the projectile type to the passed type
	protType = newProtType;
}
/*===================================================================
	getProtType - returns the projectile type
	Parameters: none
	Return Type: ProjectileEnum
=====================================================================*/
ProjectileEnum Projectile::getProtType()
{
	// return the projectile types
	return protType;
}
/*===================================================================
	CowFart - Default constructor
	Parameters: none
	Return Type: none
=====================================================================*/
CowFart::CowFart()
{
}
/*===================================================================
	CowFart - Constructor, sets the sprite's position and texture, passing the pojectile enum to the base class constructor
	Parameters: Vector2f pos - position for the new cow fart
				Texture& cowFartText - reference to the cowfart texture
				ProjectileEnum protType - type of projectile this is
	Return Type: none
=====================================================================*/
CowFart::CowFart(Vector2f pos, Texture& cowFartText, ProjectileEnum protType) : Projectile(protType)
{
	// set the sprite's texture
	cowFart.setTexture(cowFartText);
	// set the sprite's position
	cowFart.setPosition(pos);
}
/*===================================================================
	draw - overload of the base class PVF, draws the sprite on the screen
	Parameters: RenderWindow & win - reference to the render window
	Return Type: void
=====================================================================*/
void CowFart::draw(RenderWindow & win)
{
	// draw the sprite
	win.draw(cowFart);
}
/*===================================================================
	setPos - sets the position of the enemy to the passed position
	Parameters: Vector2f newPos - new position for the sprite
	Return Type: void
=====================================================================*/
void CowFart::setPos(Vector2f newPos)
{
	// set the new position
	cowFart.setPosition(newPos);
}
/*===================================================================
	getPos - returns the position of the sprite
	Parameters: none
	Return Type: Vactor2f
=====================================================================*/
Vector2f CowFart::getPos()
{
	// return the sprite's position
	return cowFart.getPosition();
}
/*===================================================================
	getGlobalBounds - returns the bounds of the sprite
	Parameters: none
	Return Type: FloatRect
=====================================================================*/
FloatRect CowFart::getGlobalBounds()
{
	// return bounds of the sprite
	return cowFart.getGlobalBounds();
}
/*===================================================================
	CommunistTurd - Default Constructor
	Parameters: none
	Return Type: none
=====================================================================*/
CommunistTurd::CommunistTurd()
{
}
/*===================================================================
	CommunistTurd - Constructor, sets the sprite's position and texture, passing the pojectile enum to the base class constructor
	Parameters: Vector2f pos - position for the new cow fart
				Texture& comTurd - reference to the communist turd texture
				ProjectileEnum protType - type of projectile this is
	Return Type: none
=====================================================================*/
CommunistTurd::CommunistTurd(Vector2f pos, Texture& comTurd, ProjectileEnum protType) : Projectile(protType)
{
	// set texture of the sprite to passed texture
	commieTurd.setTexture(comTurd);
	// set the sprite's position to the passed position
	commieTurd.setPosition(pos);
}
/*===================================================================
	draw - overload of the base class PVF, draws the sprite on the screen
	Parameters: RenderWindow & win - reference to the render window
	Return Type: void
=====================================================================*/
void CommunistTurd::draw(RenderWindow & win)
{
	// draw the communist turd
	win.draw(commieTurd);
}
/*===================================================================
    setPos - sets the position of the enemy to the passed position
	Parameters: Vector2f newPos - new position for the sprite
	Return Type: void
=====================================================================*/
void CommunistTurd::setPos(Vector2f newPos)
{
	// set the new position
	commieTurd.setPosition(newPos);
}
/*===================================================================
	getPos - returns the position of the sprite
	Parameters: none
	Return Type: Vactor2f
=====================================================================*/
Vector2f CommunistTurd::getPos()
{
	// return the position of the sprite
	return commieTurd.getPosition();
}
/*===================================================================
	getGlobalBounds - returns the bounds of the sprite
	Parameters: none
	Return Type: FloatRect
=====================================================================*/
FloatRect CommunistTurd::getGlobalBounds()
{
	// return the global bounds of the sprite
	return commieTurd.getGlobalBounds();
}