//---------------------------------------------------------------------------------
// Player.h
//---------------------------------------------------------------------------------
#ifndef _PLAYER_H
#define _PLAYER_H
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
#include "Box.h"

class Player
{
private:
	int xPos;
	int yPos;
	int length = 20;
	int width = 20;
	float red = 1.0f;
	float green = 0.0f;
	float blue = 0.0f;

public:
	void Init(int xp, int yp);
	void Render();
	void UpdatePosition(int nxp, int nyp);
	bool IsCollidingWith(Box* bp);

	// Default constructor
	Player()
	{
	}
};

#endif