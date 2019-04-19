#pragma once
#include "gameUI.h"

/*===================================================================
	GameUI - Constructor, loads in font, initializes buttons and texts, and GameMGR pointer
	Parameters: GameMgr * ptr - pointer to the game manager
	Return Type: none
=====================================================================*/
GameUI::GameUI(GameMgr * ptr)
{
	// load font
	if (!arial.loadFromFile("arial.ttf"))
	{
		exit(EXIT_FAILURE);
	}
	// intialize UI elements
	translucent.setSize(Vector2f(800.0f, 600.0f));
	translucent.setPosition(Vector2f(0.0f, 0.0f));
	translucent.setFillColor(Color(0, 0, 0, 30));
	translucent.setOutlineColor(Color(0, 0, 0, 0));

	playButton.setSize(Vector2f(150.0f, 60.0f));
	playButton.setPosition(Vector2f(325.0f, 270.0f));
	playButton.setOutlineColor(Color::White);
	playButton.setFillColor(Color::White);

	pauseButton.setSize(Vector2f(100.0f, 30.0f));
	pauseButton.setPosition(Vector2f(700.0f, 0.0f));
	pauseButton.setOutlineColor(Color::White);
	pauseButton.setFillColor(Color::White);

	livesLeft.setFont(arial);
	livesLeft.setCharacterSize(25);
	livesLeft.setFillColor(Color::White);
	livesLeft.setPosition(Vector2f(120.0f, 0.0f));

	curLev.setFont(arial);
	curLev.setCharacterSize(25);
	curLev.setFillColor(Color::White);
	curLev.setPosition(Vector2f(280.0f, 0.0f));

	pause.setFont(arial);
	pause.setCharacterSize(28);
	pause.setFillColor(Color::Black);
	pause.setString("Pause");
	pause.setPosition(Vector2f(710.0f, 0.0f));

	play.setFont(arial);
	play.setCharacterSize(50);
	play.setFillColor(Color::Black);
	play.setString("Play");
	play.setPosition(Vector2f(350.0f, 267.0f));

	nextLevel.setFont(arial);
	nextLevel.setCharacterSize(20);
	nextLevel.setFillColor(Color::Black);
	nextLevel.setString("Play Next Level");
	nextLevel.setPosition(Vector2f(326.0f, 290.0f));

	restart.setFont(arial);
	restart.setCharacterSize(45);
	restart.setFillColor(Color::Black);
	restart.setString("Restart");
	restart.setPosition(Vector2f(330.0f, 267.0f));

	youWon.setFont(arial);
	youWon.setCharacterSize(25);
	youWon.setFillColor(Color::Black);
	youWon.setString("You Won,");
	youWon.setPosition(Vector2f(340.0f, 267.0f));

	playAgain.setFont(arial);
	playAgain.setCharacterSize(25);
	playAgain.setFillColor(Color::Black);
	playAgain.setString("Play Again");
	playAgain.setPosition(Vector2f(339.0f, 297.0f));

	level.setFont(arial);
	level.setCharacterSize(25);
	level.setFillColor(Color::White);
	level.setString("Level #");
	level.setPosition(Vector2f(190.0f, 0.0f));

	livesText.setFont(arial);
	livesText.setCharacterSize(25);
	livesText.setFillColor(Color::White);
	livesText.setString("Lives Left: ");
	livesText.setPosition(Vector2f(0.0f, 0.0f));

	score.setFont(arial);
	score.setCharacterSize(25);
	score.setFillColor(Color::White);
	score.setString("Score: ");
	score.setPosition(Vector2f(310.0f, 0.0f));

	scoreDisplay.setFont(arial);
	scoreDisplay.setCharacterSize(25);
	scoreDisplay.setFillColor(Color::White);
	scoreDisplay.setPosition(Vector2f(410.0f, 0.0f));

	//intialize Manager pointer
	mgrPtr = ptr;
}
/*===================================================================
	draw - draws game ui elements depending on the current game state
	Parameters: RenderWindow & win - reference to the window for rendering
	Return Type: void
=====================================================================*/
void GameUI::draw(RenderWindow & win)
{
	// draw elements for inprogress game state
	if (mgrPtr->getCurState() == INPROGRESS)
	{
		livesLeft.setString(to_string(mgrPtr->getLives()));
		curLev.setString(to_string(mgrPtr->getCurLevel()->getLevelNumber()));
		win.draw(pauseButton);
		win.draw(livesLeft);
		win.draw(livesText);
		win.draw(pause);
		win.draw(curLev);
		win.draw(level);
		win.draw(score);
		win.draw(scoreDisplay);
	}
	// draw the elements for startup and paused states
	else if (mgrPtr->getCurState() == STARTUP || mgrPtr->getCurState() == PAUSED)
	{
		win.draw(translucent);
		win.draw(playButton);
		win.draw(play);
	}
	// draw ui elements if the game is over
	else if (mgrPtr->getCurState() == OVER)
	{
		win.draw(translucent);
		win.draw(playButton);
		// if the player won the game, ask them to play again
		if (mgrPtr->getLives() > 0)
		{
			win.draw(playAgain);
			win.draw(youWon);
		}
		// if they lost ask them to restart
		else
			win.draw(restart);
	}
	// draw ui elements for the next level state
	else if (mgrPtr->getCurState() == NEXTLEVEL)
	{
		win.draw(translucent);
		win.draw(playButton);
		win.draw(nextLevel);
	}
	scoreDisplay.setString(to_string(mgrPtr->getScore()));
	win.draw(score);
	win.draw(scoreDisplay);
}
/*===================================================================
	handleMouseUp - handle button presses
	Parameters: Vector2f mousePos - position of the mouse
	Return Type: void
=====================================================================*/
void GameUI::handleMouseUp(Vector2f mousePos)
{
	// check if user pressed the play button
	if (playButton.getGlobalBounds().contains(mousePos))
	{
		// if the game is over reset the level
		if (mgrPtr->getCurState() == OVER)
		{
			mgrPtr->resetLevel();
			mgrPtr->resetScore();
		}
		// set the game state to inprogress
		mgrPtr->setGameState(INPROGRESS);
	}
	// check is the user pressed the pause button, and handle
	else if (pauseButton.getGlobalBounds().contains(mousePos))
	{
		mgrPtr->setGameState(PAUSED);
	}
}