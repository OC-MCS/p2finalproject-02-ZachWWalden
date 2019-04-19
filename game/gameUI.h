#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include "gameMGR.h"

class GameUI
{
private:
	// pointer to game manager for acess to the current state
	GameMgr* mgrPtr;
	// rectangeShapes for the bttons
	RectangleShape playButton, pauseButton, translucent;
	// font for text display
	Font arial;
	// various texts to display for the UI
	Text livesLeft, play, pause, restart, nextLevel, killCount, curLev, youWon, playAgain, level, livesText, score, scoreDisplay;
public:
//functions
private:
public:
	// see implementation file for detailed explanation
	GameUI(GameMgr* ptr);
	// see implementation file for detailed explanation
	void draw(RenderWindow& win);
	// see implementation file for detailed explanation
	void handleMouseUp(Vector2f);
};