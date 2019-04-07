#include "OcasioCortez.h"
#include "CortezMGR.h"

void OcasioCortez::handleAnimation()
{
	if (animationCount > 60)
	{
		animationCount = 0;
		state = BOMBING;
		cortez.setTexture(mgrPtr->getTextTwo());
	}
	if (state == BOMBING && animationCount > 30)
	{
		state = NORMAL;
		cortez.setTexture(mgrPtr->getTextOne());
	}

	
	if (state == DEAD)
		cortez.setTexture(mgrPtr->getTextThree());
}

OcasioCortez::OcasioCortez(CortezMGR *Mgr, Vector2f pos)
{
	cortez.setTexture(Mgr->getTextOne());

	cortez.setPosition(pos);

	mgrPtr = Mgr;
}

void OcasioCortez::draw(RenderWindow & win)
{
	handleAnimation();
	win.draw(cortez);
	animationCount++;
}
