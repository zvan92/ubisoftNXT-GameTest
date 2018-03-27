//---------------------------------------------------------------------------------
// Player.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
#include "Player.h"

bool Player::IsCollidingWith(Box* bp)
{
	// These hold the proposed new positions of the player
	int testX = xPos + xTmp;
	int testY = yPos + yTmp;

	// X axis collision?
	if ((testX > bp->xPos && testX < (bp->xPos + bp->width)) ||
		(testX + width > bp->xPos && (testX + width) < (bp->xPos + bp->width)))
	{
		// X axis collision true; checking Y axis
		if ((testY > bp->yPos && testY < (bp->yPos + bp->length)) ||
			(testY + length > bp->yPos && (testY + length) < (bp->yPos + bp->length)))
		{
			return true;
		}
	}
	return false;
}

void Player::SetColour(float r, float g, float b)
{
	red = r;
	green = g;
	blue = b;
}

//---------------------------------------------------------------------------------
// Use this to initialize the player object.
// Syntax: Player(x start position, y start position)
//---------------------------------------------------------------------------------
void Player::Init(int xp, int yp)
{
	// Not used on init; player isn't moving yet
	xTmp = 0;
	yTmp = 0;
	// Actual init position is set with these
	xPos = xp;
	yPos = yp;
}

// Update player position
void Player::UpdatePosition(int nxp, int nyp)
{
	xTmp = nxp; // X position to be applied to xPos if no collision (buffer)
	yTmp = nyp; // Y position to be applied to yPos if no collision (buffer)
}

// Applies changes to player position
void Player::Update()
{
	xPos += xTmp;
	yPos += yTmp;
}

//---------------------------------------------------------------------------------
// Use this to render the player object.
// Syntax: Player(&playername), i.e. Player(&playerObject)
//---------------------------------------------------------------------------------
void Player::Render()
{
	// top line
	App::DrawLine(xPos, (yPos + length), (xPos + width), (yPos + length), red, green, blue);
	
	// bottom line
	App::DrawLine(xPos, yPos, (xPos + width), yPos, red, green, blue);

	// left line
	App::DrawLine(xPos, yPos, xPos, (yPos + length), red, green, blue);

	// right line
	App::DrawLine((xPos + width), (yPos + length), (xPos + width), yPos, red, green, blue);
}