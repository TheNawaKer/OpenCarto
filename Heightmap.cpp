#include "Heightmap.hpp"
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

Heightmap::~Heightmap(){
	delete [] map;
};