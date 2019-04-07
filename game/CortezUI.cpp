#include "CortezUI.h"

CortezUI::CortezUI(CortezMGR *MGR)
{
	mgrPtr = MGR;
}

void CortezUI::draw(RenderWindow & win)
{
	list<OcasioCortez*>* listPtr = mgrPtr->getCortezPtr();
	list<OcasioCortez*>::iterator iter;
	for (iter = listPtr->begin(); iter != listPtr->end(); iter++)
	{
		(*iter)->draw(win);
	}
	mgrPtr->moveCortez();
}
