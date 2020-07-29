// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// arrow.cpp
//
// This file defines the class for arrow objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "arrow.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

arrow::arrow()
{
	// Initialise the object's state
	setName("arrow");

	//¼ýÉí
	body = new extrusion("dzhead.txt","lrlegpath.txt");
	body->setColour(0.55,0.278,0.149);//140,71,38
	body->setDeformation(0.6,0.6,1.2);
	body->setParent(this);

	//¼ýÍ·
	head = new extrusion("dzhead.txt","arrowpath.txt");
	head->setColour(0.753,0.753,0.753);
	head->attachToParentAt(body,0,0,3);

	//ÓðÃ«
	feather1 = new extrusion("featherprofile.txt","featherpath.txt");
	feather1->setColour(1,1,1,0.6);
	feather1->setRotation('z',-27,'y',90);
	feather1->attachToParentAt(body,1.45,0.1,0.2);

	feather2 = new extrusion("featherprofile.txt","featherpath.txt");
	feather2->setColour(1,1,1,0.6);
	feather2->setRotation('z',-27,'y',-90);
	feather2->attachToParentAt(body,-1.45,-0.3,0);
	
	// put the shape onto the shapeVector so it gets draw messages

	gShapeVector.push_back(this);
}

void arrow::hide()
{
	body->hide();
	head->hide();
	feather1->hide();feather2->hide();
}

void arrow::show()
{
	body->show();
	head->show();
	feather1->show();feather2->show();
}

void arrow::move(float time)
{
	float t = time -35;
	setPosition(getPosition().data[0]+0.1,getPosition().data[1],getPosition().data[2]);
}
