#include "Render.hpp"
#include <GL/glut.h>


Render::Render():heightmap("res/heightmap.jpg"){
	const int height = heightmap.getHeight();
	const int width = heightmap.getWidth();
	point=new float[height*width];
	int p=0;
	for (int i=0;i<heightmap.getHeight();i++){
		for(int j=0;j<heightmap.getWidth();j++){
			point[p]=i;
			point[p+1]=j;
			point[p+2]=heightmap[i*heightmap.getHeight()+j];
			p+=3;
		}
	}
}
void Render::render(){
	// glColor3d(1,1,1);
	// glEnableClientState(GL_VERTEX_ARRAY);
	// glEnableClientState(GL_COLOR_ARRAY);
	// glVertexPointer ( 3, GL_FLOAT, 0, h.get_point() );
	// glColorPointer(3, GL_FLOAT, 0, h.get_color());
	// int w = h.get_w();
	// for ( int i = 0 ; i < w - 1 ; i++) { 
	// 	glDrawElements( GL_TRIANGLE_STRIP , h.get_w()*2 , GL_UNSIGNED_INT, &h.get_vertex()[w * 2 * i]);
	// }
}

Render::~Render(){
	delete [] point;
}