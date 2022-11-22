#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void drawDot (float x, float y){
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void userdraw(void) {
    glPointSize(10);
    glColor3f(0, 1, 0);
    drawDot(0, 0);
    glColor3f(0, 1, 1);
    drawDot(50, 0);
    glColor3f(1, 1, 0);
    drawDot(-50, 0);   
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Test");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-320., 320., -240.0, 240.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}