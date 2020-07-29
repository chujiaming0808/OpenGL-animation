#include "prefix.h"
#include "thief.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

thief::thief()
{
	// Initialise the object's state
	setName("thief");

	//身体
	body = new extrusion("dzbody.txt","dzbodypath.txt");
	body->useSmoothShading();
	body->setColour(0.408,0.667,0.91);//rgb(104,170,232)
	body->setRotation('x',90);
	body->setParent(this);
	body->setDeformation(1,1,1);

	//头的轮廓
	face = new extrusion("dzhead.txt","dzheadpath.txt");
	face->useSmoothShading();
	face->setColour(0.545,0.949,0.451);
	face->setDeformation(1,1,1);
	face->attachToParentAt(body,0,0,-3.9);

	//两个眼眶
	orbit1 = new sphere(10);
	orbit1->setColour(0,0,0);
	orbit1->setRotation( 'z',10,'x', 270);
	orbit1->setDeformation(0.8,0.4,0.01);
	orbit1->attachToParentAt(face,-0.8, 2, 0.1);

	orbit2 = new sphere(10);
	orbit2->setColour(0,0,0);
	orbit2->setRotation( 'z',-10,'x', 270);
	orbit2->setDeformation(0.8,0.4,0.01);
	orbit2->attachToParentAt(face,0.8, 2, 0.1);

	//哭的表情
	ceye1 = new cube();
	ceye1->setColour(0,0,0);
	ceye1->setRotation( 'y',10);
	ceye1->setDeformation(0.75,0.01,0.1);
	ceye1->attachToParentAt(face,-0.9, 2, 0.05);

	ceye2 = new cube();
	ceye2->setColour(0,0,0);
	ceye2->setRotation( 'y',-10);
	ceye2->setDeformation(0.75,0.01,0.1);
	ceye2->attachToParentAt(face,0.9, 2, 0.05);

	ceye1->hide();
	ceye2->hide();
	
	//两个眼睛
	eye1 = new sphere(10);
	eye1->setColour(1,1,1);
	eye1->setDeformation(0.75,0.32,0.01);
	eye1->attachToParentAt(orbit1,0,0,0.01);

	eye2 = new sphere(10);
	eye2->setColour(1,1,1);
	eye2->setDeformation(0.75,0.32,0.01);
	eye2->attachToParentAt(orbit2,0,0,0.01);

	//两个眼球
	ball1 = new sphere(10);
	ball1->setColour(0,0,0);
	ball1->setDeformation(0.03, 0.03, 0.01);
	ball1->attachToParentAt(eye1, 0.4, 0, 0.05);

	ball2 = new sphere(10);
	ball2->setColour(0,0,0);
	ball2->setDeformation(0.03, 0.03, 0.01);
	ball2->attachToParentAt(eye2, -0.4, 0, 0.05);

	
	//两个鼻子
	nose1 = new sphere(10);
	nose1->setColour(0,0,0);
	nose1->setRotation('x',90);
	nose1->setDeformation(0.08, 0.08, 0.01);
	nose1->attachToParentAt(face,0.2, 2.05, 0.8);	

	nose2 = new sphere(10);
	nose2->setColour(0,0,0);
	nose2->setRotation('x',90);
	nose2->setDeformation(0.08, 0.08, 0.01);
	nose2->attachToParentAt(face,-0.2, 2.05, 0.8);

	//嘴巴
	mouth = new extrusion("dzhead.txt","mouthpath.txt");
	mouth->useSmoothShading();
	mouth->setColour(0.545,0.949,0.451);
	mouth->attachToParentAt(face,0,1.5,3);

	//牙齿
	tooth1 = new extrusion("tooth.txt","toothpath.txt");
	tooth1->setRotation('y',180);
	tooth1->setDeformation(1,1,1.2);
	tooth1->setColour(1,1,1);
	tooth1->attachToParentAt(mouth,1.1,0.5,-3.3);

	tooth2 = new extrusion("tooth.txt","toothpath.txt");
	tooth2->setRotation('y',180);
	tooth2->setDeformation(1,1,1.2);
	tooth2->setColour(1,1,1);
	tooth2->attachToParentAt(mouth,-1.1,0.5,-3.3);

	//小牙
	tooth3 = new extrusion("lrbody.txt","stoothpath.txt");
	tooth3->setRotation('y',180);
	tooth3->setColour(1,1,1);
	tooth3->attachToParentAt(mouth,0.5,0.8,-2.8);

	tooth4 = new extrusion("lrbody.txt","stoothpath.txt");
	tooth4->setRotation('y',180);
	tooth4->setColour(1,1,1);
	tooth4->attachToParentAt(mouth,-0.5,0.8,-2.8);


	//耳朵
	ear1 = new sweep("ear.txt",100);
	ear1->useSmoothShading();
	ear1->setColour(0.545,0.949,0.451);
	ear1->setRotation('z',90,'y',-15);
	ear1->setDeformation(0.2,0.5,0.5);
	ear1->attachToParentAt(face,1.85, 0.1, 0.2);

	ear2 = new sweep("ear.txt",100);
	ear2->useSmoothShading();
	ear2->setColour(0.545,0.949,0.451);
	ear2->setRotation('z',-90,'y',15);
	ear2->setDeformation(0.2,0.5,0.5);
	ear2->attachToParentAt(face,-1.85, 0.1, 0.2);

	//袖子
	sleeve1 = new extrusion("sleeve.txt","sleevepath.txt");
	sleeve1->setColour(0.408,0.667,0.91);
	sleeve1->setRotation('y',80);
	sleeve1->setDeformation(0.45,0.5,1.2);
	sleeve1->attachToParentAt(body,3.1,0,-0.6);

	sleeve2 = new extrusion("sleeve.txt","sleevepath.txt");
	sleeve2->setColour(0.408,0.667,0.91);
	sleeve2->setRotation('y',-80);
	sleeve2->setDeformation(0.45,0.5,1.2);
	sleeve2->attachToParentAt(body,-3.1,0,-0.6);

	//手臂
	arm1 = new extrusion("arm.txt","armpath.txt");
	arm1->setColour(0.545,0.949,0.451);
	arm1->setRotation('y',150);
	arm1->setDeformation(0.52,0.52,0.4);
	arm1->attachToParentAt(sleeve1,0.5,0,-2);

	arm2 = new extrusion("arm.txt","armpath.txt");
	arm2->setColour(0.545,0.949,0.451);
	arm2->setRotation('y',-150);
	arm2->setDeformation(0.52,0.52,0.4);
	arm2->attachToParentAt(sleeve2,-0.5,0,-2);

	//短剑
	s1 = new sword(); 
	s1->setRotation('x',-120);
	s1->attachToParentAt(arm1,0,1.2,-2.3);
	

	s2 = new sword(); 
	s2->setRotation('x',-120);
	s2->attachToParentAt(arm2,0,1.2,-2.3);


	//裤子
	pants = new extrusion("pants.txt","pantspath.txt");
	pants->setColour(0.3765,0.2235,0.07);//96,57,18
	pants->attachToParentAt(body,0,0,1.8);

	//腿
	leg1 = new sweep("leg.txt",20);
	leg1->setColour(0.3765,0.2235,0.07);
	leg1->setRotation('x',90);
	leg1->setDeformation(0.6,0.8,0.6);
	leg1->attachToParentAt(pants,0.6,0,-1.8);

	leg2 = new sweep("leg.txt",20);
	leg2->setColour(0.3765,0.2235,0.07);
	leg2->setRotation('x',90);
	leg2->setDeformation(0.6,0.8,0.6);
	leg2->attachToParentAt(pants,-0.6,0,-1.8);

	//鞋子
	shoes1 = new sphere(10);
	shoes1->setColour(0,0,0);
	shoes1->setDeformation(0.2,0.1,0.3);
	shoes1->attachToParentAt(leg1,0, 1.83, -0.1);

	shoes2 = new sphere(10);
	shoes2->setColour(0,0,0);
	shoes2->setDeformation(0.2,0.1,0.3);
	shoes2->attachToParentAt(leg2,0, 1.83, -0.1);


	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}
