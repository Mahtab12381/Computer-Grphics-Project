#include <windows.h>7878
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include<mmsystem.h>
#define PI  3.14159265358979323846
using namespace std;
bool isDay = true;
bool isRain=false;
bool keymap=true;
bool sound=true;
float angle1=0.0;
float angle2=120.0;
float angle3=240.0;
GLfloat cloud_position = 0.85f;
GLfloat cloud_speed = 0.008f;
int i;
int triangleAmount = 500;
const float DEG2RAD = 3.14159/180.0;
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
void midPointEllipse(float xradius, float yradius, float q,float r,float g,float b)
{
	glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
	for(int i=0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD/q;
		glVertex2f(cos(degInRad)*xradius,sin(degInRad)*yradius);
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
    }}

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
    glVertex2f(0.0f,0.79f);
    /*glVertex2f(0.0f,0.9f);
    glVertex2f(0.07f,0.8f);
    glVertex2f(0.07f,0.7f);
    glVertex2f(0.03f,0.56f);
    glVertex2f(0.03f,0.45f);*/
    glVertex2f(0.03f,0.95f);
    glVertex2f(0.13f,0.79f);
    glVertex2f(0.13f,0.9f);
    glVertex2f(0.23f,0.75f);
    glVertex2f(0.23f,0.85f);
    glVertex2f(0.33f,0.65f);
    glVertex2f(0.33f,0.785f);
    glVertex2f(0.33f,0.958f);
    glVertex2f(0.43f,0.55f);
    glVertex2f(0.43f,0.75f);
    glVertex2f(0.43f,0.89f);
    glVertex2f(0.55f,0.47f);
    glVertex2f(0.55f,0.67f);
    glVertex2f(0.55f,0.87f);
    glVertex2f(0.5f,0.42f);
    glVertex2f(0.58f,0.45f);
    glVertex2f(0.58f,0.65f);
    glVertex2f(0.58f,0.95f);
    glVertex2f(0.49f,0.51f);
    glVertex2f(0.63f,0.525f);
    glVertex2f(0.63f,0.725f);
    glVertex2f(0.63f,0.925f);
    glVertex2f(0.73f,0.425f);
    glVertex2f(0.73f,0.525f);
    glVertex2f(0.73f,0.725f);
    glVertex2f(0.83f,0.35f);
    glVertex2f(0.83f,0.46f);
    glVertex2f(0.83f,0.56f);
    glVertex2f(0.83f,0.76f);
    glVertex2f(0.83f,0.96f);
    glVertex2f(0.93f,0.485f);
    glVertex2f(0.93f,0.585f);
    glVertex2f(0.93f,0.785f);
    glVertex2f(0.98f,0.885f);
    glVertex2f(0.98f,0.285f);
    /*glVertex2f(-0.0f,0.79f);
    glVertex2f(-0.0f,0.9f);
    glVertex2f(-0.07f,0.9f);
    glVertex2f(-0.07f,0.7f);
    glVertex2f(-0.03f,0.75f);*/
    glVertex2f(-0.03f,0.85f);
    glVertex2f(-0.03f,0.95f);
    glVertex2f(-0.13f,0.79f);
    glVertex2f(-0.13f,0.9f);
    glVertex2f(-0.23f,0.75f);
    glVertex2f(-0.23f,0.85f);
    glVertex2f(-0.33f,0.65f);
    glVertex2f(-0.33f,0.785f);
    glVertex2f(-0.33f,0.958f);
    glVertex2f(-0.43f,0.55f);
    glVertex2f(-0.43f,0.75f);
    glVertex2f(-0.43f,0.89f);
    glVertex2f(-0.55f,0.47f);
    glVertex2f(-0.55f,0.67f);
    glVertex2f(-0.55f,0.87f);
    glVertex2f(-0.5f,0.42f);
    glVertex2f(-0.58f,0.45f);
    glVertex2f(-0.58f,0.65f);
    glVertex2f(-0.58f,0.95f);
    glVertex2f(-0.49f,0.51f);
    glVertex2f(-0.63f,0.525f);
    glVertex2f(-0.63f,0.725f);
    glVertex2f(-0.63f,0.925f);
    glVertex2f(-0.73f,0.425f);
    glVertex2f(-0.73f,0.525f);
    glVertex2f(-0.73f,0.725f);
    glVertex2f(-0.83f,0.35f);
    glVertex2f(-0.83f,0.46f);
    glVertex2f(-0.83f,0.56f);
    glVertex2f(-0.83f,0.76f);
    glVertex2f(-0.83f,0.96f);
    glVertex2f(-0.93f,0.485f);
    glVertex2f(-0.93f,0.585f);
    glVertex2f(-0.93f,0.785f);
    glVertex2f(-0.98f,0.885f);
    glVertex2f(-0.98f,0.285f);
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

