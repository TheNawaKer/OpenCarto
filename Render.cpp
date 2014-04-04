#include "Render.hpp"
#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;


Render::Render():heightmap("res/map.png"){
  gltextete= ReadPNGFromFile("res/map.png");
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
  generate_point();
  generate_indice();
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glVertexPointer(3,GL_FLOAT, 3*sizeof(GL_FLOAT),point);  
  glColorPointer(3, GL_FLOAT, 3*sizeof(GL_FLOAT),color);
}
void Render::render(){
  void* ptr = NULL;
  for (int i = 0; i < heightmap.getHeight()-1 ; ++i)
    glDrawElements(GL_TRIANGLE_STRIP, heightmap.getWidth()*2, GL_UNSIGNED_INT,ptr + i * heightmap.getWidth()*2 * sizeof(unsigned int));}

  void Render::generate_indice(){
    int cpt = 0;
    indices=new unsigned int[heightmap.getHeight()*heightmap.getWidth()*2];
    for (unsigned int i = 0; i < heightmap.getHeight(); ++i){
      cpt = i * heightmap.getWidth();
      for (unsigned int j = 0; j < heightmap.getWidth() * 2; j+=2){
        indices[(2*heightmap.getWidth())*i + j] = cpt;
        indices[(2*heightmap.getWidth())*i + j + 1] = cpt + heightmap.getWidth();
        cpt ++;
      }
    } 
  }

  void Render::generate_point(){
    point=new float[heightmap.getHeight()*heightmap.getWidth()*3];
    color=new float[heightmap.getHeight()*heightmap.getWidth()*3];
    int cpt = 0;
    int p=0;
    for (int i = 0; i < heightmap.getHeight(); ++i)
      for (int j = 0; j < heightmap.getWidth(); ++j){
        point[cpt] = j;
        point[cpt+1] = heightmap[p]*(15/100.0);
        point[cpt+2] = i;
        // if ( heightmap[p]-128 >= 90) {
        //   color[cpt] = 0.35f;
        //   color[cpt+1] = 0.16;
        //   color[cpt+2] = 0.16;
        // } else if ( heightmap[p]-128 >= 30) {
        //   color[cpt] = 0;
        //   color[cpt+1] = 1;
        //   color[cpt+2] = 0;
        // } else if ( heightmap[p]-128 >= -10 ) {
        //   color[cpt] = 0.2;
        //   color[cpt+1] = 0.2;
        //   color[cpt+2] = 0.9;
        // } else {
        //   color[cpt] = 0;
        //   color[cpt+1] = 0;
        //   color[cpt+2] = 1;
        // }

        cpt+=3;
        p++;
      }
      texture();

    }

    void Render::texture(){
      ILuint mapId;
      ilGenImages(1, &mapId);
      ilBindImage(mapId);
      ilLoadImage("res/texture.png");
      int width = ilGetInteger(IL_IMAGE_WIDTH);
      int height = ilGetInteger(IL_IMAGE_HEIGHT);
      ilCopyPixels(0, 0, 0, width, height, 1, IL_RGB,IL_FLOAT, color);
      ilBindImage(0);
      ilDeleteImage(mapId);
    }

    int Render::getHeight() const{
      return heightmap.getHeight();
    }

    int Render::getWidth() const{
      return heightmap.getWidth();
    }

    float* Render::getPoint(){
      return point;
    }

    float* Render::getColor(){
      return color;
    }

    unsigned int *  Render::getIndices(){
      return indices;
    }

    Render::~Render(){
     delete [] point;
     delete [] indices;
     delete [] color;
   }