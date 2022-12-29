// #include<windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.1416

using namespace std;

#include<time.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
#define BLOCKSPEED 0.004


typedef struct star
{
    float posxChar;
    float posyChar;
} CHAR;

CHAR c[10];

GLint i, j, k;
GLfloat sun_spin = 0, sun_x = 0, sun_y = 0;
GLfloat ax = 0, bx = 0, cx = 0, dx = 0, str = 500.0, mn = 500.0;
GLfloat sr = 0.0, sg = 0.749, sb = 1.0;
GLfloat spin = 0.0;

float man_posy = -0.45, man_posy_speed = 8.8;
float roadblock1_posy = 0, roadblock1_posy_speed = 0.0009;

float posx = 0;
float posxSpeed = 0.1;

float posxChar = 1.0;

float posyBall = 0.31;
float posyBall2 = 0.31;
float posyBall3 = 0.31;
float posyBall4 = 0.31;
float posyBall5 = 0.31;
float posyBall6 = 0.31;
float posyBall7 = 0.31;
float posyBall8 = 0.31;
float posyBall9 = 0.31;
float posyBall10 = 0.31;

float RandomNumber(float Min, float Max)
{
    return ((float(rand())) / (float(RAND_MAX)) * (Max - Min)) + Min;
}

void windowkey(unsigned char key, int x, int y)
{
    if (key == 'd')
        posx += posxSpeed;

    if (key == 'a')
        posx -= posxSpeed;
}

