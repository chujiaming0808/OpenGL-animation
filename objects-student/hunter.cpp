#include "prefix.h"
#include "hunter.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

hunter::hunter()
{
	// Initialise the object's state
	setName("hunter");
	//ÉíÌå
	body = new extrusion("lrbody.txt","lrbodypath.txt");
	body->useSmoothShading();
	body->setColour(0.251,0.2,0.188);//rgb(64,51,48)
	body->setParent(this);

	//²±×Ó
	neck = new extrusion("lrneck.txt","lrneckpath.txt");
	neck->setColour(0.353,0.745,0.847);
	neck->setDeformation(1.4,1.4,0.7);
	neck->attachToParentAt(body,0,0,-2);

	//Í·µÄÂÖÀª
	head = new extrusion("lrhead.txt","lrheadpath.txt");
	head->useSmoothShading();
	head->setColour(0.353,0.745,0.847);//(90,190,216)
	head->setRotation('y',45);
	head->setDeformation(1,0.8,1);
	head->attachToParentAt(neck,0,0,-1.3);

	//×ì°Í
	mouth = new extrusion("lrmouth.txt","lrmouthpath.txt");
	mouth->setColour(0.353,0.745,0.847);
	mouth->setRotation('y',130);
	mouth->setDeformation(1,0.5,1);
	mouth->attachToParentAt(head,0.5,0,0.5);

	//±Ç×Ó
	nose = new extrusion("lrnose.txt","lrnosepath.txt");
	nose->useSmoothShading();
	nose->setColour(0.353,0.745,0.847);
	nose->setRotation('y',-155);
	nose->setDeformation(1.25,1.25,1.6);
	nose->attachToParentAt(head,0.035,0,0.2);

	//Í··¢
	hair = new extrusion("lrhair.txt","lrhairpath.txt");
	hair->setColour(0.545,0.949,0.451);
	hair->setRotation('x',-90,'y',-30);
	hair->setDeformation(1.6,1.8,1.5);
	hair->attachToParentAt(head,0.4,-0.2,-0.9);

	//ÑÛ¿ô
	orbit1 = new sphere(10);
	orbit1->setColour(0.1,0.1,0.1);
	orbit1->setRotation( 'x', 88.5,'z',-20);
	orbit1->setDeformation(0.3,0.3,0.01);
	orbit1->attachToParentAt(head,0.4,0.88,0.4);

	orbit2 = new sphere(10);
	orbit2->setColour(0.1,0.1,0.1);
	orbit2->setRotation( 'x', 88.5,'z',20);
	orbit2->setDeformation(0.3,0.3,0.01);
	orbit2->attachToParentAt(head,0.4,-0.88,0.4);

	//ÑÛ°×
	weye1 = new sphere(10);
	weye1->setColour(1,1,1);
	weye1->setDeformation(0.25,0.25,0.01);
	weye1->attachToParentAt(orbit1,0,0,-0.01);

	weye2 = new sphere(10);
	weye2->setColour(1,1,1);
	weye2->setDeformation(0.25,0.25,0.01);
	weye2->attachToParentAt(orbit2,0,0,0.01);

	//ÑÛºÚ
	beye1 = new sphere(10);
	beye1->setColour(0,0,0);
	beye1->setRotation('z',30);
	beye1->setDeformation(0.12,0.17,0.01);
	beye1->attachToParentAt(weye1,0,0,-0.01);

	beye2 = new sphere(10);
	beye2->setColour(0,0,0);
	beye2->setRotation('z',30);
	beye2->setDeformation(0.12,0.17,0.01);
	beye2->attachToParentAt(weye2,0,0,0.01);

	//ÑÛÇò
	eye1 = new sphere(10);
	eye1->setColour(1,1,1);
	eye1->setDeformation(0.02,0.02,0.01);
	eye1->attachToParentAt(beye1,0,-0.09,-0.01);

	eye2 = new sphere(10);
	eye2->setColour(1,1,1);
	eye2->setDeformation(0.02,0.02,0.01);
	eye2->attachToParentAt(beye2,0,-0.09,0.01);

	//¶ú¶ä
	ear1 = new extrusion("lrmouth.txt","lrearpath.txt");
	ear1->useSmoothShading();
	ear1->setColour(0.353,0.745,0.847);//(90,190,216)
	ear1->setRotation('x',-50);
	ear1->attachToParentAt(head,-0.2,2,0.6);

	ear2 = new extrusion("lrmouth.txt","lrearpath.txt");
	ear2->useSmoothShading();
	ear2->setColour(0.353,0.745,0.847);//(90,190,216)
	ear2->setRotation('x',50);
	ear2->attachToParentAt(head,-0.2,-2,0.6);

	//ÑÀ³Ý
	tooth1 = new extrusion("tooth.txt","toothpath.txt");
	tooth1->setColour(1,1,1);
	tooth1->setRotation('x',-30);
	tooth1->attachToParentAt(mouth,-0.4,1.2,0);

	tooth2 = new extrusion("tooth.txt","toothpath.txt");
	tooth2->setColour(1,1,1);
	tooth2->setRotation('x',30);
	tooth2->attachToParentAt(mouth,-0.4,-1.2,0);

	//ÊÖ±Û
	arm1 = new extrusion("lrneck.txt","lrarmpath.txt");
	arm1->setColour(0.353,0.745,0.847);
	arm1->setRotation('x',-50);
	arm1->attachToParentAt(body,0,0.4,-0.8);

	arm2 = new extrusion("lrneck.txt","lrarmpath.txt");
	arm2->setColour(0.353,0.745,0.847);
	arm2->setRotation('x',50);
	arm2->attachToParentAt(body,0,-0.4,-0.8);

	//ÊÖ
	hand1 = new extrusion("lrneck.txt","lrhandpath.txt");
	hand1->setColour(0.353,0.745,0.847);
	hand1->setRotation('y',50);
	hand1->attachToParentAt(arm1,0,0,0.75);

	hand2 = new extrusion("lrneck.txt","lrhandpath.txt");
	hand2->setColour(0.353,0.745,0.847);
	hand2->setRotation('y',50);
	hand2->attachToParentAt(arm2,0,0,0.75);

	//¹­
	bow = new extrusion("lrbody.txt","bowpath.txt");
	bow->setColour(1.53,0.506,0.439);//rgb(237,129,112)
	bow->setRotation('y',50);
	bow->setDeformation(0.2,0.2,0.4);
	bow->attachToParentAt(hand1,-0.4,0,-0.3);

	//¼ý
	aw = new arrow();
	aw->setRotation('y',90);
	aw->attachToParentAt(body,2,0.85,-1.3);
	aw->hide();

	//¸«Í·
	a = new ax();
	a->setRotation('y',-30,'z',90);
	a->attachToParentAt(body,-0.6,-0.2,0.5);

	//ÍÈ
	leg1 = new extrusion("lrneck.txt","lrlegpath.txt");
	leg1->setColour(0.353,0.745,0.847);
	leg1->attachToParentAt(body,0,0.2,1.5);

	leg2 = new extrusion("lrneck.txt","lrlegpath.txt");
	leg2->setColour(0.353,0.745,0.847);
	leg2->attachToParentAt(body,0,-0.2,1.5);

	//½Å
	foot1 = new sphere(10);
	foot1->setColour(0.353,0.745,0.847);
	foot1->setRotation('x',90);
	foot1->setDeformation(0.2,0.05,0.1);
	foot1->attachToParentAt(leg1,0.1, 0, 1.4);

	foot2 = new sphere(10);
	foot2->setColour(0.353,0.745,0.847);
	foot2->setRotation('x',90);
	foot2->setDeformation(0.2,0.05,0.1);
	foot2->attachToParentAt(leg2,0.1, 0, 1.4);

	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);

}
/*
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
		extrusion *ear1,*ear2;
		ax *a;
		sphere *orbit1,*orbit2;
		sphere *weye1,*weye2;
		sphere *beye1,*beye2;
		sphere *eye1,*eye2;
		sphere *foot1,*foot2;
*/
void hunter::hide()
{
	head->hide();
	mouth->hide();
	nose->hide();
	hair->hide();
	tooth1->hide();tooth2->hide();
	neck->hide();
	body->hide();
	hand1->hide();hand2->hide();arm1->hide();arm2->hide();
	leg1->hide();leg2->hide();
	bow->hide();
	aw->hide();
	ear1->hide();ear2->hide();
	a->hide();
	orbit1->hide();orbit2->hide();
	weye1->hide();weye2->hide();
	beye1->hide();beye2->hide();
	eye1->hide();eye2->hide();
	foot1->hide();foot2->hide();
}

