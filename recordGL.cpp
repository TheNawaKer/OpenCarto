/*
 *  recordGL.cpp
 *  glutmaster
 *
 *  Created by Emmanuel Melin on 24/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "recordGL.h"
#include <GL/glut.h>

#include <iostream>

using namespace std;

double now = 0;
double start_time =0;



recordGL::recordGL(std::string st,int sizeX, int sizeY){
	image=NULL;
	recording_on=false;
	
	filepath=st;
	image_sizeX=sizeX;
	image_sizeY=sizeY;
	cout<<"Recording activated on path : "<<filepath<<endl;
}


void recordGL::switch_recording(std::string st) {
	recording_on=!recording_on;
	if (recording_on)
		open_ppmfile(st);
	else
		close_ppmfile();
}

void recordGL::treat_recording() {
	string aux="/usr/bin/ffmpeg -b 2000k -f image2pipe -y   -vcodec ppm   -i "+filepath+"/"+filename+".ppm -f flv -pass 1 -y "+filepath+"/"+filename+".flv";
	string aux2="mencoder -vf flip -o "+filepath+"/"+filename+".flv -ovc lavc "+filepath+"/"+filename+".flv";
	if (recording_on)
		printf("error: opengl video is recording ...\n");
	else
	{
		system(aux.c_str());
		//system(aux2.c_str());
		system(string("rm "+filepath+"/"+filename+".ppm").c_str());
	}
}


void recordGL::open_ppmfile(std::string st){
	filename=st;
	string aux=filepath+"/"+filename+".ppm";
	if (( outputfile = fopen(aux.c_str(), "w")) == NULL) {
		perror("Can't open video recording ouput file\n");
	}
	recording_on=true;
	cout<<"Recording on file  : "<<filepath+"/"+filename<<endl;
	
};


void recordGL::close_ppmfile() {
	if (image!=NULL) {
		free(image);
		image=NULL;
		
		fclose(outputfile);
	}
	recording_on=false;
	printf("Recording stopped\n");
}

void recordGL::write_ppmfile() {
	if(recording_on){
		
		
			int image_size=image_sizeX*image_sizeY;
			
			if (image != NULL) {
				free(image);
				image=NULL;
			}
			
			if (image==NULL)
				image = (char*)malloc(image_size * sizeof(GLubyte) * 3);
			
			glPixelStorei(GL_PACK_ALIGNMENT, 1);
			glReadPixels(0, 0, image_sizeX, image_sizeY, GL_RGB, GL_UNSIGNED_BYTE, image);
			
			fprintf(outputfile,"P6\n");
			fprintf(outputfile,"# opengl video recorded from gla...\n");
			fprintf(outputfile,"%d %d\n",image_sizeX,image_sizeY);
			fprintf(outputfile,"255\n");
				
			fwrite(image,sizeof(char), image_size * 3 * sizeof(GLubyte),outputfile);
		
	}
}