void init(void)
{
    glClearColor(.40, .110, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void drawString(float x, float y, float z, void *font, char *string)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

///============================================================================================================///

///=================///
///*** All_Model ***///
///=================///

///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for (i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}
/// *** Sun_Model **///
void Sun_Model()
{
    glPushMatrix();
    glTranslatef(500, 0, 0);
    circle(30);
    glPopMatrix();
}
void Moving_Sun_Model()
{
    glPushMatrix();
    glRotatef(-sun_spin, 0, 0, -.009);
    Sun_Model();
    glPopMatrix();
}
///*** Cloud_Model***///
void cloud_model_one()
{

    glColor3f(1.25, 0.924, 0.930);

    /// Top_Left

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    /// Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    /// Right

    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(16);
    glPopMatrix();

    /// middle_Fill
    glPushMatrix();
    glTranslatef(355, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305, 204, 0);
    circle(10);
    glPopMatrix();

    ///****Fill End****
}

void cloud_model_Two()
{
    glColor3f(1.25, 0.924, 0.930);

    /// Left_Part
    glPushMatrix();
    glTranslatef(305, 205, 0);
    circle(10);
    glPopMatrix();

    /// Top

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    /// Right_Part
    glPushMatrix();
    glTranslatef(334, 207, 0);
    circle(10);
    glPopMatrix();

    /// Bottom_Part
    glPushMatrix();
    glTranslatef(320, 207, 0);
    circle(10);
    glPopMatrix();
}

void cloud_model_Three()
{
    glColor3f(1.25, 0.924, 0.930);

    /// Left_Part
    glPushMatrix();
    glTranslatef(300, 200, 0);
    circle(15);
    glPopMatrix();

    /// Top_Left

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    /// Top
    glPushMatrix();
    glTranslatef(340, 220, 0);
    circle(16);
    glPopMatrix();

    /// Top_Right
    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(15);
    glPopMatrix();

    /// Right_Part
    glPushMatrix();
    glTranslatef(380, 200, 0);
    circle(15);
    glPopMatrix();

    /// Bottom_Right
    glPushMatrix();
    glTranslatef(360, 190, 0);
    circle(20);
    glPopMatrix();

    /// Bottom_Left
    glPushMatrix();
    glTranslatef(320, 190, 0);
    circle(20);
    glPopMatrix();

    /// Bottom
    glPushMatrix();
    glTranslatef(340, 190, 0);
    circle(20);
    glPopMatrix();

    ///****Fill End****
}
///*** Hill_Model***///
void hill_big()
{

    /// Hill
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);

    glEnd();

    /// Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);

    glEnd();
}
void hill_small()
{
    /// Hill_Small
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(250, 100);
    glVertex2i(310, 175);
    glVertex2i(370, 100);

    glEnd();

    /// Hill_Small_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
    glVertex2i(310, 175);
    glVertex2i(330, 150);
    glVertex2i(325, 140);
    glVertex2i(310, 150);
    glVertex2i(300, 140);

    glEnd();
}
///*** Tilla_Model ***///
void Tilla_One_Model()
{
    /// Tilla
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(300, 110);
    glVertex2i(300, 70);

    glEnd();
}

void Tilla_Two_Model()
{

    glColor3f(0.1, 1.293, 0.0);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430, 90, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420, 87, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390, 70, 0);
    circle(30);
    glPopMatrix();

    /// Right_Part
    glPushMatrix();
    glTranslatef(445, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455, 75, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465, 70, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470, 65, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480, 60, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485, 55, 0);
    circle(20);
    glPopMatrix();
}
///*** House_Model ***///
void house()
{
    /// House_Roof
    glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 130);
    glVertex2i(380, 115);
    glVertex2i(380, 105);

    glEnd();

    /// House_Roof_Shadow
    glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 120);
    glVertex2i(380, 105);
    glVertex2i(380, 105);

    glEnd();

    /// House_Fence
    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(290, 70);
    glVertex2i(290, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();

    /// House_Fence_Shadow
    glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
    glVertex2i(310, 70);
    glVertex2i(350, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();

    /// House_Door
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(330, 70);
    glVertex2i(330, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 70);

    glEnd();

    /// House_Window1
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);

    glEnd();

    /// House_Window2
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(312, 75);
    glVertex2i(312, 90);
    glVertex2i(327, 90);
    glVertex2i(327, 75);

    glEnd();

    /// House_Window3
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);

    glEnd();

    /// House_Small_Roof
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(250, 90);
    glVertex2i(257, 104);
    glVertex2i(290, 104);
    glVertex2i(290, 90);

    glEnd();

    /// House_Small_Fence
    glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
    glVertex2i(255, 70);
    glVertex2i(255, 90);
    glVertex2i(290, 90);
    glVertex2i(290, 70);

    glEnd();

    /// House_Small_Door
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(260, 70);
    glVertex2i(260, 80);
    glVertex2i(285, 80);
    glVertex2i(285, 70);

    glEnd();
}
///*** Field_Model ***///
void field()
{
    /// Field
    glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
    glVertex2i(0, 50);
    glVertex2i(0, 70);
    glVertex2i(1000, 70);
    glVertex2i(1000, 50);

    glEnd();

    /// Field_Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(0, 0);
    glVertex2i(0, 50);
    glVertex2i(1000, 50);
    glVertex2i(1000, 0);

    glEnd();
}
///*** Tree_Model ***///
void Tree_Model_One()
{

    glPushMatrix();
    glTranslatef(110, 110, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110, 100, 0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(109, 70);
    glVertex2f(109, 90);
    glVertex2f(111, 90);
    glVertex2f(111, 70);

    glEnd();
}
void Tree_Model_Two()
{

    glPushMatrix();
    glTranslatef(130, 130, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125, 126, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135, 126, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 125, 0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(129, 110);
    glVertex2f(129, 124);
    glVertex2f(131, 124);
    glVertex2f(131, 110);

    glEnd();
}

void Tree_Model_Three()
{

    glBegin(GL_POLYGON);

    glVertex2f(125, 123);
    glVertex2f(133, 145);
    glVertex2f(141, 123);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(132, 110);
    glVertex2f(132, 124);
    glVertex2f(134, 124);
    glVertex2f(134, 110);

    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model()
{

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade()
{

    /// Blade_One
    glPushMatrix();
    glRotatef(spin, 0, 0, 90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    /// Blade_Two
    glPushMatrix();
    glRotatef(spin, 0, 0, 90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    /// Blade_Three
    glPushMatrix();
    glRotatef(spin, 0, 0, 90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0, 0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();
}
///*** Windmill_Final_Model ***///
void Windmill()
{

    /// Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    /// Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380, 250, 0);
    circle(10);
    glPopMatrix();

    /// Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380, 251, 0);
    Windmill_Blade();
    glPopMatrix();
}

/// Model_End
///=======================================================================================================///

///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun()
{
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}
///*** Cloud_One_Model_One ***///
void cloud_one()
{
    glPushMatrix();
    glTranslatef(cx, -40, 0);
    cloud_model_one();
    glPopMatrix();
}

///*** Cloud_Two_Model_one ***///

void cloud_two()
{
    glPushMatrix();
    glTranslatef(bx + 100, 150, 0);
    cloud_model_one();
    glPopMatrix();
}

///*** Cloud_Three_Model_Two ***///

void cloud_three()
{
    glPushMatrix();
    glTranslatef(ax - 80, 80, 0);
    cloud_model_Two();
    glPopMatrix();
}
///*** Cloud_Four_Model_Two ***///

void cloud_four()
{
    glPushMatrix();
    glTranslatef(dx + 300, 125, 0);
    cloud_model_Two();
    glPopMatrix();
}
///*** Cloud_Five_Model_Three ***///
void cloud_five()
{

    glPushMatrix();
    glTranslatef(ax + -300, 170, 0);
    cloud_model_Three();
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six()
{

    glPushMatrix();
    glTranslatef(cx + -500, 20, 0);
    cloud_model_Three();
    glPopMatrix();
}

///*** House_One ***///
void house_one()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_two()
{
    glPushMatrix();
    glTranslatef(450, 0, 0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_three()
{
    glPushMatrix();
    glTranslatef(320, 37, 0);
    house();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two()
{
    glPushMatrix();
    glTranslatef(550, -20, 0);
    hill_big();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hill_small();
    glPopMatrix();
}
/// *** Tilla_One_Model_One ***///

void Tilla_One()
{

    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tilla_One_Model();
    glPopMatrix();
}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two()
{

    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tilla_Two_Model();
    glPopMatrix();
}
/// *** Tilla_Three_Model_Two ***///
void Tilla_Three()
{

    glPushMatrix();
    glTranslatef(400, 0, 0);
    Tilla_Two_Model();
    glPopMatrix();
}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four()
{

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380, 0, 0);
    Tilla_One_Model();
    glPopMatrix();
}
///*** Tree_1 ***///
void Tree_One()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292, 40, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30, -20, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50, -10, 0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322, 0, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350, -15, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760, -25, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90, -2, 0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125, 0, 0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408, -22, 0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0, -10, 0);
    Windmill();
    glPopMatrix();
}

void Windmill_Two()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508, -70, 0);
    Windmill();
    glPopMatrix();
}
void Windmill_Three()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108, -90, 0);
    Windmill();
    glPopMatrix();
}
/// Object_End
///=========================================================================================================///

//************charactar**********************
void drawOpenCircle(float posx, float posy, float r)
{
    glColor3f(0.0f, 0.3f, 0.5f);
    glPointSize(3);
    glBegin(GL_POINTS);
    for (float i = 0; i < 360; i += 0.01)
    {
        float deginrad = i * 3.14 / 180;
        glVertex2f(posx + r * cos(deginrad), posy + r * sin(deginrad));
        glVertex2f(posx, posy);
    }

    glEnd();
}

void drawCloseCircleWhite(float posx, float posy, float r)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(3);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.01)
    {
        float deginrad = i * 3.14 / 180;
        glVertex2f(posx + r * cos(deginrad), posy + r * sin(deginrad));
        glVertex2f(posx, posy);
    }

    glEnd();
}

void drawCloseCircleBlue(float posx, float posy, float r)
{
    glColor3f(0.0f, 0.5f, 0.9f);
    glPointSize(3);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.01)
    {
        float deginrad = i * 3.14 / 180;
        glVertex2f(posx + r * cos(deginrad), posy + r * sin(deginrad));
        glVertex2f(posx, posy);
    }

    glEnd();
}

void drawCloseCircleBrawn(float posx, float posy, float r)
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3);
    glBegin(GL_POLYGON);
    for (float i = 0; i < 360; i += 0.01)
    {
        float deginrad = i * 3.14 / 180;
        glVertex2f(posx + r * cos(deginrad), posy + r * sin(deginrad));
        glVertex2f(posx, posy);
    }

    glEnd();
}