void hunter::show()
{
	head->show();
	mouth->show();
	nose->show();
	hair->show();
	tooth1->show();tooth2->show();
	neck->show();
	body->show();
	hand1->show();hand2->show();arm1->show();arm2->show();
	leg1->show();leg2->show();
	bow->show();
	aw->show();
	ear1->show();ear2->show();
	a->show();
	orbit1->show();orbit2->show();
	weye1->show();weye2->show();
	beye1->show();beye2->show();
	eye1->show();eye2->show();
	foot1->show();foot2->show();
}
/*
void hunter::calibrate(terrain *ground)
{
	printf("%f\n",foot1->getPosition().data[2]);
	setPosition(getPosition().data[0],-(-foot1->getPosition().data[2]-ground->rawelevation(getPosition().data[0],getPosition().data[2])),getPosition().data[2]);
	printf("%f %f\n",getPosition().data[1],ground->rawelevation(getPosition().data[0],getPosition().data[2]));
}*/
void hunter::walk(float time,float speed)
{
	leg1->setRotation('y',sin_d(time*180*speed)*25);
	hand1->setRotation('y',-sin_d(time*180*speed)*25);
	leg2->setRotation('y',-sin_d(time*180*speed)*25);
	hand2->setRotation('y',sin_d(time*180*speed)*25);
}

void hunter::shoot(float time)//46-50
{
	float t = time - 40;
	arm1->setRotation('x',-50,'y',sin_d(t*18)*90);
	hand1->setRotation('y',50,'z',-sin_d(t*18)*90,'x',sin_d(t*15)*30);
	hand2->setRotation('y',50,'x',sin_d(t*18)*120);
}

arrow* hunter::getArrow()
{
	return aw;
}

void hunter::riseHead(float time)//60-70
{
	float t = time - 59;
	head->setRotation('y',45+sin_d(t*9)*60);
}

void hunter::dropWeapon(float time)
{
	float t = time - 59;
	arm1->setRotation('x',-50,'y',-sin_d(t*18)*90);
	hand1->setRotation('y',50,'z',sin_d(t*18)*90,'x',-sin_d(t*15)*30);
	hand2->setRotation('y',50,'x',-sin_d(t*18)*120);
	bow->setPosition(-1.5*sin_d(t*18),-1.5*sin_d(t*18),0);
}

void hunter::resetAll()
{	
	head->setRotation('y',45);
	arm1->setRotation('x',-50);
	arm2->setRotation('x',50);
	hand1->setRotation('y',50);
	hand2->setRotation('y',50);
	bow->attachToParentAt(hand1,-0.4,0,-0.3);
	aw->setRotation('y',90);
	aw->attachToParentAt(body,2,0.85,-1.3);
	
	
}