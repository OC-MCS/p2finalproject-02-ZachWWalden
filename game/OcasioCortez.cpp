#include "OcasioCortez.h"
#include "CortezMGR.h"

void OcasioCortez::handleAnimation()
{
	if (state == BOMBING && animationCount == 40)
	{
		cortez.setTexture(mgrPtr->getTextTwo());
		animationCount--;
	}
	if ((animationCount != 40 || animationCount != 0) && state == BOMBING)
		animationCount--;
	if (animationCount == 0)
	{
		animationCount = 40;
		state = NORMAL;
		cortez.setTexture(mgrPtr->getTextOne());
	}
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
}

FloatRect OcasioCortez::getGlobalBounds()
{
	return cortez.getGlobalBounds();
}

void OcasioCortez::setState(CortexEnum newState)
{
	state = newState;
}

Vector2f OcasioCortez::getPosition()
{
	return cortez.getPosition();
}

void OcasioCortez::setPosition(Vector2f newPos)
{
	cortez.setPosition(newPos);
}