void char1()
{
    // backgrround
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3f, 0.5f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.2f, -0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.9f);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.6f, 0.6f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.2f, 0.3f);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.6f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.9f);
    glVertex2f(-0.25f, 0.73f);
    glVertex2f(-0.31f, 0.6f);
    glVertex2f(-0.114f, 0.6f);
    glVertex2f(-0.25f, 0.73f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.2f, 0.3f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.2f, -0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.2f, 0.3f);
    glVertex2f(-0.25f, 0.73f);
    glVertex2f(-0.31f, 0.6f);
    glVertex2f(-0.31f, 0.6f);
    glVertex2f(-0.114f, 0.6f);
    glVertex2f(-0.114f, 0.6f);
    glVertex2f(-0.25f, 0.73f);
    glEnd();
    //************************ twoLines **************************************
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.3f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.144f, -0.6f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.2f, -0.54f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.3f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.6f, -0.55f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.556f, -0.6f);
    glEnd();

    /***************************** nois ****************************************/
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.3f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.7f, 0.3f, 0.0f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.3f, 0.0f);
    glEnd();

    //***************************** legs ****************************************
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(-0.4f, -0.49f);
    glVertex2f(-0.25f, -0.49f);
    glVertex2f(-0.25f, -0.6f);
    glVertex2f(-0.4f, -0.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(-0.15f, -0.6f);
    glVertex2f(-0.15f, -0.49f);
    glVertex2f(-0.0f, -0.49f);
    glVertex2f(-0.0f, -0.6f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.7f, 0.3f, 0.0f);
    glVertex2f(-0.4f, -0.49f);
    glVertex2f(-0.25f, -0.49f);
    glVertex2f(-0.25f, -0.49f);
    glVertex2f(-0.25f, -0.6f);
    glVertex2f(-0.25f, -0.6f);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(-0.4f, -0.6f);
    glVertex2f(-0.4f, -0.49f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.7f, 0.3f, 0.0f);
    glVertex2f(-0.15f, -0.6f);
    glVertex2f(-0.15f, -0.49f);
    glVertex2f(-0.15f, -0.49f);
    glVertex2f(-0.0f, -0.49f);
    glVertex2f(-0.0f, -0.49f);
    glVertex2f(-0.0f, -0.6f);
    glVertex2f(-0.0f, -0.6f);
    glVertex2f(-0.15f, -0.6f);
    glEnd();

    //**************************** leftEay ********************************
    drawCloseCircleWhite(-0.424, 0.304, 0.1765443542938);
    drawCloseCircleBlue(-0.424, 0.304, 0.0887617189669);
    drawOpenCircle(-0.424, 0.304, 0.0887617189669);
    drawOpenCircle(-0.424, 0.304, 0.1765443542938);

    //********************************* rightEay *******************************************
    drawCloseCircleWhite(0.023, 0.293, 0.1765443542938);
    drawCloseCircleBlue(0.023, 0.293, 0.0887617189669);
    drawOpenCircle(0.023, 0.293, 0.0887617189669);
    drawOpenCircle(0.023, 0.293, 0.1765443542938);
}

