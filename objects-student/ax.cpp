// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// ax.cpp
//
// This file defines the class for ax objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "ax.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

ax::ax()
{
	// Initialise the object's state
	setName("ax");

	//¸«Éí

	pole = new extrusion("dzhead.txt","polepath.txt");
	pole->setColour(0.2196,0.18,0.16);//rgb(56,46,41)
	pole->setParent(this);

	body = new extrusion("axprofile.txt","axpath.txt");
	body->setColour(0.753,0.753,0.753);
	body->setRotation('y',-30);
	body->attachToParentAt(pole,-1.4,0,-0.6);

	//¸Ë×Ó
	
	// put the shape onto the shapeVector so it gets draw messages

	gShapeVector.push_back(this);
}

void ax::hide()
{
	pole->hide();
	body->hide();
}

void ax::show()
{
	pole->show();
	body->show();
}
