#ifndef RENDER
#define RENDER

#include "Heightmap.hpp"

class Render{
private:
	float * point;
	int * indices;

	Heightmap heightmap;
public:
	Render();
	void render();
	~Render();
};

#endif