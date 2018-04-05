//---------------------------------------------------------------------------------
// Goal.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
#include "Goal.h"

//---------------------------------------------------------------------------------
// Use this to initialize the goal.
// Syntax: goalName.Init(x start position, y start position);
//---------------------------------------------------------------------------------
void Goal::Init(int xp, int yp)
{
	xPos = xp;
	yPos = yp;
}

//---------------------------------------------------------------------------------
// Use this to render existing boxes.
// Syntax: goalName.Render();
//---------------------------------------------------------------------------------
void Goal::Render()
{
	// top line
	App::DrawLine(xPos, yPos, (xPos + width), yPos, red, green, blue);

	// bottom line
	App::DrawLine(xPos, (yPos + length), (xPos + width), (yPos + length), red, green, blue);

	// left line
	App::DrawLine(xPos, yPos, xPos, (yPos + length), red, green, blue);

	// right line
	App::DrawLine((xPos + width), (yPos + length), (xPos + width), yPos, red, green, blue);
}