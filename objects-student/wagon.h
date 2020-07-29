// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// wagon.h
//
// This file declares the class for wagon objects, based on the
// generic 3D object


#ifndef _wagon_H
#define _wagon_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include "cylinder.h"
#include "tcube.h"
#include "torus.h"
#include "texture.h"


// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class wagon : public object3d
{
	public:
		wagon();
		virtual void hide();
		virtual void show();
	private:
		cylinder *pole1,*pole2;
		tcube *bottom,*front,*side1,*side2;
		torus *wheel1,*wheel2;
		texture *wood;

};


#endif // _wagon_H

