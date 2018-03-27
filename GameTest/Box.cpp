//---------------------------------------------------------------------------------
// Box.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
#include "Box.h"

//---------------------------------------------------------------------------------
// Use this to initialize boxes.
// Syntax: boxName.initBox(x start position, y start position, length (default = 30), width (default = 30)
//---------------------------------------------------------------------------------
void Box::Init(int xp, int yp, int l, int w)
{
	xPos = xp;
	yPos = yp;
	length = l;
	width = w;
	numberOfBoxes++;
}

//---------------------------------------------------------------------------------
// Use this to render existing boxes.
// Syntax: boxName.renderBox();
//---------------------------------------------------------------------------------
void Box::Render()
{
	// top line
	App::DrawLine(xPos, yPos, (xPos + width), yPos);
	
	// bottom line
	App::DrawLine(xPos, (yPos + length), (xPos + width), (yPos + length));

	// left line
	App::DrawLine(xPos, yPos, xPos, (yPos + length));

	// right line
	App::DrawLine((xPos + width), (yPos + length), (xPos + width), yPos);
}