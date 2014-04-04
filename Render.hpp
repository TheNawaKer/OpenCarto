#ifndef RENDER
#define RENDER

#include "Heightmap.hpp"
#include "readpng.h"

class Render{
private:
	float * point;
	unsigned int * indices;
	float * color;

	int size;
	gl_texture_t* gltextete;
	Heightmap heightmap;
public:
	Render();
	void render();
	void generate_indice();
	void generate_point();
	int getHeight() const;
	int getWidth() const;

	float* getPoint();
	float* getColor();
	unsigned int * getIndices();
	~Render();
};

#endif