void cloudComponent2(){
    Circle(0.58f, 0.75f,  0.060f, 255, 255, 255);
    Circle(0.5f, 0.82f,  0.068f, 255, 255, 255);
    Circle(0.42f, 0.75f,  0.068f, 255, 255, 255);
    Circle(0.5f, 0.72f,  0.07f, 255, 255, 255);
}

void keymappings(bool keymap){
    if(keymap==true)
    anyText("t = toggle daynight , r = toggle rain , k = keymap show , s=toggle sound,e = exit", -0.95f, -.95f, 255, 255, 255);
}

void update(int value) {

    if(cloud_position < -1.2)
    cloud_position = 1.2f;
    cloud_position -=cloud_speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}
void cloudView(){
    glPushMatrix();

    glTranslatef(cloud_position-0.4f,0,0);
    cloudComponent();

    glTranslatef(cloud_position - 0.4f,-0.650,0);
    cloudComponent();

    glPopMatrix();
}

void cloudviewDAy(){

    glPushMatrix();

    glTranslatef(cloud_position-0.4f,0,0);
    cloudComponent2();

    glTranslatef(cloud_position - 0.4f,-0.45,0);
    cloudComponent2();

    glPopMatrix();
}

void HalfCircle(float r1,float r,float g,float b){
glPushMatrix();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416/2;
            float A=(i*2*pi)/200;
            float r=r1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }
	glEnd();
    glPopMatrix();
}
void window(){
glBegin(GL_QUADS);
                glColor3ub(96,96,96);
                glVertex2f(0.015,-0.04);
                glVertex2f(-0.015, -0.04);
                glColor3ub(160,160,160);
                glVertex2f(-0.015, -0.00);
                glVertex2f(0.015, -0.00);
                glEnd();
                glTranslatef(-0.0005,0,0);
                HalfCircle(0.015,160,160,160);
                glLoadIdentity();
}
void distancetree(float r1){
glPushMatrix();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,102,51);
            float pi=3.1416/2;
            float A=(i*2*pi)/200;
            float r=r1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }
	glEnd();
    glPopMatrix();
}
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
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
        if(isRain==true){
        (isRain&&sound) ? PlaySound("assets/rain.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
        }
        else if(isDay==true){
         (isDay&&sound&&!isRain) ? PlaySound("assets/morning.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
        }
        else
        (!isDay&&sound&&!isRain) ? PlaySound("assets/night.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
        break;
    case 'r':
        isRain = !isRain;
        if(isDay==true){
                if(isRain==true){
                    (isRain&&sound) ? PlaySound("assets/rain.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
                }
                else
            (isDay&&sound&&!isRain) ? PlaySound("assets/morning.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
        }
        if(isDay==false){
            if(isRain==true){
                    (isRain&&sound) ? PlaySound("assets/rain.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
                }
                else
            (!isDay&&sound&&!isRain) ? PlaySound("assets/night.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP) : PlaySound(NULL, 0, 0);
        }
        break;
    case 'k':
        keymap = !keymap;
        break;
    case 's':
        sound = !sound;
        break;
    case 'e':
        exit(0);
        break;
    glutPostRedisplay();
    }
    }
void SkyComponent(bool isDay){
    if(isDay==true){
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-1.0, -0.25f);
    glVertex2f(1.0f, -0.25f);
    glColor3ub(77, 184, 255);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    sunComponent();
    cloudviewDAy();
    }
    else{
    glBegin(GL_QUADS);
                 glColor3ub(0, 0,51);
                glVertex2f(-1.0, -0.25f);
                glColor3ub(0, 0,110);
                glVertex2f(1.0f, -0.25f);
                glVertex2f(1.0f, 1.0f);
                glVertex2f(-1.0f, 1.0f);
                glEnd();
    moonComponent();
    starComponent();
    }
}

void rainView(bool isRain)
{
    if(isRain==true){
            if(isDay==true){
    glBegin(GL_QUADS);
    glColor3ub(77, 184, 255);
    glVertex2f(-1.0, -0.25f);
    glColor3ub(224, 224, 224);
    glVertex2f(1.0f, -0.25f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    cloudView();
            }
            else{
                glBegin(GL_QUADS);
                 glColor3ub(0, 0,51);
                glVertex2f(-1.0, -0.25f);
                glColor3ub(0, 0,110);
                glVertex2f(1.0f, -0.25f);
                glVertex2f(1.0f, 1.0f);
                glVertex2f(-1.0f, 1.0f);
                glEnd();
                cloudView();
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
 void river(){
  glBegin(GL_TRIANGLES);
                glColor3ub(0,105,255);
                glVertex2f(-1,-0.25);
                glColor3ub(51,255,255);
                glVertex2f(0,-0.25);
                glVertex2f(-1,-0.45);
                glEnd();
 }
void distancetreeview(){


            glTranslatef(-1.0,-0.2521,0);
            distancetree(0.05);
            glLoadIdentity();


            glTranslatef(-0.9,-0.2521,0);
            distancetree(0.07);
            glLoadIdentity();


            glTranslatef(-0.8,-0.2521,0);
            distancetree(0.06);
            glLoadIdentity();


            glTranslatef(-0.7,-0.2521,0);
            distancetree(0.05);
            glLoadIdentity();


            glTranslatef(-0.62,-0.2521,0);
            distancetree(0.04);
            glLoadIdentity();


            glTranslatef(-0.515,-0.2521,0);
            distancetree(0.07);
            glLoadIdentity();


            glTranslatef(-0.43,-0.2521,0);
            distancetree(0.03);
            glLoadIdentity();


            glTranslatef(-0.385,-0.2521,0);
            distancetree(0.02);
            glLoadIdentity();


            glTranslatef(-0.35,-0.2521,0);
            distancetree(0.021);
            glLoadIdentity();


            glTranslatef(-0.32,-0.2521,0);
            distancetree(0.019);
            glLoadIdentity();


            glTranslatef(-0.31,-0.2521,0);
            distancetree(0.018);
            glLoadIdentity();


            glTranslatef(-0.385,-0.2521,0);
            distancetree(0.011);
            glLoadIdentity();


            glTranslatef(-1.0,-0.2521,0);
            distancetree(0.05);
            glLoadIdentity();


            glTranslatef(-0.9,-0.2521,0);
            distancetree(0.07);
            glLoadIdentity();


            glTranslatef(-0.8,-0.2521,0);
            distancetree(0.06);
            glLoadIdentity();


            glTranslatef(-0.7,-0.2521,0);
            distancetree(0.05);
            glLoadIdentity();


            glTranslatef(-0.62,-0.2521,0);
            distancetree(0.04);
            glLoadIdentity();


            glTranslatef(-0.515,-0.2521,0);
            distancetree(0.07);
            glLoadIdentity();


            glTranslatef(-0.43,-0.2521,0);
            distancetree(0.03);
            glLoadIdentity();


            glTranslatef(-0.385,-0.2521,0);
            distancetree(0.02);
            glLoadIdentity();


            glTranslatef(-0.35,-0.2521,0);
            distancetree(0.021);
            glLoadIdentity();


            glTranslatef(-0.32,-0.2521,0);
            distancetree(0.019);
            glLoadIdentity();


            glTranslatef(-0.31,-0.2521,0);
            distancetree(0.018);
            glLoadIdentity();


            glTranslatef(-0.385,-0.2521,0);
            distancetree(0.011);
            glLoadIdentity();


            glTranslatef(1.0,-0.2521,0);
            distancetree(0.05);
            glLoadIdentity();


            glTranslatef(0.9,-0.2521,0);
            distancetree(0.07);
            glLoadIdentity();


            glTranslatef(0.8,-0.2521,0);
            distancetree(0.06);
            glLoadIdentity();


            glTranslatef(0.7,-0.2521,0);
            distancetree(0.05);
            glLoadIdentity();


            glTranslatef(0.62,-0.2521,0);
            distancetree(0.04);
            glLoadIdentity();


            glTranslatef(0.515,-0.2521,0);
            distancetree(0.07);
            glLoadIdentity();


            glTranslatef(0.43,-0.2521,0);
            distancetree(0.03);
            glLoadIdentity();


            glTranslatef(0.385,-0.2521,0);
            distancetree(0.02);
            glLoadIdentity();


            glTranslatef(0.35,-0.2521,0);
            distancetree(0.021);
            glLoadIdentity();


            glTranslatef(0.32,-0.2521,0);
            distancetree(0.019);
            glLoadIdentity();


            glTranslatef(0.31,-0.2521,0);
            distancetree(0.018);
            glLoadIdentity();


            glTranslatef(0.385,-0.2521,0);
            distancetree(0.011);
            glLoadIdentity();

}
 void hills(){
                glBegin(GL_TRIANGLES);
                glColor3ub(34,139,34);
                glVertex2f(-1.1,-0.25);
                glColor3ub(176,196,222);
                glVertex2f(-0.955,-0.10);
                glVertex2f(-0.90,-0.25);

                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(34,139,34);
                glVertex2f(-0.75,-0.25);
                glColor3ub(176,196,222);
                glVertex2f(-0.45,-0.05);
                glVertex2f(-0.25,-0.25);

                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(34,139,34);
                glVertex2f(-0.95,-0.25);
                glColor3ub(176,196,222);
                glVertex2f(-0.75,0.10);
                glVertex2f(-0.60,-0.25);
                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(224,224,224);
                glVertex2f(45,-0.25);
                glColor3ub(176,196,222);
                glVertex2f(63,0.10);
                glVertex2f(83,-0.25);
                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(34,139,34);
                glVertex2f(0.25,-0.25);
                glColor3ub(176,196,222);
                glVertex2f(0.40,-0.13);
                glVertex2f(0.55,-0.25);

                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(34,139,34);
                glVertex2f(0.50,-0.25);
                glColor3ub(176,196,222);
                glVertex2f(0.60,-0.10);
                glVertex2f(0.80,-0.25);

                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(34,139,34);
                glVertex2f(0.65,-0.25);
                glColor3ub(176,196,222);
                glVertex2f(0.85,0.05);
                glVertex2f(1.05,-0.25);

                glEnd();

 }
 void groundview(){


     glBegin(GL_QUADS);
                glColor3ub(0,204,0);
                glVertex2f(-1,-0.25);
                //glColor3ub(178,255,102);
                glVertex2f(1, -0.25);
                 glColor3ub(229,255,204);
                glVertex2f(1, -1);
                 glColor3ub(229,255,204);
                glVertex2f(-1, -1);
                glEnd();


        glTranslatef(-0.15,-0.70,0);
        glScalef(1.2,1.2,0);
        treeComponent();
        glLoadIdentity();

        glTranslatef(-0.64,-0.76,0);
        glScalef(1.2,1.2,0);
        treeComponent();
        glLoadIdentity();


        glTranslatef(0.8,-0.95,0);
        midPointEllipse(0.9, 0.30, 2,178,255,102);
        glLoadIdentity();

        glTranslatef(-0.5,-0.98,0);
        midPointEllipse(0.4, 0.3, 2,0,204,0);
        glLoadIdentity();

        glTranslatef(-1.9,-0.85,0);
        glScalef(1.5,1.5,0);
        treeComponent();
        glLoadIdentity();

        glTranslatef(-0.8,-1.15,0);
        midPointEllipse(0.4, 0.40, 2,102,204,0);
        glLoadIdentity();

        glTranslatef(-0.18,-0.90,0);
        glScalef(1.5,1.5,0);
        treeComponent();
        glLoadIdentity();

        glTranslatef(-0.63,-0.90,0);
        glScalef(1.5,1.5,0);
        treeComponent();
        glLoadIdentity();

        glTranslatef(0.6,-1.1,0);
        midPointEllipse(0.60, 0.30, 2,102,204,0);
        glLoadIdentity();



        glTranslatef(-0.15,-1.1,0);
        midPointEllipse(0.45, 0.38, 2,0,153,76);
        glLoadIdentity();

 }

 void castle(){

                glBegin(GL_QUADS);
                glColor3ub(211,211,211);
                glVertex2f(0.14,-0.20);
                glColor3ub(255,255,255);
                glVertex2f(0.22, -0.20);
                glVertex2f(0.22, 0.17);
                glVertex2f(0.14, 0.17);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(211,211,211);
                glVertex2f(-0.14,-0.20);
                glColor3ub(255,255,255);
                glVertex2f(-0.22, -0.20);
                glVertex2f(-0.22, 0.17);
                glVertex2f(-0.14, 0.17);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(211,211,211);
                glVertex2f(0.07,-0.20);
                glColor3ub(255,255,255);
                glVertex2f(-0.07, -0.20);
                glVertex2f(-0.07, 0.36);
                glVertex2f(0.07, 0.36);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(211,211,211);
                glVertex2f(0.14,-0.20);
                glColor3ub(255,255,255);
                glVertex2f(-0.18, -0.20);
                glVertex2f(-0.18, -0.04);
                glVertex2f(0.14, -0.04);
                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(65,105,225);
                glVertex2f(-0.18,-0.04);
                glColor3ub(176,196,222);
                glVertex2f(-0.02,0.04);
                glVertex2f(0.14,0.-0.04);
                  glEnd();

                  glLineWidth(50);
                glBegin(GL_LINES);
               glColor3ub(190,190,190);
                glVertex2f(-0.19,-0.04);
                glVertex2f(0.14, -0.04);
                glEnd();

                float x3=0;
                for(int i=0;i<10;i++){
                glPointSize(10);
                glBegin(GL_POINTS);
                glColor3ub(190,190,190);
                glVertex2f(-0.18-x3,-0.03);
                glEnd();
                x3=x3-0.03;
                  }

                glBegin(GL_QUADS);
                glColor3ub(211,211,211);
                glVertex2f(0.18,-0.20);
                glColor3ub(255,255,255);
                glVertex2f(0.04, -0.20);
                glVertex2f(0.04, 0.06);
                glVertex2f(0.18, 0.06);
                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(65,105,225);
                glVertex2f(0.04,0.06);
                glColor3ub(176,196,222);
                glVertex2f(0.11,0.10);
                glVertex2f(0.18,0.06);
                  glEnd();

                  glLineWidth(8);
                glBegin(GL_LINES);
               glColor3ub(190,190,190);
                glVertex2f(0.03,0.06);
                glVertex2f(0.19, 0.06);
                glEnd();


                 glBegin(GL_TRIANGLES);
                glColor3ub(65,105,225);
                glVertex2f(-0.07,0.36);
                glColor3ub(176,196,222);
                glVertex2f(0.0,0.41);
                glVertex2f(0.07,0.36);
                  glEnd();

                  glLineWidth(8);
                glBegin(GL_LINES);
               glColor3ub(190,190,190);
                glVertex2f(-0.08,0.36);
                glVertex2f(0.08, 0.36);
                glEnd();


                glBegin(GL_TRIANGLES);
                glColor3ub(65,105,225);
                glVertex2f(0.14,0.17);
                glColor3ub(176,196,222);
                glVertex2f(0.18,0.27);
                glVertex2f(0.22,0.17);
                  glEnd();

                 glBegin(GL_TRIANGLES);
                glColor3ub(65,105,225);
                glVertex2f(-0.14,0.17);
                glColor3ub(176,196,222);
                glVertex2f(-0.18,0.27);
                glVertex2f(-0.22,0.17);
                  glEnd();

                  glLineWidth(50);
                glBegin(GL_LINES);
                glColor3ub(190,190,190);
                glVertex2f(0.13,0.17);
                glVertex2f(0.23, 0.17);
                glEnd();

                glLineWidth(50);
                glBegin(GL_LINES);
               glColor3ub(190,190,190);
                glVertex2f(-0.13,0.17);
                glVertex2f(-0.23, 0.17);
                glEnd();

                float x2=0;
                for(int i=0;i<14;i++){
                glPointSize(10);
                glBegin(GL_POINTS);
                glColor3ub(190,190,190);
                glVertex2f(-0.195-x2,-0.195);
                glEnd();
                x2=x2-0.03;
                  }

                  glBegin(GL_QUADS);
                glColor3ub(190,190,190);
                glVertex2f(-0.20f, -0.40f);
                glVertex2f(0.20f, -0.40f);
                glVertex2f(0.20f, -0.20f);
                glVertex2f(-0.20f, -0.20f);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(211,211,211);
                glVertex2f(-0.30f, -0.40f);
                glColor3ub(255,255,255);
                glVertex2f(-0.20f, -0.40f);
                glVertex2f(-0.20f, -0.10f);
                glVertex2f(-0.30f, -0.10f);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(211,211,211);
                glVertex2f(0.20,-0.40);
                glColor3ub(255,255,255);
                glVertex2f(0.30, -0.40);
                glVertex2f(0.30, -0.10);
                glVertex2f(0.20, -0.10);
                glEnd();

                glLineWidth(3);
                glBegin(GL_LINES);
                glColor3f(0,0,0);
                glVertex2f(-0.20f, -0.20f);
                glVertex2f(-0.20f, -0.40f);
                glEnd();

                glLineWidth(3);
                glBegin(GL_LINES);
                glColor3f(0,0,0);
                glVertex2f(0.20, -0.20);
                glVertex2f(0.20, -0.40);
                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(65,105,225);
                glVertex2f(-0.20,-0.12);
                glColor3ub(176,196,222);
                glVertex2f(-0.25,0.0);
                glVertex2f(-0.30,-0.12);
                glEnd();

                glBegin(GL_TRIANGLES);
                glColor3ub(65,105,225);
                glVertex2f(0.20,-0.12);
                glColor3ub(176,196,222);
                glVertex2f(0.25,0.0);
                glVertex2f(0.30,-0.12);
                  glEnd();

                float x=0;
                for(int i=0;i<5;i++){
                glPointSize(10);
                glBegin(GL_POINTS);
                glColor3ub(190,190,190);
                glVertex2f(-0.19+x,-0.11);
                glEnd();
                x=x-0.03;
                  }
                float x1=0;
                for(int i=0;i<5;i++){
                glPointSize(10);
                glBegin(GL_POINTS);
                glColor3ub(190,190,190);
                glVertex2f(0.31+x1,-0.11);
                glEnd();
                x1=x1-0.03;
                  }

                glLineWidth(50);
                glBegin(GL_LINES);
                glColor3ub(190,190,190);
                glVertex2f(0.18,-0.12);
                glVertex2f(0.32, -0.12);
                glEnd();

                glLineWidth(50);
                glBegin(GL_LINES);
                glColor3ub(190,190,190);
                glVertex2f(-0.18,-0.12);
                glVertex2f(-0.32, -0.12);
                glEnd();

                glLineWidth(50);
                glBegin(GL_LINES);
                glColor3ub(190,190,190);
                glVertex2f(0.085,0.17);
                glVertex2f(-0.085, 0.17);
                glEnd();

                float x4=0;
                for(int i=0;i<7;i++){
                glPointSize(10);
                glBegin(GL_POINTS);
                glColor3ub(190,190,190);
                glVertex2f(0.089+x4,0.185);
                glEnd();
                x4=x4-0.03;
                  }

                  glBegin(GL_QUADS);
                glColor3ub(255,178,102);
                glVertex2f(0.10,-0.40);
                glVertex2f(-0.10, -0.40);
                glColor3ub(255,204,153);
                glVertex2f(-0.10, -0.30);
                glVertex2f(0.10, -0.30);
                glEnd();

                glTranslatef(0,-0.309,0);
                HalfCircle(0.1,255,204,153);
                glLoadIdentity();

                glLineWidth(1);
                glBegin(GL_LINES);
                glColor3ub(0,0,0);
                glVertex2f(0.005,-0.21);
                glVertex2f(0.005,-0.401);
                glEnd();
                glLineWidth(1);
                glBegin(GL_LINES);
                glColor3ub(0,0,0);
                glVertex2f(-0.005,-0.21);
                glVertex2f(-0.005,-0.401);
                glEnd();

                glTranslatef(-0.25,-0.25,0);
                window();
                glLoadIdentity();

                glTranslatef(0.25,-0.25,0);
                window();
                glLoadIdentity();

                glTranslatef(-0.10,-0.105,0);
                window();
                glLoadIdentity();

                glTranslatef(-0.02,-0.105,0);
                window();
                glLoadIdentity();

                glTranslatef(0.00,0.105,0);
                window();
                glLoadIdentity();

                glTranslatef(0.00,0.28,0);
                window();
                glLoadIdentity();

                glScalef(0.55,0.55,0);
                glTranslatef(-0.33,0.23,0);
                window();
                glLoadIdentity();

                glScalef(0.55,0.55,0);
                glTranslatef(-0.33,0.12,0);
                window();
                glLoadIdentity();

                glScalef(0.55,0.55,0);
                glTranslatef(0.33,0.21,0);
                window();
                glLoadIdentity();

                glTranslatef(0.111,-0.1,0);
                window();
                glLoadIdentity();

                glScalef(0.55,0.9,0);
                glTranslatef(0.14,-0.022,0);
                window();
                glLoadIdentity();

                glScalef(0.55,0.9,0);
                glTranslatef(0.26,-0.022,0);
                window();
                glLoadIdentity();

                glBegin(GL_QUADS);
                glColor3ub(200,200,200);
                glVertex2f(0.32,-0.40);
                glVertex2f(-0.32, -0.40);
                glVertex2f(-0.32, -0.42);
                glVertex2f(0.32, -0.42);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(204,102,0);
                glVertex2f(0.34,-0.42);
                glVertex2f(-0.34, -0.42);
                glVertex2f(-0.34, -0.44);
                glVertex2f(0.34, -0.44);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(200,200,200);
                glVertex2f(0.36,-0.44);
                glVertex2f(-0.36, -0.44);
                glVertex2f(-0.36, -0.46);
                glVertex2f(0.36, -0.46);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(204,102,0);
                glVertex2f(0.38,-0.46);
                glVertex2f(-0.38, -0.46);
                glVertex2f(-0.38, -0.48);
                glVertex2f(0.38, -0.48);
                glEnd();

 }

 void windmill(){
                 glPushMatrix();
                 glBegin(GL_POLYGON);
                 glColor3ub(255,255,255);
                 glVertex2f(0.12,0.45);
                 glVertex2f(0.12, 0.6);
                 glVertex2f(0.13,0.6);
                 glVertex2f(0.13, 0.45);
                 glEnd();
                 glPushMatrix();
                 glTranslatef(0.125,0.6,0.0);
                 glRotatef(angle1,0.0,0.0,1);
                 glTranslatef(-0.125,-0.6,0.0);
                 glBegin(GL_POLYGON);
                 glColor3ub(255,255,255);
                 glVertex2f(0.125,0.6);
                 glColor3ub(204,204,204);
                 glVertex2f(0.12, 0.6);
                 glVertex2f(0.12,0.66);
                 glVertex2f(0.13, 0.66);
                 glVertex2f(0.13, 0.6);
                 glEnd();
                 glPopMatrix();


                 glPushMatrix();
                 glTranslatef(0.125,0.6,0.0);
                 glRotatef(angle2,0.0,0.0,1);
                 glTranslatef(-0.125,-0.6,0.0);
                 glBegin(GL_POLYGON);
                 glColor3ub(255,255,255);
                 glVertex2f(0.125,0.6);
                 glColor3ub(204,204,204);
                 glVertex2f(0.12, 0.6);
                 glVertex2f(0.12,0.66);
                 glVertex2f(0.13, 0.66);
                 glVertex2f(0.13, 0.6);
                 glEnd();
                 glPopMatrix();


                 glPushMatrix();
                 glTranslatef(0.125,0.6,0.0);
                 glRotatef(angle3,0.0,0.0,1);
                 glTranslatef(-0.125,-0.6,0.0);
                 glBegin(GL_POLYGON);
                 glColor3ub(255,255,255);
                 glVertex2f(0.125,0.6);
                 glColor3ub(204,204,204);
                 glVertex2f(0.12, 0.6);
                 glVertex2f(0.12,0.66);
                 glVertex2f(0.13, 0.66);
                 glVertex2f(0.13, 0.6);
                 glEnd();
                 glPopMatrix();

                 Circle(0.125,0.6,0.01,255,255,255);

 }

void windmillview(){

        glTranslatef(0.35,-0.925,0);
        glScalef(1.5,1.5,0);
        windmill();
        glLoadIdentity();

        glTranslatef(0.60,-0.925,0);
        glScalef(1.5,1.5,0);
        windmill();
        glLoadIdentity();

        glTranslatef(-0.76,-0.925,0);
        glScalef(1.5,1.5,0);
        windmill();
        glLoadIdentity();

        glTranslatef(-0.99,-0.925,0);
        glScalef(1.5,1.5,0);
        windmill();
        glLoadIdentity();


}
 void updatewindmill(int value){
 angle1-=0.5;
 angle2-=0.5;
 angle3-=0.5;
 glutPostRedisplay();
 glutTimerFunc(10,updatewindmill,0);
 }
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    SkyComponent(isDay);
    groundview();
    river();
    rainView(isRain);
    hills();
    windmillview();
    distancetreeview();
    castle();
    keymappings(keymap);
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
    glutTimerFunc(100, update, 0);
    glutTimerFunc(10,updatewindmill,0);
    PlaySound("assets/morning.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
    glutMainLoop();
    return 0;
}
