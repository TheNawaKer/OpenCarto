/*
 *  recordGL.h
 *  exemple
 *
 *  Created by Emmanuel Melin on 09/12/10.
 *  Copyright 2010 LIFO. All rights reserved.
 *
 */
#ifndef config_h
#define config_h

#endif

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class recordGL{
public:
	bool recording_on;
	
	 char *image;
	 int image_sizeX;
	int image_sizeY;
 	 FILE *outputfile;
	string filepath,filename;
	double frame,time,timebase;
	
	
	void write_ppmfile() ;
	recordGL(std::string st,int sizeX=704, int sizeY=576);
	void open_ppmfile(std::string st);
	void close_ppmfile();
	void treat_recording();
	void switch_recording(std::string st) ;
	
};
