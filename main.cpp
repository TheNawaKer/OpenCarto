#include "Heightmap.hpp"
#include "Window.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <GL/glut.h>

using namespace std;

int main(int argc, char ** argv){
	ilInit();
    iluInit();
    ilutInit();
   	srand(time(NULL));
	glutInit(&argc, argv); 

	Heightmap heightmap("res/map.png");
	Window window;
	return 0;
}