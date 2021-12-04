#include <iostream>
#include <GL/glut.h>
#include <cmath>
#define PI  3.14159265358979323846
using namespace std;
bool isDay = true;
bool isRain=true;
int i;
int triangleAmount = 500;
GLfloat x = 0,y = 0,radius = 0;
GLfloat twicePi = 2.0f * PI;

void Circle(GLfloat cx, GLfloat cy, GLfloat radius, int r, int g, int b)
{
    glColor3ub(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cx, cy);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            cx + (radius * cos(i *  twicePi / triangleAmount)),
			    cy + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}


void anyTriangle( float a, float b, float c, float d, float e, float f, int R, int G, int B ){
    glBegin(GL_TRIANGLES);
    glColor3ub(R, G, B);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glEnd();
}

void anyQuad( float a, float b, float c, float d, float e, float f, float g, float h, int R, int G, int B ){
    glBegin(GL_QUADS);
    glColor3ub(R, G, B);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glVertex2f(g, h);
    glEnd();
}

void lineComponent(float a, float b, float c, float d){
   glBegin(GL_LINES);
   glVertex2f(a, b);
   glVertex2f(c, d);
   glEnd();
}

void anyText(string text, float x, float y, int R, int G, int B){
    glColor3ub(R, G, B);
    glRasterPos2f(x, y);
    for (i = 0; i < text.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void sunComponent()
{
    Circle(0.8f, 0.8f, 0.08f, 255, 255, 0);
}


void moonComponent()
{
    Circle(0.8f, 0.8f, 0.08f, 245, 245, 245);
}
void starComponent(){
    glPointSize(2);
    glBegin(GL_POINTS);
	glColor3ub(255,255,255);
	glVertex2f(-0.9,0.9);
	glVertex2f(-0.8,0.8);
	glVertex2f(-0.85,0.55);
    glVertex2f(-0.75,0.65);
    glVertex2f(-0.55,0.85);
    glVertex2f(-0.55,0.85);
    glVertex2f(-0.85,0.75);
    glVertex2f(-0.35,0.75);
    glVertex2f(-0.95,0.45);
    glVertex2f(-0.85,0.65);
    glVertex2f(-0.65,0.55);
    glVertex2f(-0.35,0.64);

    glVertex2f(-0.75,0.75);
    glVertex2f(-0.15,0.75);
    glVertex2f(-0.25,0.75);

    glVertex2f(-0.0,0.75);
    glVertex2f(0.25,0.85);
    glVertex2f(0.275,0.75);
    glVertex2f(0.0,0.75);
    glVertex2f(0.9,0.91);
	glVertex2f(0.875,0.95);
    glVertex2f(0,0.99);
    glVertex2f(-0.1,0.95);
    glVertex2f(-0.2,0.93);
    glVertex2f(-0.4,0.95);
    glVertex2f(0.1,0.95);
    glVertex2f(0.2,0.93);
    glVertex2f(0.4,0.95);
    glVertex2f(0.7,0.95);
    glVertex2f(0.8,0.95);
    glVertex2f(0.1,0.55);
    glVertex2f(0.2,0.63);
    glVertex2f(0.66,0.45);
    glVertex2f(0.8,0.55);
    glVertex2f(0.76,0.35);
    glVertex2f(0.8,0.65);
    glVertex2f(0.6,0.75);
    glVertex2f(0.8,0.55);
    glEnd();
    glPointSize(7);
}


void treeComponent(){
    anyQuad(0.69f, 0.13f, 0.67f, 0.10f, 0.78f, 0.10f, 0.76f, 0.13f, 0, 102, 51);
    anyQuad(0.70f, 0.16f, 0.68f, 0.13f, 0.77f, 0.13f, 0.75f, 0.16f, 0, 153, 0);
    anyQuad(0.71f, 0.19f, 0.69f, 0.16f, 0.76f, 0.16f, 0.74f, 0.19f, 0, 204, 0);
    anyQuad(0.72f, 0.22f,0.70f, 0.19f, 0.75f, 0.19f, 0.73f, 0.22f, 128, 255, 0);
    anyQuad(0.71f, 0.10f, 0.71f, 0.0f, 0.73f, 0.0f, 0.73f, 0.10f, 102, 51, 0);
    anyQuad(0.73f, 0.10f, 0.73f, 0.0f, 0.74f, 0.0f, 0.74f, 0.10f, 153, 76, 0);
}

void cloudComponent(){
    Circle(0.58f, 0.75f,  0.060f, 204, 204, 204);
    Circle(0.5f, 0.82f,  0.068f, 204, 204, 204);
    Circle(0.42f, 0.75f,  0.068f, 204, 204, 204);
    Circle(0.5f, 0.72f,  0.07f, 204, 204, 204);
}
void init(void)
{
    glClearColor(0.0,1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
}
void Idle()
{   Sleep(10);
    glutPostRedisplay();
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
    case 't':
        isDay = !isDay;
        break;
    case 'r':
        isRain = !isRain;
        break;
    glutPostRedisplay();
    }
    }
void SkyComponent(bool isDay){
    if(isDay==true){
    glBegin(GL_QUADS);
    glColor3ub(77, 184, 255);
    glVertex2f(-1.0, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    sunComponent();
    }
    else{
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-1.0, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    moonComponent();
    starComponent();
    }
}

void rainView(bool isRain)
{
    if(isRain==false){
            if(isDay==true){
    glBegin(GL_QUADS);
    glColor3ub(77, 184, 255);
    glVertex2f(-1.0, 0.0f);
    glColor3ub(224, 224, 224);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    cloudComponent();
            }
            else{
                glBegin(GL_QUADS);
                glColor3ub(0, 0, 0);
                glVertex2f(-1.0, 0.0f);
                glVertex2f(1.0f, 0.0f);
                glVertex2f(1.0f, 1.0f);
                glVertex2f(-1.0f, 1.0f);
                glEnd();
                cloudComponent();
            }

    float x=0.0, y = -0.5, x1=-0.099;
    glColor3ub(255,255,255);
    glPushMatrix();
    glTranslatef(0,-0.5,0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    for(int i=500;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3f(x,y,0);
            glVertex3f(x+0.05,y+0.04,0);
            x+=float(rand()%5)/10;
        }
        for(int j=0;j<=i;j++)
        {
            glVertex3f(x1,y,0);
            glVertex3f(x1+0.05,y+0.04,0);
            x1-=float(rand()%5)/10;
        }
        y+=float(rand()%10)/10;
        x=0.0;
        x1=-0.099;
    }
    glEnd();
    glPopMatrix();
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    SkyComponent(isDay);
    rainView(isRain);
    treeComponent();
    glFlush();
}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Castle");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(Idle);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}

