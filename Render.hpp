#ifndef RENDER
#define RENDER

#include "Heightmap.hpp"

class Render{
private:
	float * point;
	int * indices;
	float * color;

	Heightmap heightmap;
public:
	Render();
	void render();
	void generate_indice();
	~Render();
};

#endif