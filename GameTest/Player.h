//---------------------------------------------------------------------------------
// Player.h
//---------------------------------------------------------------------------------
#ifndef _PLAYER_H
#define _PLAYER_H
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
#include "Box.h"
#include "Goal.h"

class Player
{
private:
	int xPos;
	int yPos;
	int xTmp;	// Buffer to store proposed x position for use in collision detection
	int yTmp;	// Buffer to store proposed y position for use in collision detection
	int length = 20;
	int width = 20;
	float red = 1.0f;
	float green = 0.0f;
	float blue = 0.0f;

public:
	void Init(int xp, int yp);
	void Render();
	void UpdatePosition(int nxp, int nyp);
	void SetColour(float r, float g, float b);
	void Update();
	bool IsCollidingWith(Box* bp);
	bool IsCollidingWith(Goal* bp);
	bool levelFinished = false;

	Player()
	{
	}
};

#endif