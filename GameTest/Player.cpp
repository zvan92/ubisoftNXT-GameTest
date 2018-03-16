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
	// x axis collision?
	if ((xPos >= bp->xPos && xPos <= (bp->xPos + bp->width)) ||
		(xPos + width >= bp->xPos && (xPos + width) <= (bp->xPos + bp->width)))
	{
		// x axis collision true; checking y axis
		if ((yPos >= bp->yPos && yPos <= (bp->yPos + bp->length)) ||
			(yPos + length >= bp->yPos && (yPos + length) <= (bp->yPos + bp->length)))
		{
			red = 0.0;
			blue = 1.0;
			green = 0.0;
			return true;
		}
	}
}

//---------------------------------------------------------------------------------
// Use this to initialize the player object.
// Syntax: Player(x start position, y start position)
//---------------------------------------------------------------------------------
void Player::Init(int xp, int yp)
{
	xPos = xp;
	yPos = yp;
}

// Update player position
void Player::UpdatePosition(int nxp, int nyp)
{
	xPos += nxp;
	yPos += nyp;
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