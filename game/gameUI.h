#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "gameMGR.h"

class GameUI
{
private:
	GameMgr* mgrPtr;
	RectangleShape playButton, pauseButton, translucent;
	Font arial;
	Text livesLeft, play, pause, restart;
public:
//functions
private:
public:
	GameUI(GameMgr* ptr);
	void draw(RenderWindow& win);
	void handleMouseUp(Vector2f);
};