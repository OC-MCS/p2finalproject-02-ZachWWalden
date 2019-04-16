#include "gameUI.h"

GameUI::GameUI(GameMgr * ptr)
{
	if (!arial.loadFromFile("arial.ttf"))
	{
		exit(EXIT_FAILURE);
	}
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
	livesLeft.setCharacterSize(80);
	livesLeft.setFillColor(Color::Red);
	livesLeft.setPosition(Vector2f(0.0f, 0.0f));

	pause.setFont(arial);
	pause.setCharacterSize(30);
	pause.setFillColor(Color::Black);
	pause.setString("Pause");
	pause.setPosition(Vector2f(700.0f, 0.0f));

	play.setFont(arial);
	play.setCharacterSize(50);
	play.setFillColor(Color::Black);
	play.setString("Play");
	play.setPosition(Vector2f(350.0f, 267.0f));

	restart.setFont(arial);
	restart.setCharacterSize(45);
	restart.setFillColor(Color::Black);
	restart.setString("Restart");
	restart.setPosition(Vector2f(330.0f, 267.0f));

	mgrPtr = ptr;
}

void GameUI::draw(RenderWindow & win)
{
	if (mgrPtr->getCurState() == INPROGRESS)
	{
		livesLeft.setString(to_string(mgrPtr->getLives()));
		win.draw(pauseButton);
		win.draw(livesLeft);
		win.draw(pause);
	}
	else if (mgrPtr->getCurState() == STARTUP || mgrPtr->getCurState() == PAUSED)
	{
		win.draw(translucent);
		win.draw(playButton);
		win.draw(play);
	}
	else if (mgrPtr->getCurState() == OVER)
	{
		win.draw(translucent);
		win.draw(playButton);
		win.draw(restart);
	}
}

void GameUI::handleMouseUp(Vector2f mousePos)
{
	if (playButton.getGlobalBounds().contains(mousePos))
	{
		if (mgrPtr->getCurState() == OVER)
			mgrPtr->resetLevel();

		mgrPtr->setGameState(INPROGRESS);
	}
	else if (pauseButton.getGlobalBounds().contains(mousePos))
	{
		mgrPtr->setGameState(PAUSED);
	}
}
