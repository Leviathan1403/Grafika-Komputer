
#define _USE_MATH_DEFINES 

#include <cstdlib>
#include <cmath>

#include <GL/glut.h>


int object = 0;
float xmove[]{ 0, 0 };
float ymove[]{ 0, 0 };
float zmove[]{ 0, 0 };

float degree = 0;
float xscale = 1, yscale = 1, zscale = 1;

void keyboard(int button, int x, int y)
{
    switch (button)
    {
        case GLUT_KEY_F1: object = 0; break;
        case GLUT_KEY_F2: object = 1; break;
        case GLUT_KEY_LEFT: xmove[object] -= 0.1; break;
        case GLUT_KEY_RIGHT: xmove[object] += 0.1; break;
        case GLUT_KEY_DOWN:  ymove[object] -= 0.1; break;
        case GLUT_KEY_UP: ymove[object] += 0.1; break;
        case GLUT_KEY_PAGE_UP: zmove[object] -= 0.1; break;
        case GLUT_KEY_PAGE_DOWN: zmove[object] += 0.1; break;
    }
    glutPostRedisplay();
}

void Settings()
{
    glClearColor(1,1,1,0);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT , GL_NICEST);
}

void drawScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Place scene in frustum.
	glTranslatef(-1, 0, -5);
	glScalef(2,2,2);

	glPushMatrix();
	//naruh
	glTranslatef(0.0, 0.0, -4.0);
	//skala
	glScalef(2,4,0.1);

	// kotak belakang.
	glColor3f(0, 0., 0.);
	glutWireCube(1.01);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	
	//////////////////////////////////////////////////////////////

	glPushMatrix();

	//naruh
	glTranslatef(-1.0, 0.0, -3.5);
	//skala
	glScalef(0.1,4,1);

	// kotak kiri
	glColor3f(0, 0, 0);
	glutWireCube(1.01);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(1);

	
	glPopMatrix();
	/////////////////////////////////////////////////////////////////////////////

	glPushMatrix();

	//naruh
	glTranslatef(1, 0.0, -3.5);
	//skala
	glScalef(0.1,4,1);
	//
	// 

	// kotak kanan
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1.01);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(1);

	glPopMatrix();

////////////////////////////////////////////////////////

	glPushMatrix();
	//ref belakang = 2 4 0.1
	// ref lokasi belakang = -1 0 -4
	//kotak bawah
	glTranslatef(-0.1, -2.3, -4.5);
	glScalef(2.2,0.1,1.1);
	glColor3f(0, 0, 0);
	glutWireCube(1.01);
	glColor3f(0.4, 0.4, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//kotak tengah
	
	glTranslatef(-0.1, -0.8, -4.5);
	glScalef(2.2,0.1,1.1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1.01);
	glColor3f(0.4, 0.4, 0.4);
	glutSolidCube(1);

	glPopMatrix();

	glPushMatrix();
	//kotak tengah 2
	glTranslatef(-0.1, 0.7, -4.5);
	glScalef(2.2,0.1,1.1);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(1.01);
	glColor3f(0.4, 0.4, 0.4);
	glutSolidCube(1);

	glPopMatrix();

    glPushMatrix(); 

	//kotak atas
	glTranslatef(-0.1, 2.3, -4.5);
	glScalef(2.2,0.1,1.1);
	glColor3f(0.0, 0, 0);
	glutWireCube(1.01);
	glColor3f(0.4, 0.4, 0.4);
	glutSolidCube(1);
	

    glPopMatrix();
	
	//box di dalam kiri atas
	glPushMatrix();
	glTranslatef(-0.5, 1.02, -4);
	glScalef(1, 0.5, 0.5);
	glColor3f(0, 0, 0);
	glutWireCube(1.01);
	glColor3f(0.4, 1, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	//box di dalam kanan atas
	glPushMatrix();
	glTranslatef(0.5, 1.3, -4);
	glScalef(0.5, 1, 0.5);
	glColor3f(0, 0, 0);
	glutWireCube(1.01);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(1);
	glPopMatrix();

	//box di dalam tengah kiri
	glPushMatrix();
	glTranslatef(0, -0.3, -4);
	glScalef(1.9, 0.7, 0.5);
	glColor3f(0, 0, 0);
	glutWireCube(1.01);
	glColor3f(0.5, 1.0, 0.0);
	glutSolidCube(1);
	glPopMatrix();

	//pintu bawah kiri
	glPushMatrix();
	glTranslatef(-0.5, -1.3, -3.0);
	glScalef(1, 1.3, 0.1);
	glColor3f(0, 0., 0.);
	glutWireCube(1.01);
	glColor3f(0.5, 0.5, 0.5);
	//glutSolidCube(1);
	glPopMatrix();

	//pintu bawah kanan
	glPushMatrix();
	glTranslatef(0.5, -1.3, -3.0);
	glScalef(1, 1.3, 0.1);
	glColor3f(0, 0., 0.);
	glutWireCube(1.01);
	glColor3f(0.5, 0.5, 0.5);
	//glutSolidCube(1);
	glPopMatrix();

	//pintu kanan
	glPushMatrix();
	glTranslatef(0.5, 0.7, -3.0);
	glRotatef(degree, 0.0, 1.0, 0.0);
	glScalef(1, 2.6, 0.1);
	glColor3f(0, 0., 0.);
	glTranslatef(xmove[0], ymove[0], zmove[0]);
	glutWireCube(1.01);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	//pintu kiri
	glPushMatrix();
	glTranslatef(-0.5, 0.7, -3.0);
	glRotatef(degree, 0.0, 1.0, 0.0);
	glScalef(1, 2.6, 0.1);
	glColor3f(0, 0., 0.);
	glTranslatef(xmove[1], ymove[1], zmove[1]);
	glutWireCube(1.01);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	
	glutSwapBuffers();
}

// Initialization routine.

// OpenGL window reshape routine.
void AppearanceAdjustment(int x, int y)
{
    int aspect = x / y;
    glViewport(0, 0, x, y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspect,0.1,20);
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ini Lemari");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(AppearanceAdjustment);
    glutSpecialFunc(keyboard);

	Settings();

	glutMainLoop();
}
