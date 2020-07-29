// generic 3D object


#ifndef _hunter_H
#define _hunter_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "extrusion.h"
#include "sphere.h"
#include "sweep.h"
#include "ax.h"
#include "terrain.h"
#include "arrow.h"

// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class hunter : public object3d
{
	public:
		hunter();
		virtual void hide();
		virtual void show();
		void walk(float time,float speed);
		void shoot(float time);
		arrow* getArrow();
		void riseHead(float time);
		void dropWeapon(float time);	
		void resetAll();
		//void calibrate(terrain *ground);//和世界坐标轴校准y坐标。
	private:
		extrusion *head;
		extrusion *mouth;
		extrusion *nose;
		extrusion *hair;
		extrusion *tooth1,*tooth2;
		extrusion *neck;
		extrusion *body;
		extrusion *hand1,*hand2,*arm1,*arm2;
		extrusion *leg1,*leg2;
		extrusion *bow;
		arrow *aw;
		extrusion *ear1,*ear2;
		ax *a;
		sphere *orbit1,*orbit2;
		sphere *weye1,*weye2;
		sphere *beye1,*beye2;
		sphere *eye1,*eye2;
		sphere *foot1,*foot2;
};


#endif // _hunter_H