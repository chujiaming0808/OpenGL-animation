// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// sword.cpp
//
// This file defines the class for sword objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "sword.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

sword::sword()
{
	// Initialise the object's state
	setName("sword");

	//½£±ú
	pole = new extrusion("dzhead.txt","spolepath.txt");
	pole->setColour(0.2196,0.18,0.16);
	pole->setParent(this);

	//½£¸ñ
	grid = new extrusion("cubeprofile.txt","gridpath.txt");
	grid->setColour(0.2196,0.18,0.16);
	grid->attachToParentAt(pole,0,0,0.3);
	

	//½£Éí
	body = new extrusion("swordprofile.txt","swordpath.txt");
	body->setColour(0.753,0.753,0.753);
	body->attachToParentAt(grid,0,0,0);
	// put the shape onto the shapeVector so it gets draw messages

	gShapeVector.push_back(this);
}

void sword::hide()
{
	pole->hide();
	grid->hide();
	body->hide();
}

void sword::show()
{
	pole->show();
	grid->show();
	body->show();
}
