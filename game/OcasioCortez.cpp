#pragma once
#include "OcasioCortez.h"
#include "CortezMGR.h"

/*===================================================================
	handleAnimation - handles the animation states for the enemies
	Parameters: none
	Return Type: void
=====================================================================*/
void OcasioCortez::handleAnimation()
{
	// if the enemy is bombing and the bombing run just began, set the texture to the bombing texture
	if (state == BOMBING && animationCount == 40)
	{
		// set bombing texture
		cortez.setTexture(mgrPtr->getTextTwo());
		// decrement the animation count
		animationCount--;
	}
	// if the enemy is bombing and the animation count is not 0, decrement the animation count
	if ((animationCount != 40 || animationCount != 0) && state == BOMBING)
		// decrement the animation count
		animationCount--;
	// when the animaiton count hits zero, set the normal texture, and reset the animation count for the next bombing run
	if (animationCount == 0)
	{
		// reset animation count
		animationCount = 40;
		// set enemy state to normal
		state = NORMAL;
		// reset to the normal texture
		cortez.setTexture(mgrPtr->getTextOne());
	}
}
/*===================================================================
	OcasioCortez - Constructor, intializes the enemy sprite, and manager pointer
	Parameters: CortezMGR *Mgr pointer to the enemy manager
				Vector2f pos - position for the enemy
	Return Type: none
=====================================================================*/
OcasioCortez::OcasioCortez(CortezMGR *Mgr, Vector2f pos)
{
	// set texture
	cortez.setTexture(Mgr->getTextOne());
	// initialize the sprites position
	cortez.setPosition(pos);
	// initialize pointer to the enemy manager
	mgrPtr = Mgr;
}
/*===================================================================
	draw - handles animation, and draw the enemy on the screen
	Parameters: RenderWindow & win - reference to the render window
	Return Type: void
=====================================================================*/
void OcasioCortez::draw(RenderWindow & win)
{
	// handle enemy animation
	handleAnimation();
	// draw the enemy
	win.draw(cortez);
}
/*===================================================================
	getGlobalBounds - wrapper around the sprite class' getGlobalBounds function
	Parameters: none
	Return Type: FloatRect
=====================================================================*/
FloatRect OcasioCortez::getGlobalBounds()
{
	// return the bounds of this enemy
	return cortez.getGlobalBounds();
}
/*===================================================================
	setState - set the state of the enemy to the current value
	Parameters: CortexEnum newState - new state for the enemy
	Return Type: void
=====================================================================*/
void OcasioCortez::setState(CortexEnum newState)
{
	// set the state to the passed state
	state = newState;
}
/*===================================================================
	getPosition - wrapper around the Sprite class's getPosition function
	Parameters: none
	Return Type: Vector2f
=====================================================================*/
Vector2f OcasioCortez::getPosition()
{
	// return enemy position
	return cortez.getPosition();
}
/*===================================================================
	setPosition - wrapper around the graphics library's setPosition function
	Parameters: Vector2f newPos - new position for the enemy
	Return Type: void
=====================================================================*/
void OcasioCortez::setPosition(Vector2f newPos)
{
	// set the position of the enemy to the passed position
	cortez.setPosition(newPos);
}