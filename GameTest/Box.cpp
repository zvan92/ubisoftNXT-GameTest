//---------------------------------------------------------------------------------
// Box.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include "App/app.h"
//---------------------------------------------------------------------------------
#include "Box.h"

//---------------------------------------------------------------------------------
// Use this to render existing boxes.
// Syntax: Box(&boxName), i.e. Box(&gArrayOfBoxes[0])
//---------------------------------------------------------------------------------
void renderBox(Box* pBox)
{
	// top line
	App::DrawLine(pBox->xPos, pBox->yPos, (pBox->xPos + pBox->width), pBox->yPos);
	
	// left line
	App::DrawLine(pBox->xPos, pBox->yPos, pBox->xPos, (pBox->yPos + pBox->length));

	// bottom line
	App::DrawLine(pBox->xPos, (pBox->yPos + pBox->length), (pBox->xPos + pBox->width), (pBox->yPos + pBox->length));

	// right line
	App::DrawLine((pBox->xPos + pBox->width), (pBox->yPos + pBox->length), (pBox->xPos + pBox->width), pBox->yPos);
}