#include "Window.hpp"
using namespace std;

static int zoom=0;

Window::Window(int x,int y,string titre){
	win=this;
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glDepthMask(GL_TRUE);
	glutInitWindowSize (x, y);
	glutInitWindowPosition (0, 0);
	glutCreateWindow("OpenCarto");
	//ACTIVATION ETAT
	glShadeModel(GL_SMOOTH);  // Permet un joli ombrage
	glClearColor (0.0, 0.0, 0.0, 0.0); //√àtabli vers quelle couleur la fen√çtre sera vid√àe
	glClearDepth(1.0f);       // Mis en place du tampon de profondeur
    glEnable(GL_DEPTH_TEST);  // Mis en place du test de profondeur
    glDepthFunc(GL_LEQUAL);      // Le type de test de profondeur 
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Très jolis calculs de perspective
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Filtered
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
    // glEnable(GL_TEXTURE_2D);
    // gltextete= ReadPNGFromFile("/home/furet/opengl/logo/briques.png");
    // glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

    //linkage des fonctions
    glutReshapeFunc(Window::reshapeFct);
    glutKeyboardFunc(Window::keyFct);
    glutDisplayFunc(Window::displayFct); 
    glutIdleFunc(Window::idleFct); 

    glutMainLoop();
}


void Window::reshape(int w,int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(70.0, (GLfloat) w/(GLfloat) h, 0.01, 30.0);
	glMatrixMode(GL_MODELVIEW);
}

void Window::display(void){
	framerate();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //vide r√àellement la fen√çtre
	glLoadIdentity();
	glTranslated(0,0,zoom-5);
	render.render();
	glutSwapBuffers();
}

void Window::idle(){
	framerate();
}

void Window::framerate(void){
	static int frame=0,time,timebase=0;
	static char titre[100];
	
	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(titre,"FPS:%4.2f",
				frame*1000.0/(time-timebase));
		glutSetWindowTitle(titre);	
		timebase = time;		
		frame = 0;
	}
}

void Window::key(unsigned char key , int x , int y ){
	switch ( key ) {
		case 'w'  : zoom-=0.1f;		
			break;
		case 'x'  : zoom+=0.1f;					
			break;	
		case GLUT_KEY_F1 : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
		case GLUT_KEY_F2 : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;

		case GLUT_KEY_LEFT : zoom-=0.1;
			break; 
		case GLUT_KEY_RIGHT : zoom+=0.1; 
			break; 		
		case 0x1B : exit(0); 
	}
		glutPostRedisplay();
}