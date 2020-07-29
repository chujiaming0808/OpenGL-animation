// =========================================================================================


// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "cylinder.h"
#include "utility.h"

#define PI 3.141592653
#define RADIUS 2.0 
#define HEIGHT 2.0

// -----------------------------------------------------------------------------------------
// globals
extern vector<object3d*> gShapeVector;

// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

cylinder::cylinder(int density)
{
	setColour(1.0, 0.0, 0.0);					// default colour (red)
	setName("cylinder");
			

	vertexCount =2*density+2;
	faceCount =3*density;
	polygonCount = faceCount;

	// allocate memory for the vertex and face arrays
	vertices.resize(vertexCount);
	faces.resize(faceCount);


	for(int i = 0; i< density;i++)
	{
	    float yRot = i * (360.0 / density);
        float x = cos(yRot*PI/180.0);
        float z = sin(yRot*PI/180.0);
        vertices[i].set(x,1,z);
	

        vertices[i+density].set(x,-1,z);

	}
    vertices[2*density].set(0,1,0);
    vertices[2*density+1].set(0,-1,0);;



	//
	// 
	for(int i=0; i<density;i++)
	{
	    int j = (i+1) % density;				// j is (i+1) wrapped correctly
		
		faces[i].init(density*2,j,i);

			///init(density*2, j, i);					// top face
        //faces[i + density].init(density*2+1, i+density, j+density);	// bottom face
		faces[i+ density].init(density*2+1,i+density,j+density);

        //faces[i + density*2].init(i, j, j+density, i+density);		// side face
		faces[i+ density*2].init(i,j,j+density,i+density);
	}
	calculateNormals();
	diffuseShading = false;
	
	
	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}





