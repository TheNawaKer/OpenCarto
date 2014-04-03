#include "Render.hpp"
#include <GL/glut.h>
#include <iostream>
using namespace std;


Render::Render():heightmap("res/heightmap.jpg"){
	point=new float[heightmap.getHeight()*heightmap.getWidth()*3];
	color=new float[heightmap.getHeight()*heightmap.getWidth()*3];
	int p=0;
	int c=0;
	for (int i=0;i<heightmap.getHeight();i++){
		for(int j=0;j<heightmap.getWidth();j++){
			point[p]=i;
            if ( heightmap[i + j * heightmap.getWidth()] >= (90 * 10)) {
                point [ p + 1 ] = heightmap[i + j * heightmap.getWidth()];
                color[c] = 0.35;
                color[c+1] = 0.16;
                color[c+2] = 0.16;
            } else if ( heightmap[i + j * heightmap.getWidth()] >= (30*10)) {
                point [ p + 1 ] = heightmap[i + j * heightmap.getWidth()];
                color[c] = 0;
                color[c+1] = 1;
                color[c+2] = 0;
            } else if ( heightmap[i + j * heightmap.getWidth()] >= (-10 * 10) ) {
                point [ p + 1 ] = -10*10;
                color[c] = 0.2;
                color[c+1] = 0.2;
                color[c+2] = 0.9;
            } else {
                point [ p + 1 ] = -10*10;
                color[c] = 0;
                color[c+1] = 0;
                color[c+2] = 1;
            }
            point[p+2]=j;
			p+=3;
			c+=3;
		}
	}
	generate_indice();
}
void Render::render(){
	glColor3d(1,1,1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer ( 3, GL_FLOAT, 0, point);
	glColorPointer(3, GL_FLOAT, 0, color);
	cout<<"start"<<endl;
	for ( int i = 0 ; i < heightmap.getHeight() - 1 ; i++) { 
		cout<<i<<endl;
		glDrawElements( GL_TRIANGLE_STRIP , heightmap.getHeight()*heightmap.getWidth() , GL_UNSIGNED_INT, &indices[heightmap.getHeight() * heightmap.getWidth() * i]);
	}
}

void Render::generate_indice(){
	indices=new int[heightmap.getHeight()*heightmap.getWidth()*2];
    int c = 0;
    for ( int i = 0 ; i < heightmap.getHeight() ; i++) {
    	for ( int j = 0 ; j < heightmap.getWidth() ; j++ ) {
    	    indices[c] = j + i * heightmap.getHeight();
    	    indices[c+1] = j + heightmap.getWidth() + i * heightmap.getHeight();
    	    c+=2;
    	}
    }
}

Render::~Render(){
	delete [] point;
}