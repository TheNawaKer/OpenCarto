all: Heightmap.cpp Heightmap.hpp Render.cpp Render.hpp main.cpp
	g++ Heightmap.cpp main.cpp Render.cpp -o out -lIL -lILU -lILUT -std=c++11