#pragma once
#include "CortezUI.h"

/*===================================================================
	CortexUI - Constructor, initailizes enemy manager pointer
	Parameters: CortezMGR *MGR - pointer to the enemy manager class used for displaying
	Return Type: none
=====================================================================*/
CortezUI::CortezUI(CortezMGR *MGR)
{
	// initialize pointer
	mgrPtr = MGR;
}
/*===================================================================
	draw - draws the enemies on to the screen
	Parameters: RenderWindow & win - reference tot he RenderWindow for drawing
	Return Type: void
=====================================================================*/
void CortezUI::draw(RenderWindow & win)
{
	// pointer to the list of enemies
	list<OcasioCortez*>* listPtr = mgrPtr->getCortezPtr();
	// enemy list iterator
	list<OcasioCortez*>::iterator iter;
	// drawing loop
	for (iter = listPtr->begin(); iter != listPtr->end(); iter++)
	{
		(*iter)->draw(win);
	}
	// move the enemies
	mgrPtr->moveCortez();
}