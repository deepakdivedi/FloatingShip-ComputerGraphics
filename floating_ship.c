#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

GLfloat x1=0.0;
int z=0,a;
int boat1,basic;

void sky()
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(0,730);
	glVertex2f(999,730);
	glVertex2f(999,999);
	glVertex2f(0,999);
	glEnd();
}

void boat(int x,int y)
{
//base
    glBegin(GL_POLYGON);
	glColor3f(0.40f,0.06f,0.42f);
	glVertex2f(20+x,238+y);
	glColor3f(0.30f,0.06f,0.42f);
	glVertex2f(20+x,220+y);
	glColor3f(.0f,0.0f,0.0f);
	glVertex2f(82+x,140+y);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex2f(438+x,84+y);
	glColor3f(0.32f,0.06f,0.42f);
	glVertex2f(584+x,196+y);
	glColor3f(0.30f,0.06f,0.42f);
	glVertex2f(600+x,220+y);
	glEnd();

    /*above base front side*/
    glColor3f(0.6,0.4,0.5);
    glBegin(GL_POLYGON);
	glVertex2f(70+x,236+y);
	glVertex2f(70+x,256+y);
	glVertex2f(478+x,262+y);
	glVertex2f(478+x,222+y);
	glVertex2f(70+x,238+y);
	glEnd();

    /*Second Layer above base Front side*/
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
	glVertex2f(90+x,258+y);
	glVertex2f(90+x,280+y);
	glVertex2f(466+x,298+y);
	glVertex2f(466+x,262+y);
	glVertex2f(90+x,258+y);
	glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
	glVertex2f(90+x,258+y);
	glVertex2f(90+x,280+y);
	glVertex2f(466+x,298+y);
	glVertex2f(466+x,262+y);
	glVertex2f(90+x,258+y);
	glEnd();

    /*Top Layer above base Front side*/
    glColor3f(0.30,0.30,0.30);
    glBegin(GL_POLYGON);
	glVertex2f(102+x,302+y);
	glVertex2f(102+x,280+y);
	glVertex2f(442+x,298+y);
	glVertex2f(442+x,330+y);
	glVertex2f(102+x,302+y);
    glEnd();

    /*Top third pillar from right*/
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
	glVertex2f(158+x,304+y);
	glVertex2f(158+x,388+y);
	glColor3f(0.3,0.3,0.0);
	glVertex2f(188+x,388+y);
	glVertex2f(188+x,304+y);
    glEnd();

    /*Top Layer above base Right side*/
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,0.4);
	glVertex2f(442+x,328+y);
	glVertex2f(442+x,298+y);
	glVertex2f(494+x,294+y);
	glVertex2f(494+x,324+y);
	glVertex2f(318+x,322+y);
	glEnd();

    /*Second Layer above base Right side*/
    glBegin(GL_POLYGON);
    glColor3f(0.80,0.80,0.80);
	glVertex2f(466+x,298+y);
	glVertex2f(466+x,262+y);
	glVertex2f(508+x,256+y);
	glVertex2f(508+x,290+y);
	glEnd();

    /*above base right side*/
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.3,0.4);
	glVertex2f(478+x,262+y);
	glVertex2f(478+x,222+y);
	glVertex2f(514+x,220+y);
	glVertex2f(514+x,254+y);
	glEnd();

    /*Top second pillar from right*/
    glColor3f(0.1,0.1,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(224+x,312+y);
	glVertex2f(224+x,396+y);
	glColor3f(0.3,0.3,0.0);
	glVertex2f(254+x,396+y);
	glVertex2f(254+x,312+y);
    glEnd();

    /*Top first pillar from right*/
    glColor3f(0.1,0.1,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(320+x,320+y);
	glVertex2f(320+x,406+y);
	glColor3f(0.5,0.5,0.2);
	glVertex2f(355+x,406+y);
	glVertex2f(355+x,320+y);
	glEnd();

}

void start(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
	glPushMatrix();
	glCallList(basic);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x1,0.0,0.0);
	glCallList(boat1);
	glFlush();
    glPopMatrix();
    glPopMatrix();
    glutPostRedisplay();
    glFlush();
}

void myinit()
{
    glClearColor(0.0,0.4,0.8,0.0);	//background color
    gluOrtho2D(0,999,0,999);
    glPointSize(2.0);
    glLineWidth(2.0);
	basic = glGenLists(1);
	glNewList(basic, GL_COMPILE);
	sky();
	glEndList();
	boat1 = glGenLists(1);
	glNewList(boat1, GL_COMPILE);
	boat(-300,220);
    glEndList();
}

 void floatRight(void)
 {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
	glPushMatrix();
	glCallList(basic);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x1,0.0,0.0);
	glCallList(boat1);
	glFlush();
    glPopMatrix();

    if(z<200)
    {
        a+=5;
        x1=x1+5.0;
        z++;
    }
    glPopMatrix();
    glutPostRedisplay();
    glFlush();
}

void floatLeft(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
	glPushMatrix();
	glCallList(basic);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x1,0.0,0.0);
	glCallList(boat1);
	glFlush();
    glPopMatrix();

    if(z>0)
    {
        a+=5;
        x1=x1-5.0;
        z--;
    }
    glPopMatrix();
    glutPostRedisplay();
    glFlush();
 }

 void floating(unsigned char key,int x,int y){
 	switch(key){
 		case 'l':
 				floatLeft();
 				break;

 		case 'r':
 				floatRight();
 				break;
 		
		case 'L':
 				floatLeft();
 				break;

 		case 'R':
 				floatRight();
 				break;
 		case 'e':
 				exit(0);
 				break;
		case 'E':
 				exit(0);
 				break;		 		
	 }
 }

 int main(int argc,char ** argv)
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1350,700);
    glutCreateWindow("Floating Ship");
    myinit();
    glutDisplayFunc(start);
    glutKeyboardFunc(floating);
    glutMainLoop();
	return 0;
}
