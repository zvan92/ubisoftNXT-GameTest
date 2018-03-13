//---------------------------------------------------------------------------------
// Box.h
//---------------------------------------------------------------------------------
#ifndef _BOX_H
#define _BOX_H
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
extern int numberOfBoxes;

class Box
{
public:
	float xPos;
	float yPos;
	int length;
	int width;
	
	Box()
	{
	}

	//---------------------------------------------------------------------------------
	// Use this to initialize boxes.
	// Syntax: Box(x start position, y start position, length in pixels, width in pixels
	//---------------------------------------------------------------------------------
	Box(float xp, float yp, int l, int w)
	{
		xPos = xp;
		yPos = yp;
		length = l;
		width = w;
		numberOfBoxes++;
	}
};

void renderBox(Box* pBox);

#endif