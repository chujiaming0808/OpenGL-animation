// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// sword.h
//
// This file declares the class for sword objects, based on the
// generic 3D object


#ifndef _sword_H
#define _sword_H



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

// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class sword : public object3d
{
	public:
		sword();
		virtual void hide();
		virtual void show();
	private:
		extrusion *body;
		extrusion *pole;
		extrusion *grid;

};


#endif // _sword_H