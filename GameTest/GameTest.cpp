//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
#include "GameTest.h"
//------------------------------------------------------------------------
void OnKeyEvent();

//########################################################################
// GAME START
//########################################################################

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	// Initializing box positions & sizes
	arrayOfBoxes[0].Init(100, 100, 100, 100);
	arrayOfBoxes[1].Init(300, 300, 100, 100);
	arrayOfBoxes[2].Init(500, 500, 100, 100);
	arrayOfBoxes[3].Init(300, 100, 100, 200);

	// Initializing player position
	player.Init(250, 250);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{

	// Check for keypresses & update player position
	OnKeyEvent();

	// Check for collisions between player & boxes at the updated player position
	for (int i = 0; i < numberOfBoxes; i++)
	{
		colliding = player.IsCollidingWith(&arrayOfBoxes[i]);
		if (colliding)
		{
			// Disable movement if collision is detected
			player.UpdatePosition(0, 0);
			break;
		}
	}

	// Apply the updated player position
	player.Update();
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine or Print) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	// Print welcome message on bottom-right of window
	App::Print(748, 10, welcomeMessage, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

	// Render boxes
	for (int i = 0; i < numberOfBoxes + 1; i++)
	{
		arrayOfBoxes[i].Render();
	}

	// Render player object
	player.Render();
}

//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{

}

//########################################################################
// GAME END
//########################################################################

void OnKeyEvent()
{
	int x = 0;
	int y = 0;

	if (App::IsKeyPressed('W'))
	{
		y = PLAYER_SPEED;
	}
	if (App::IsKeyPressed('S'))
	{
		y = -PLAYER_SPEED;
	}
	if (App::IsKeyPressed('A'))
	{
		x = -PLAYER_SPEED;
	}
	if (App::IsKeyPressed('D'))
	{
		x = PLAYER_SPEED;
	}

	// Updated position will be sent out for collision detection before being applied
	player.UpdatePosition(x, y);
}