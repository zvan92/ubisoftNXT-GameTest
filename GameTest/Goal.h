//---------------------------------------------------------------------------------
// Goal.h
//---------------------------------------------------------------------------------
#ifndef _GOAL_H
#define _GOAL_H
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
class Goal
{
public:
	int xPos;
	int yPos;
	int length = 30;
	int width = 30;
	float red = 0.0f;
	float green = 1.0f;
	float blue = 0.0f;

	void Init(int xp, int yp);
	void Render();

	// Default constructor
	Goal()
	{
	}
};

#endif
