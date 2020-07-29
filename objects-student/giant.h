// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// giant.h
//
// This file declares the class for giant objects, based on the
// generic 3D object


#ifndef _giant_H
#define _giant_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include "cylinder.h"
#include "tcube.h"
#include "torus.h"
#include "texture.h"
#include "extrusion.h"
#include "sweep.h"
#include "tsphere.h"

// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class giant : public object3d
{
	public:
		giant();
		virtual void hide();
		virtual void show();
		void walk(float time,float speed);
	private:
		texture *faceStone,*stone,*patternStone,*patternStone2,*thighStone,*footStone;
		tsphere *head;
		tsphere *body;
		tsphere *arm1,*arm2;
		tsphere *hand1,*hand2;
		tsphere *butt;
		tsphere *thigh1,*thigh2;
		tsphere *foot1,*foot2;

};


#endif // _giant_H