/*
extrusion *face,*body;
		extrusion *sleeve1,*sleeve2;
		extrusion *pants;
		extrusion *arm1,*arm2;
		extrusion *mouth;
		extrusion *tooth1,*tooth2,*tooth3,*tooth4;
		sword *s1,*s2;
		sphere *eye1,*eye2;
		sphere *orbit1,*orbit2;
		sphere *ball1,*ball2;
		sphere *nose1,*nose2;
		sphere *shoes1,*shoes2;
		sweep *ear1,*ear2;
		sweep *leg1,*leg2;
*/
void thief::hide()
{
	body->hide();
	face->hide();
	sleeve1->hide();sleeve2->hide();
	pants->hide();
	arm1->hide();arm2->hide();
	mouth->hide();
	tooth1->hide();tooth2->hide();tooth3->hide();tooth4->hide();
	s1->hide();s2->hide();
	ceye1->hide();ceye2->hide();
	eye1->hide();eye2->hide();
	orbit1->hide();orbit2->hide();
	ball1->hide();ball2->hide();
	nose1->hide();nose2->hide();
	shoes1->hide();shoes2->hide();
	ear1->hide();ear2->hide();
	leg1->hide();leg2->hide();
}

void thief::show()
{
	body->show();
	face->show();
	sleeve1->show();sleeve2->show();
	pants->show();
	arm1->show();arm2->show();
	mouth->show();
	tooth1->show();tooth2->show();tooth3->show();tooth4->show();
	s1->show();s2->show();
	ceye1->show();ceye2->show();
	eye1->show();eye2->show();
	orbit1->show();orbit2->show();
	ball1->show();ball2->show();
	nose1->show();nose2->show();
	shoes1->show();shoes2->show();
	ear1->show();ear2->show();
	leg1->show();leg2->show();
}
void thief::walk(float time,float speed)
{
	leg1->setRotation('x',sin_d(time*180*speed)*20+90);
	arm1->setRotation('y',150,'x',-sin_d(time*180*speed)*5);
	leg2->setRotation('x',-sin_d(time*180*speed)*20+90);
	arm2->setRotation('y',-150,'x',sin_d(time*180*speed)*5);

}

