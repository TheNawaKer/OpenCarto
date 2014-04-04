#include "Heightmap.hpp"
#include <iostream>
using namespace std;

Heightmap::Heightmap(string file):mapId(0){
	ilGenImages(1, &mapId);
	ilBindImage(mapId);
	ilLoadImage(file.c_str());
	width = ilGetInteger(IL_IMAGE_WIDTH);
	height = ilGetInteger(IL_IMAGE_HEIGHT);
	map = new BYTE[width * height * 3];
	ilCopyPixels(0, 0, 0, width, height, 1, IL_RGB,IL_UNSIGNED_BYTE, map);
	ilBindImage(0);
	ilDeleteImage(mapId);
}

void Heightmap::show(ostream & os) const{
	for(int i=0;i<height*width;i++){
		if(i%width==0){
			os<<endl;
		}
		os<<"[";
		os<<operator()(i,0);
		os<<"],";
	}
}

int Heightmap::operator() (int i,int j) const{
	return (int)map[j*width +i*3];
}

Heightmap::~Heightmap(){
	delete [] map;
};

ostream & operator<<(ostream & os,const Heightmap & h){
	h.show(os);
	return os;
}

int Heightmap::getWidth() const{
	return width;
}

int Heightmap::getHeight() const{
	return height;
}