//*********************************************************************************

void cir(float x, float y, float r)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    // COLOROKSTRING;
    double a = 22, b = 7, pi = a / b;

    for (float i = 0; i <= 2 * pi; i += pi / 360)
        glVertex2f(x + sin(i) * r, y + cos(i) * (1.4 * r));

    glEnd();
}

void cirr(float x, float y, float r)
{
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    // COLOROKSTRING;
    double a = 22, b = 7, pi = a / b;

    for (float i = 0; i <= 2 * pi; i += pi / 360)
        glVertex2f(x + sin(i) * r, y + cos(i) * (1.4 * r));

    glEnd();
}

void cirr2(float x, float y, float r)
{
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.f);
    // COLOROKSTRING;
    double a = 22, b = 7, pi = a / b;

    for (float i = 0; i <= 2 * pi; i += pi / 360)
        glVertex2f(x + sin(i) * r, y + cos(i) * (1.4 * r));

    glEnd();
}

void cir2(float x, float y, float r)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = -90; i < 90; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir22(float x, float y, float r)
{
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.6f, 0.5f);
    double a = 22, b = 7, pi = a / b;

    for (float i = -90; i < 90; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir3(float x, float y, float r)
{
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = 90; i < 270; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir4(float x, float y, float r)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = 0; i < 180; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir44(float x, float y, float r)
{
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = 0; i < 180; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir5(float x, float y, float r)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = -180; i < 0; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir55(float x, float y, float r)
{
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = -180; i < 0; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir6(float x, float y, float r)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.8f, 0.8f, 0.4f);
    double a = 22, b = 7, pi = a / b;

    for (float i = 0; i <= 2 * pi; i += pi / 360)
        glVertex2f(x + sin(i) * r, y + cos(i) * (1.4 * r));

    glEnd();
}

void cir66(float x, float y, float r)
{
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = 0; i <= 2 * pi; i += pi / 360)
        glVertex2f(x + sin(i) * r, y + cos(i) * (1.4 * r));

    glEnd();
}

void cir7(float x, float y, float r)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = -90; i < 90; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void cir77(float x, float y, float r)
{
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    double a = 22, b = 7, pi = a / b;

    for (float i = -90; i < 90; i += 1)
        glVertex2f(x + sin(i * 3.14 / 180) * r, y + cos(i * 3.14 / 180) * (r));

    glEnd();
}

void man()
{

    // if (man_posy > -0.45)man_posy -= 0.0007;
    // first Quads
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glPointSize(100);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.5f, 0.5f);
    glEnd();

    // first Quads
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(100);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.5f, 0.5f);
    glEnd();

    //.........2.......................
    // 2 Quads
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(100);
    glVertex2f(-0.5f, -0.2f);

    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.5f, -0.6f);
    glVertex2f(-0.5f, -0.6f);

    glEnd();

    // 2 Quads
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(100);
    glVertex2f(-0.5f, -0.2f);

    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.5f, -0.6f);
    glVertex2f(-0.5f, -0.6f);

    glEnd();

    //................3.................

    // cr1
    cirr(-0.2748162243232, 0.1923058295183, 0.15);
    cir(-0.2748162243232, 0.1923058295183, 0.15);

    // cr1
    cirr2(-0.2748162243232, 0.1923058295183, 0.09);
    cir(-0.2748162243232, 0.1923058295183, 0.09);

    // cr2
    cirr(0.2797876771572, 0.2023439091831, 0.15);
    cir(0.2797876771572, 0.2023439091831, 0.15);

    // cr2
    cirr2(0.2797876771572, 0.2023439091831, 0.09);
    cir(0.2797876771572, 0.2023439091831, 0.09);

    //................4..................

    // cr3
    cir22(0.0f, -0.2f, 0.22);
    cir2(0.0f, -0.2f, 0.22);

    // cr4
    cir3(0.0f, -0.05f, 0.1);

    //..........5..................
    // cr5
    cir44(0.5f, -0.057f, 0.1);
    cir4(0.5f, -0.057f, 0.1);

    // cr6
    cir55(-0.5f, -0.057, 0.1);
    cir5(-0.5f, -0.057, 0.1);

    // cr7
    cir66(0, -0.4, 0.09);
    cir6(0, -0.4, 0.09);
    //.........feet...........................
    // cr8
    cir77(-0.3f, -0.8, 0.2);
    cir7(-0.3f, -0.8, 0.2);

    // cr9
    cir77(0.3f, -0.8, 0.2);
    cir7(0.3f, -0.8, 0.2);

    // last line
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(100);
    glVertex2f(-0.1f, -0.8f);
    glVertex2f(-0.5f, -0.8f);

    glEnd();

    // last line 2
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1f, 0.1f, 0.1f);
    glPointSize(100);
    glVertex2f(0.1f, -0.8f);
    glVertex2f(0.5f, -0.8f);

    glEnd();

    // arm1
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(100);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.6008422758294f, -0.5120501458475f);
    glVertex2f(-0.5f, -0.56f);

    // glVertex2f(-0.5f, -0.56f);
    // glVertex2f(-0.63f, -0.57f);

    glEnd();

    // arm1
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glPointSize(100);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.6008422758294f, -0.5120501458475f);
    glVertex2f(-0.5f, -0.56f);

    // glVertex2f(-0.5f, -0.56f);
    // glVertex2f(-0.63f, -0.57f);

    glEnd();

    // arm1
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(100);

    glVertex2f(-0.6008422758294f, -0.5120501458475f);

    glVertex2f(-0.5f, -0.56f);
    glVertex2f(-0.63f, -0.57f);

    glEnd();

    // arm1
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(100);

    glVertex2f(-0.6008422758294f, -0.5120501458475f);

    glVertex2f(-0.5f, -0.56f);
    glVertex2f(-0.63f, -0.57f);

    glEnd();

    // arm2
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(100);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.6008422758294f, -0.5120501458475f);
    glVertex2f(0.5f, -0.56f);

    // glVertex2f(-0.5f, -0.56f);
    // glVertex2f(-0.63f, -0.57f);

    glEnd();

    // arm2
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glPointSize(100);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.6008422758294f, -0.5120501458475f);
    glVertex2f(0.5f, -0.56f);

    // glVertex2f(-0.5f, -0.56f);
    // glVertex2f(-0.63f, -0.57f);

    glEnd();

    // arm2
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(100);

    glVertex2f(0.6008422758294f, -0.5120501458475f);

    glVertex2f(0.5f, -0.56f);
    glVertex2f(0.63f, -0.57f);

    glEnd();

    // arm2
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(100);

    glVertex2f(0.6008422758294f, -0.5120501458475f);

    glVertex2f(0.5f, -0.56f);
    glVertex2f(0.63f, -0.57f);

    glEnd();

    // glutSwapBuffers();
    // glutPostRedisplay();
}

