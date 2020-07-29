// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// ax.h
//
// This file declares the class for ax objects, based on the
// generic 3D object


#ifndef _ax_H
#define _ax_H



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

class ax : public object3d
{
	public:
		ax();
		virtual void hide();
		virtual void show();
	private:
		extrusion *body;
		extrusion *pole;

};


#endif // _ax_H

