#ifndef RENDER
#define RENDER

#include "Heightmap.hpp"

struct Point{
	int x;
	int y;
	int z;
};

class Render{
private:
	int * point;
public:
	Render(const Heightmap & h);
	void render() const;
	~Render();
};

#endif