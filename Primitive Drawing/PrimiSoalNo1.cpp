#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void circle(void)
{
    GLfloat x, y, angle;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for (angle = 0.0f; angle <= (2.0f * 3.14); angle += 0.01f)
    {
        glColor3f(0, 1, 0);
        x = 150.0f * sin(angle);
        y = 150.0f * cos(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void userdraw(void)
{
    circle();
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