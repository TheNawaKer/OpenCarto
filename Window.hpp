#ifndef WINDOW
#define WINDOW

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Render.hpp"

class Window {
private:
	//Camera camera;
	Render render;
	float zoom;
	float moveX,moveY;
public:

	static Window * win;
	Window(int x=640,int y=480,std::string titre="Test");
	void framerate(void);
	void reshape(int w,int h);
	void display(void);
	void key(unsigned char key , int x , int y );
	void GestionSpecial(int key, int x, int y);
	void idle();
	void initVBOs();

	static void framerateFct(){
		win->framerate();
	}

	static void GestionFct(int key, int x, int y){
		win->GestionSpecial(key,x,y);
	}

	static void idleFct(){
		win->idle();
	}

	static void reshapeFct(int w,int h){
		win->reshape(w,h);
	}

	static void displayFct(){
		win->display();
	}

	static void keyFct(unsigned char key , int x , int y ){
		win->key(key,x,y);
	}

};
#endif