//**********************draw ball***************************************
void ball()
{
    drawCloseCircleBrawn(0.0f, 0.0f, 0.1087617189669);
}

///========================///
///*** Display Function ***///
///========================///

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);

    ///*** Object_Layer ***///
    Sun();

    Windmill_Three();

    Hill_Big_One();
    Tilla_Four();

    house_three();

    Hill_Big_Two();
    Hill_Small_One();

    cloud_three();
    cloud_four();

    Windmill_One();
    Windmill_Two();

    Tilla_One();
    Tilla_Two();
    Tilla_Three();

    house_one();
    cloud_one();
    house_two();

    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();

    cloud_two();
    cloud_five();
    cloud_six();
    field();

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(posxChar, 0.35f, 0.0f);
    glScalef(0.085, 0.065, 0.0);
    char1();
    posxChar -= 0.01;

    if (posxChar <= 0.75 && posxChar >= 0.62)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(0.73f, posyBall, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall -= 0.1;
        if (posyBall <= -0.9)
        {
            posyBall = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= 0.61 && posxChar >= 0.48)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(0.59f, posyBall2, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall2 -= 0.1;
        if (posyBall2 <= -0.9)
        {
            posyBall2 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= 0.47 && posxChar >= 0.34)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(0.45f, posyBall3, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall3 -= 0.1;
        if (posyBall3 <= -0.9)
        {
            posyBall3 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= 0.20 && posxChar >= 0.07)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(0.18f, posyBall4, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall4 -= 0.1;
        if (posyBall4 <= -0.9)
        {
            posyBall4 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= 0.06 && posxChar >= -0.07)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(0.04f, posyBall5, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall5 -= 0.1;
        if (posyBall5 <= -0.9)
        {
            posyBall5 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= -0.08 && posxChar >= -0.21)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(-0.1f, posyBall6, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall6 -= 0.1;
        if (posyBall6 <= -0.9)
        {
            posyBall6 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= -0.22 && posxChar >= -0.35)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(-0.24f, posyBall7, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall7 -= 0.1;
        if (posyBall7 <= -0.9)
        {
            posyBall7 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= -0.36 && posxChar >= -0.49)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(-0.38f, posyBall8, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall8 -= 0.1;
        if (posyBall8 <= -0.9)
        {
            posyBall8 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= -0.5 && posxChar >= -0.63)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(-0.52f, posyBall9, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall9 -= 0.1;
        if (posyBall9 <= -0.9)
        {
            posyBall9 = 0.31;
        }
        glPopMatrix();
    }

    if (posxChar <= -0.64 && posxChar >= -0.77)
    {
        glPushMatrix();
        glLoadIdentity();

        glTranslatef(-0.66f, posyBall10, 0.0f);
        glScalef(0.085, 0.065, 0.0);
        ball();
        posyBall10 -= 0.1;
        if (posyBall10 <= -0.9)
        {
            posyBall10 = 0.31;
        }
        glPopMatrix();
    }

    glPopMatrix();

    //   for (int i = 0; i < 10; i++){

    //     c[i].posxChar -= 0.001;
    //   }

    // for (int i = 0; i < 10; i++){

    //     glPushMatrix();
    //     glLoadIdentity();
    //     glTranslatef(RandomNumber(-1.2,1.0), RandomNumber(0.35,0.50) ,0.0f);
    //     glScalef(0.085,0.065,0.0);
    //     char1();
    //     glTranslatef(c[i].posxChar,c[i].posyChar,0.0);
    //     glPopMatrix();
    //   }

    if (posxChar <= -1)
    {
        posxChar = 1;
    }

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(posx, -0.70f, 0.0f);
    glScalef(0.095, 0.095, 0.0);
    man();
    glPopMatrix();


    if (posx <= 0.73 && posyBall <= -0.70)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
        glEnd();

        drawString(0.0, 0.0, 0, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER!!!");
    }

    glFlush();
}

///========================///
///*** Speed & Movement ***///
///========================///
///*** Sun_Move ***///
void sun_move()
{

    sun_spin = sun_spin + 0.08;
}
void move_right()
{

    sun_move();

    spin = spin + 2.0;
    ax = ax + .5;
    bx = bx + .8;
    cx = cx + .2;
    dx = dx + .2;

    if (cx > 1000)
    {
        cx = -300;
    }
    if (bx > 1000)
    {
        bx = -400;
    }
    if (cx > 1000)
    {
        cx = -400;
    }
    if (dx > 1000)
    {
        dx = -500;
    }

    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

void input_callback(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        if (man_posy < 0.45)
        {
            man_posy += man_posy_speed;
        }
        else if (man_posy > -0.45)
        {
            man_posy -= man_posy_speed;
        }
        man_posy = -0.45;
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1900, 1900);

    glutCreateWindow("Smart Village");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(windowkey);
    glutMouseFunc(mouse);
    glutMainLoop();
    glutSpecialFunc(input_callback);
}

/*
if(man_posy>1.0){
man_posy=100;
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.0f, 1.0f);
glVertex2f(1.0f, 1.0f);
glVertex2f(1.0f, -1.0f);
glVertex2f(-1.0f, -1.0f);

glEnd();

drawString(0.0,0.0,0,GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER!!!");

}
*/

/*
void drawString(float x,float y,float z,void *font,char *string)
{
glColor3f(1.0f, 1.0f, 1.0f);
 char *c;
 glRasterPos3f(x, y,z);

 for (c=string; *c != '\0'; c++)
 {
  glutBitmapCharacter(font, *c);
 }
}
*/