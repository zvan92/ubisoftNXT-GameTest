//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------
#include "Box.h"
//------------------------------------------------------------------------
Box gArrayOfBoxes[100];
int numberOfBoxes = 0;
char* welcomeMessage = "Welcome to Evan's Game!";

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	// Creating box objects and initializing their positions & sizes
	gArrayOfBoxes[0] = Box(100, 100, 100, 100);
	gArrayOfBoxes[1] = Box(300, 300, 200, 200);
	gArrayOfBoxes[2] = Box(600, 600, 100, 100);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine or Print) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	// Print welcome message on bottom-right of window
	App::Print(748, 10, welcomeMessage, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);

	// Render all existing boxes
	for (int i = 0; i < numberOfBoxes + 1; i++)
		renderBox(&gArrayOfBoxes[i]);
}

//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
}