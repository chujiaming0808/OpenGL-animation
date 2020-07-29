// generic 3D object


#ifndef _thief_H
#define _thief_H



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
#include "sphere.h"
#include "sweep.h"
#include "sword.h"
#include "cube.h"


// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class thief : public object3d
{
	public:
		thief();
		virtual void hide();
		virtual void show();

		//animation
		void walk(float time,float speed);
		void talk(float time);
		void turnAround(float time);
		void reset();
		void cry();
		void riseHead(float time);
		void dropWeapon(float time);
		void resetAll();
	private:
		extrusion *face,*body;
		extrusion *sleeve1,*sleeve2;
		extrusion *pants;
		extrusion *arm1,*arm2;
		extrusion *mouth;
		extrusion *tooth1,*tooth2,*tooth3,*tooth4;
		sword *s1,*s2;
		cube *ceye1,*ceye2;
		sphere *eye1,*eye2;
		sphere *orbit1,*orbit2;
		sphere *ball1,*ball2;
		sphere *nose1,*nose2;
		sphere *shoes1,*shoes2;
		sweep *ear1,*ear2;
		sweep *leg1,*leg2;
		
};


#endif // _thief_H