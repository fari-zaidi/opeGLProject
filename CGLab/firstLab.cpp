#include <Windows.h> 
#include <GL\glew.h> 
#include <GL\freeglut.h>
#include <iostream>
#include <fstream>
#include <mmsystem.h>
#include "SOIL.h"
using namespace std;
int y = 0;
void init()
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);

	B = SOIL_load_OGL_texture(
		"screenshot2.png",
		SOIL_LOAD_RGBA,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	/*M = SOIL_load_OGL_texture(
	"walk.png",
	SOIL_LOAD_RGBA,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);*/


	PlaySound(TEXT("Footsteps"), NULL, SND_ASYNC | SND_LOOP);

}

void myDisplay(void)
{

	glColor3f(0, 0 , 1);  //border
	glBegin(GL_POLYGON);
	glVertex2d(0, 0);
	glVertex2d(800, 0);
	glVertex2d(800, 600);
	glVertex2d(0, 600);
	glEnd();

	glColor3f(0 ,0, 0.1); //road
	glVertex2d(200, 0);
	glVertex2d(600, 0);
	glVertex2d(600, 600);
	glVertex2d(200, 600);
	glEnd();

	/*glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(350, 20);
	glVertex2d(450, 20);
	glVertex2d(450, 20+30);
	glVertex2d(350, 20+30);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(200, 10);
	glVertex2d(600, 10);
	glVertex2d(600, 590);
	glVertex2d(200, 590);
	glEnd();*/

	glPushMatrix();
	glTranslated(0, y, 0);
	for (int i = 50; i <= 800; i=i+80)
	{
		glColor3f(1, 1, 1);  //1 border
		glBegin(GL_POLYGON);
		glVertex2d(390, y+i);
		glVertex2d(410, y+i);
		glVertex2d(410, y+i+50);
		glVertex2d(390, y+i+50);
		glEnd();
	}
	
	glPopMatrix();
	if (y <= -100 )
	{
		y = 0;
	}

	glColor3f(1, 1, 0);  //car
	glBegin(GL_POLYGON);
	glVertex2d(250,100);
	glVertex2d(300, 100);
	glVertex2d(300, 150);
	glVertex2d(250, 150);
	glEnd();

	glColor3f(1, 1, 0);  //car
	glBegin(GL_POLYGON);
	glVertex2d(255, 150);
	glVertex2d(295, 150);
	glVertex2d(295, 170);
	glVertex2d(255, 170);
	glEnd();



	




	glutSwapBuffers();
}
void titlePage()
{
	glClearColor(0.75, 0.75, 0.75, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glColor3f(0.75, 0.75, 0.75);

	glBindTexture(GL_TEXTURE_2D, B);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_POLYGON);
	glTexCoord2d(1, 0);
	glVertex2d(0, 0);
	glTexCoord2d(0, 0);
	glVertex2d(500, 0);
	glTexCoord2d(0, 1);
	glVertex2d(500, 500);
	glTexCoord2d(1, 1);
	glVertex2d(0, 500);

	glEnd();
	glDisable(GL_BLEND);

 void timer(int t)
{
	y--;
	myDisplay();
	t++;
	glutTimerFunc(100,timer,t);
}
int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode( GLUT_DOUBLE |GLUT_RGB);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("First_CG_Lab");
	// Bind the two functions (above) to respond when necessary


	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.

	glutDisplayFunc(myDisplay);
	glutTimerFunc(100, timer, 1);

	glutMainLoop();
	return 0;
}
