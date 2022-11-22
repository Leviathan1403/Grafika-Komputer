#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} point2D_t;

void drawPolygon(point2D_t pnt[], int n)
{
    int i;
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < n; i++)
    {
        glVertex2f(pnt[i].x, pnt[i].y);
    }
    glEnd();
}

void userdraw(void)
{
    point2D_t shape[720];

    double srad, r;
    for (int s = 0; s < 720; s++)
    {
        srad = s * 3.14 / 180;
        r = (srad);
        shape[s].x = (float)(r * cos(srad));
        shape[s].y = (float)(r * sin(srad));
    }
    drawPolygon(shape, 720);
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
    gluOrtho2D(-50.0,50.0, -50.0, 50.0);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}