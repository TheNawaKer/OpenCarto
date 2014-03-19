#include "Heightmap.hpp"
#include <iostream>
using namespace std;

int main(){
	ilInit();
    iluInit();
    ilutInit();

	Heightmap heightmap("res/map.png");
	cout<<heightmap<<endl;
	return 0;
}