void thief::talk(float time)
{
	mouth->setPosition(mouth->getPosition().data[0],mouth->getPosition().data[1],3+sin_d(time*180)*0.3);
}

void thief::turnAround(float time)//34-38
{
	float t = time -33;
	face->setRotation('z',-sin_d(t*18)*90,'y',sin_d(t*18)*30);
	mouth->setPosition(mouth->getPosition().data[0],mouth->getPosition().data[1],3+sin_d(t*18)*0.8);
}

void thief::reset()
{
	face->setRotation('z',0,'y',0);
	mouth->attachToParentAt(face,0,1.5,3);
}
void thief::cry()
{
	orbit1->hide();
	eye1->hide();
	ball1->hide();
	orbit2->hide();
	eye2->hide();
	ball2->hide();
	ceye1->show();
	ceye2->show();

}
void thief::riseHead(float time)
{
	float t = time - 59;
	face->setRotation('x',-sin_d(t*9)*60);
	mouth->setPosition(mouth->getPosition().data[0],mouth->getPosition().data[1],3+sin_d(t*9)*0.8);
}

void thief::dropWeapon(float time)
{
	float t = time - 59;
	s1->attachToParentAt(arm1,0,1.2+0.7*sin_d(t*18),-2.3-0.8*sin_d(t*18));
	s2->attachToParentAt(arm2,0,1.2+0.7*sin_d(t*18),-2.3-0.8*sin_d(t*18));
}
void thief::resetAll()
{
	face->setRotation('x',0);
	orbit1->show();
	eye1->show();
	ball1->show();
	orbit2->show();
	eye2->show();
	ball2->show();
	ceye1->hide();
	ceye2->hide();
	mouth->attachToParentAt(face,0,1.5,3);
	s1->attachToParentAt(arm1,0,1.2,-2.3);
	s2->attachToParentAt(arm2,0,1.2,-2.3);
	leg1->setRotation('x',90);
	leg2->setRotation('x',90);
	arm1->setRotation('y',150);
	arm2->setRotation('y',-150);
}