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
	int xPos;
	int yPos;
	int length;
	int width;

	void Init(int xp, int yp, int l, int w);
	void Render();
	
	// Default constructor
	Box()
	{
	}
};

#endif