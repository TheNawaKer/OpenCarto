#include "Heightmap.hpp"

int main(){
	ilInit();
    iluInit();
    ilutInit();

	Heightmap heightmap("res/map.png");
	
	return 0;
}