//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#pragma once
#include "MooCow.h"
#include "CortezUI.h"
#include "ProjectileUI.h"
#include "gameUI.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 

//============================================================
// Zachary Walden
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen



int main()
{
	// window size constants
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	// create the render window
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Communist Invaders!!!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// create the player controlled cow
	MooCow cow(window);
	
	// create the game manager
	GameMgr gameMgr(STARTUP);
	// create the ui handler
	GameUI gameUI(&gameMgr);
	//create the manager for the list of enemies
	CortezMGR cortezMgr(gameMgr.getCurLevel(), &gameMgr);
	//  create the enemy list drawer class
	CortezUI cortezUI(&cortezMgr);
	// create the projectile list manager
	ProjectileMGR protMgr(&cortezMgr, &gameMgr);
	// create the class to draw the projectiles
	ProjectileUI protUI(&protMgr);

	// create background texture
	Texture kickedMarx;
	// load background texture from the file
	if (!kickedMarx.loadFromFile("Kicked_marx.png"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	
	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(kickedMarx);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Vector2f pos;

	// initial position of the ship will be approx middle of screen

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

  		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					// create position for new cow fart
					pos = cow.getPos();
					pos.y -= 28.0f;
					pos.x += 6.0f;
					// add the projectile to the list
   					protMgr.addProjectile(pos, COWFART);
				}
				
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				gameUI.handleMouseUp(mousePos);
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		
		// if the game is in progress 
		if (gameMgr.getCurState() == INPROGRESS)
		{
			// move the cow
			cow.moveCow();
			// check for projectile collisions
			protMgr.checkCollision(cow);

			//draw the cow
			cow.draw(window);
			// draw the enemies
			cortezUI.draw(window);
			// draw the projectiles
			protUI.draw(window);
		}
		//draw the game's UI elements
		gameUI.draw(window);
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.
		
	} // end body of animation loop

	return 0;
}
