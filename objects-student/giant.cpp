// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// giant.cpp
//
// This file defines the class for giant objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "giant.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

giant::giant()
{
	// Initialise the object's state
	setName("giant");
	//材质贴图
	faceStone = new texture("faceStone.jpg");
	stone = new texture("stone.jpg");
	patternStone = new texture("patternStone.jpg");
	patternStone2 = new texture("patternStone2.jpg");
	thighStone = new texture("thighStone.jpg");
	footStone = new texture("footStone.jpg");

	//身体
	body = new tsphere();
	body->setTexture(stone);
	body->setDeformation(1,1.7,1.3);
	body->setParent(this);

	//头
	head = new tsphere();
	head->setTexture(faceStone);
	//head->setRotation('z',-35);
	head->setDeformation(0.5,0.5,0.5);
	head->attachToParentAt(body,-1.2,0.5,0);

	//肩膀
	arm1 = new tsphere();
	arm1->setTexture(patternStone);
	arm1->setRotation('x',50);
	arm1->setDeformation(0.6,0.7,1);
	arm1->attachToParentAt(body,0,0.5,1.5);

	arm2 = new tsphere();
	arm2->setTexture(patternStone);
	arm2->setRotation('x',-50);
	arm2->setDeformation(0.6,0.7,1);
	arm2->attachToParentAt(body,0,0.5,-1.5);

	//手
	hand1 = new tsphere();
	hand1->setTexture(patternStone2);
	hand1->setDeformation(0.6,0.6,0.6);
	hand1->attachToParentAt(arm1,0,-1,1.5);

	hand2 = new tsphere();
	hand2->setTexture(patternStone2);
	hand2->setDeformation(0.6,0.6,0.6);
	hand2->attachToParentAt(arm2,0,-1,-1.5);

	//屁股
	butt = new tsphere();
	butt->setTexture(stone);
	butt->setDeformation(0.5,0.4,0.5);
	butt->attachToParentAt(body,0,-2,0);

	//大腿
	thigh1 = new tsphere();
	thigh1->setTexture(thighStone);
	thigh1->setRotation('x',-30);
	thigh1->setDeformation(0.6,0.7,0.6);
	thigh1->attachToParentAt(butt,0,-0.6,0.8);

	thigh2 = new tsphere();
	thigh2->setTexture(thighStone);
	thigh2->setRotation('x',30);
	thigh2->setDeformation(0.6,0.7,0.6);
	thigh2->attachToParentAt(butt,0,-0.6,-0.8);

	//脚
	foot1 = new tsphere();
	foot1->setTexture(footStone);
	foot1->setRotation('x',30);
	foot1->setDeformation(0.7,0.8,0.7);
	foot1->attachToParentAt(thigh1,0,-1.1,-0.5);

	foot2 = new tsphere();
	foot2->setTexture(footStone);
	foot2->setRotation('x',-30);
	foot2->setDeformation(0.7,0.8,0.7);
	foot2->attachToParentAt(thigh2,0,-1.1,0.5);
	gShapeVector.push_back(this);
}

/*
		tsphere *head;
		tsphere *body;
		tsphere *arm1,*arm2;
		tsphere *hand1,*hand2;
		tsphere *butt;
		tsphere *thigh1,*thigh2;
		tsphere *foot1,*foot2;
*/
void giant::hide()
{
	head->hide();
	body->hide();
	arm1->hide();arm2->hide();
	hand1->hide();hand2->hide();
	butt->hide();
	thigh1->hide();thigh2->hide();
	foot1->hide();foot2->hide();
}

void giant::show()
{
	head->show();
	body->show();
	arm1->show();arm2->show();
	hand1->show();hand2->show();
	butt->show();
	thigh1->show();thigh2->show();
	foot1->show();foot2->show();
}
void giant::walk(float time,float speed)
{
	thigh1->setRotation('x',-30,'z',sin_d(time*180*speed)*25);
	foot1->setRotation('x',30,'y',sin_d(time*180*speed)*25);
	arm1->setRotation('x',50,'z',sin_d(time*180*speed)*25);
	hand1->setPosition(sin_d(time*180*speed)*0.5,hand1->getPosition().data[1],hand1->getPosition().data[2]);
	thigh2->setRotation('x',30,'z',-sin_d(time*180*speed)*25);
	foot2->setRotation('x',30,'y',-sin_d(time*180*speed)*25);
	arm2->setRotation('x',-50,'z',-sin_d(time*180*speed)*25);
	hand2->setPosition(-sin_d(time*180*speed)*0.5,hand2->getPosition().data[1],hand2->getPosition().data[2]);
}
