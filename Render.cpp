#include "Render.hpp"

Render::Render(const Heightmap & h){
	const int height = h.getHeight();
	const int width = h.getWidth();
	point=new int[height][width];
	for (int i=0;i<h.getHeight();i++){
		for(int j=0;j<h.getWidth();j++){
			point[i*h.getHeight()+j]=i;
			point[i*h.getHeight()+j+1]=j;
			point[i*h.getHeight()+j+2]=h[i*h.getHeight()+j];
		}
	}
}
void Render::render() const{

}

Render::~Render(){
	delete [] point;
}