#ifndef RENDER
#define RENDER

#include "Heightmap.hpp"

class Render{
private:
	float * point;
	unsigned int * indices;
	float * color;

	int size;
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