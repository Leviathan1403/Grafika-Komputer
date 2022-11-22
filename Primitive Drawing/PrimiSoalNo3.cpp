#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void drawkotak(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex2f(x1, y1);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(x2, y2);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(x3, y3);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2f(x4, y4);
    glEnd();
}
void drawLine(float x1, float y1, float x2, float y2){
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
void drawsegitiga(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    glVertex2f(x1, y1);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(x2, y2);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(x3, y3);
    glEnd();
}

void userdraw(void) {
    drawkotak(0, 0, -200, 0, -200, -200, 0, -200);
    drawLine(100, 100, 200, 150);
    drawsegitiga(0, 200, -200, 50, 0, 50);

}

void display(void) {

glClear( GL_COLOR_BUFFER_BIT);
userdraw();
glutSwapBuffers();

}

int main(int argc, char **argv){
glutInit(&argc,argv);
glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB );
glutInitWindowPosition(100,100);
glutInitWindowSize(640,480);
glutCreateWindow ("Test");
glClearColor(0.0, 0.0, 0.0, 0.0);
gluOrtho2D(-320., 320., -240.0, 240.0);
glutIdleFunc(display);
glutDisplayFunc(display);
glutMainLoop();
return 0;

}