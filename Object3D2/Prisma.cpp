#define _USE_MATH_DEFINES
//#include <iostream>
#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

typedef struct
{
    float x, y, z;

} point3D_t;

typedef struct
{
    float v[4];
} vector3D_t;

typedef struct
{
    float x, y, z;

} point2D_t;

typedef struct
{
    float m[4][4];
} matrix3D_t;

typedef struct
{

    int NumberofVertices;
    short int pnt[32];

} face_t;

vector3D_t operator^(vector3D_t a, vector3D_t b)
{

    vector3D_t c; // c=a*b
    c.v[0] = a.v[1] * b.v[2] - a.v[2] * b.v[1];
    c.v[1] = a.v[2] * b.v[0] - a.v[0] * b.v[2];
    c.v[2] = a.v[0] * b.v[1] - a.v[1] * b.v[0];
    c.v[3] = 1.;
    return c;
}

typedef struct
{

    int NumberofVertices;
    point3D_t pnt[100];
    int NumberofFaces;
    face_t fc[32];

} object3D_t;

object3D_t prisma = {5,

                     {{0, 100, 0}, {100, 0, 0}, {0, 0, 100}, {-100, 0, 0}, {0, 0, -100}},
                     5,
                     {{3, {0, 1, 2}}, {3, {0, 2, 3}}, {3, {0, 3, 4}}, {3, {0, 4, 1}}, {4, {1, 4, 3, 2}}}};



point2D_t Vector2Point2D(vector3D_t vec)
{

    point2D_t pnt;
    pnt.x = vec.v[0];
    pnt.y = vec.v[1];
    return pnt;
}

vector3D_t Point2Vector(point3D_t pnt)
{

    vector3D_t vec;
    vec.v[0] = pnt.x;
    vec.v[1] = pnt.y;
    vec.v[2] = pnt.z;
    vec.v[3] = 1.;
    return vec;
}


matrix3D_t createIdentity(void)
{
    matrix3D_t u;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            u.m[i][j] = 0.;
        u.m[i][i] = 1.;
    }
    return u;
}
matrix3D_t rotationXMTX(float theta)
{
    matrix3D_t rotate = createIdentity();
    float cs = cos(theta);
    float sn = sin(theta);
    rotate.m[0][0] = cs;
    rotate.m[0][1] = -sn;
    rotate.m[1][0] = sn;
    rotate.m[1][1] = cs;
    return rotate;
}

matrix3D_t rotationYMTX(float theta)
{
    matrix3D_t rotate = createIdentity();
    float cs = cos(theta);
    float sn = sin(theta);
    rotate.m[0][0] = cs;
    rotate.m[0][2] = -sn;
    rotate.m[2][0] = sn;
    rotate.m[2][2] = cs;
    return rotate;
}

matrix3D_t operator*(matrix3D_t a, matrix3D_t b)
{
    matrix3D_t c; // c=a*b
    int i, j, k;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            c.m[i][j] = 0;
            for (k = 0; k < 4; k++)
                c.m[i][j] += a.m[i][k] * b.m[k][j];
        }
    return c;
}

vector3D_t operator - (vector3D_t a, vector3D_t b)
{
	vector3D_t c;//c=a*b
	for(int i=0;i<3;i++)
		c.v[i]=a.v[i]-b.v[i];
	c.v[3]=1.;
	return c;
}

vector3D_t operator * (matrix3D_t a, vector3D_t b)
{
	vector3D_t c;//c=a*b
	int i,j;
	for (i=0;i<4;i++) {
		c.v[i]=0;
		for (j=0;j<4;j++) 
			c.v[i]+=a.m[i][j]*b.v[j];
	}
	return c;
}
void setColor(float r,float g,float b){
	glColor3f(r,g,b);
}

void drawPolygon(point2D_t p[],int n){
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<n;i++) glVertex2f(p[i].x,p[i].y);
	glEnd();
}



void userdraw(void){
    float theta = 0.5; 
    int j, i;
    point2D_t titik2D[50];
matrix3D_t tilting = rotationXMTX(theta) * rotationYMTX(-theta);

matrix3D_t mat;
vector3D_t vec[1600], vecbuff[50], NormalVector;
float normalzi;
mat = tilting;
for (i = 0; i < prisma.NumberofVertices; i++)
{
    vec[i] = Point2Vector(prisma.pnt[i]);
    vec[i] = mat * vec[i];
}
for (i = 0; i < prisma.NumberofFaces; i++)
{
    for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
        vecbuff[j] = vec[prisma.fc[i].pnt[j]];
    for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
        titik2D[j] = Vector2Point2D(vec[prisma.fc[i].pnt[j]]);
    drawPolygon(titik2D, prisma.fc[i].NumberofVertices);
}

for (i = 0; i < prisma.NumberofVertices; i++)
{
    vec[i] = Point2Vector(prisma.pnt[i]);
    vec[i] = mat * vec[i];
}

for (i = 0; i < prisma.NumberofFaces; i++)
{
    for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
        vecbuff[j] = vec[prisma.fc[i].pnt[j]];
    for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
        titik2D[j] = Vector2Point2D(vec[prisma.fc[i].pnt[j]]);
    drawPolygon(titik2D, prisma.fc[i].NumberofVertices);
}


setColor(0, 0, 1);
for (i = 0; i < prisma.NumberofFaces; i++)
{
    for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
        vecbuff[j] = vec[prisma.fc[i].pnt[j]];
    NormalVector = (vecbuff[1] - vecbuff[0]) ^ (vecbuff[2] - vecbuff[0]);
    normalzi = NormalVector.v[2];
    if (normalzi < 0.)
    {
        for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
            titik2D[j] = Vector2Point2D(vec[prisma.fc[i].pnt[j]]);
        drawPolygon(titik2D, prisma.fc[i].NumberofVertices);
    }
}

setColor(0, 1, 1);
for (i = 0; i < prisma.NumberofFaces; i++)
{
    for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
        vecbuff[j] = vec[prisma.fc[i].pnt[j]];
    NormalVector = (vecbuff[1] - vecbuff[0]) ^ (vecbuff[2] - vecbuff[0]);
    normalzi = NormalVector.v[2];
    if (normalzi > 0.)
    {
        for (j = 0; j < prisma.fc[i].NumberofVertices; j++)
            titik2D[j] = Vector2Point2D(vec[prisma.fc[i].pnt[j]]);
        drawPolygon(titik2D, prisma.fc[i].NumberofVertices);
    }
}
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    userdraw();
    glutSwapBuffers();
}

int main (int argc, char ** argv) {
    // insert code here...
    glutInit(&argc,argv); //inisialisasi toolkit
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); 
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Yes");
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(-400.,400.,-400.,400.);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}