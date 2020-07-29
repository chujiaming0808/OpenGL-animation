// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// arrow.h
//
// This file declares the class for arrow objects, based on the
// generic 3D object


#ifndef _arrow_H
#define _arrow_H



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

class arrow : public object3d
{
	public:
		arrow();
		virtual void hide();
		virtual void show();
		void move(float time);
	private:
		extrusion *body;
		extrusion *head;
		extrusion *feather1,*feather2;

};


#endif // _arrow_H

