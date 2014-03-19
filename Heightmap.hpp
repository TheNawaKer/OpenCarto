#ifndef HEIGHTMAP
#define HEIGHTMAP

#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#include <iostream>

typedef unsigned char BYTE;

class Heightmap{
private:
	ILuint mapId;
	BYTE * map;
	int width;
	int height;
public:
	Heightmap(std::string file);
	~Heightmap();
};


#endif