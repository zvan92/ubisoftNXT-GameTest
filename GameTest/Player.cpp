//---------------------------------------------------------------------------------
// Player.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
#include "Player.h"

// Player-Box collision detection
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

// Player-Box collision detection
bool Player::IsCollidingWith(Goal* g)
{
	int testX = xPos + xTmp;
	int testY = yPos + yTmp;

	if ((testX > g->xPos && testX < (g->xPos + g->width)) ||
		(testX + width > g->xPos && (testX + width) < (g->xPos + g->width)))
	{
		if ((testY > g->yPos && testY < (g->yPos + g->length)) ||
			(testY + length > g->yPos && (testY + length) < (g->yPos + g->length)))
		{
			return true;
		}
	}
	return false;
}

/* void Player::SetColour(float r, float g, float b)
{
	red = r;
	green = g;
	blue = b;
} */

//---------------------------------------------------------------------------------
// Use this to initialize the player object.
// Syntax: playerName.Init(x start position, y start position);
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
// Syntax: playerName.Render();
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