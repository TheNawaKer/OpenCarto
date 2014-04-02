#ifndef WINDOW
#define WINDOW

#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

class Window {
	public:
	Window(int x=640,int y=480,std::string titre="Test");
};

void framerate(void);
void reshape(int w,int h);
void display(void);
void key(unsigned char key , int x , int y );

#endif
