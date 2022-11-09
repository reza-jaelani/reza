#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
using namespace std;

float tx=0,ty=0,z_dis=100,z_viewPoint= -120;

GLUquadricObj *rocketBody, *rocketPlate;
GLfloat pos[]= { -35, -8, 5, 1};
GLfloat amb [] = {0.3, 0.3, 0.3, 1.0};
GLfloat front_amb_diff[]= {0.7, 0.5, 0.1,1.0};
GLfloat back_amb_diff[]= {0.4,0.7,0.1,1.0};
GLfloat spe[]= {0.25,0.25,0.25,1.0};
GLfloat theta=0,alpha=0, dt=0.5;

//reza
//body roket
void rocket_body(){
    glPushMatrix ();
    rocketBody = gluNewQuadric();
    gluQuadricDrawStyle(rocketBody, GLU_FILL);
    gluQuadricNormals(rocketBody, GLU_SMOOTH);
    gluQuadricOrientation(rocketBody, GLU_OUTSIDE);

    glColor3f(0.694, 0.694, 0.686);// warna body
    glTranslated(7.5, -18, z_viewPoint);
    glRotated(-90, 1, 0, 0);
    gluCylinder(rocketBody, 4.5, 4.5, 30, 32, 32);

    // gambar roket

    int windows[5]={-5, -10,-15, -20,-25};     // arah jendela
    for(int i=0; i<5; i++){
        glColor3f(0, 0, 0);//warna jendela
        /*if (i==2) {
            glColor3f(255,0,255);
        }
        else {

        }*/
        glPushMatrix ();
        glRotated(90, 0, 0, 1);
        glRotated(-90, 1, 0, 0);
        glTranslated(0, windows[i], 0);
        glScalef(6.45, 1, 1);
        glutSolidCube(1.4);
        glPopMatrix();
    }

    glPopMatrix();
}

//bagian bawah roket
void rocket_bottom(){
    glColor3f(0.564, 0.541, 0.517);
    glPushMatrix();
    glTranslated(7.5, -18, z_viewPoint);
    glRotated(-90, 1, 0, 0);
    glutSolidSphere(4.5, 32, 32);
    glPopMatrix();
}

//kepala roket
void rocket_top(){
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslated(7.5, 12, z_viewPoint);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(4.5,10.0,32,32);
    glPopMatrix();
}

//ekor roket
void rocket_plates(){
    rocketPlate = gluNewQuadric();
    gluQuadricDrawStyle(rocketPlate, GLU_FILL);
    gluQuadricNormals(rocketPlate, GLU_SMOOTH);
    gluQuadricOrientation(rocketPlate, GLU_OUTSIDE);
    glColor3f(0.427, 0.180, 0.094);

    //ekor kanan
    glPushMatrix ();
    glTranslated(7.5, -15.5, z_viewPoint);
    glRotatef(45, 0, 1, 0);
    glRotatef(160, 1, 0, 0);
    gluPartialDisk(rocketPlate,4.5,18, 10, 5, 0, 30);
    glPopMatrix();

    //ekor tengah
    glPushMatrix ();
    glTranslated(7.5, -15.5, z_viewPoint);
    glRotatef(160, 1, 0, 0);// then rotated around x axis for 150 degree.
    glRotatef(-90, 0, 1, 0);//first rotated around y axis for -90 degree.
    gluPartialDisk(rocketPlate,4.5,18, 10, 5, 0, 30);
    glPopMatrix();

    //ekor kiri
    glPushMatrix ();
    glTranslated(7.5, -15.5, z_viewPoint);
    glRotatef(225, 0, 1, 0);
    glRotatef(160, 1, 0, 0);
    gluPartialDisk(rocketPlate,4.5,18, 10, 5, 0, 30);
    glPopMatrix();

    //ekor baru
    glPushMatrix ();
    glTranslated(7.5, -15.5, z_viewPoint);
    glRotatef(225, 0, 1, 0.4);
    glRotatef(-85, 0.1, 0, 0);
    gluPartialDisk(rocketPlate,4.5,18, 10, 5, 0, 30);
    glPopMatrix();
}

//satukan roket
void rocket_assembly() {
    rocket_plates();
    rocket_top();
    rocket_body();
    rocket_bottom();
}

//bintang
void stars(void){
    glColor3f(0.482, 0.937, 0.145);
    glPushMatrix();
    glTranslated(-5.5, 5, -300);
    glutSolidSphere(2.5, 32, 32);
    glPopMatrix();

    glColor3f(0.937, 0.145, 0.145);
    glPushMatrix();
    glTranslated(-15.5, -2.5, -200);
    glutSolidSphere(1.15, 32, 32);
    glPopMatrix();

    glColor3f(0.145, 0.882, 0.937);
    glPushMatrix();
    glTranslated(-5.5, 5, -200);
    glutSolidSphere(2, 32, 32);
    glPopMatrix();


    glColor3f(0.129, 0.168, 0.949);
    glPushMatrix();
    glTranslated(-26.5, 19, -400);
    glutSolidSphere(1.6, 32, 32);
    glPopMatrix();

    glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslated(-30, -20, -100);
    glutSolidIcosahedron();
    glPopMatrix();

    glColor3f(1, 0, 1);
    glPushMatrix();
    glTranslated(-10, 0, -100);
    glutSolidOctahedron();
    glPopMatrix();

    glColor3f(1, 0.51, 0.04);
    glPushMatrix();
    glTranslated(35.5,20 , -250);
    glutSolidSphere(2, 32, 32);
    glPopMatrix();


    glColor3f(0, 0.51, 0.72);
    glPushMatrix();
    glTranslated(35.5,-20 , -200);
    glRotated(-90, 1, 0, 0);
    glutSolidSphere(1.5, 32, 32);
    glPopMatrix();

    glColor3f(0.486, 0.862, 0.035);
    glPushMatrix();
    glTranslated(-50, -10, -150);
    glutSolidIcosahedron();
    glPopMatrix();

}


//fungsi display
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

    glPushMatrix();
    glTranslated(5, 10, z_dis - 300);
    stars();

    glPopMatrix();
    z_dis+=0.8;//kecepatan

    if(theta>359 && theta < 360)  //reset rotasi
    {
        z_dis=100;
        z_viewPoint +120;
    }
/*
    else if(theta < 46) {
        glPushMatrix();
        glTranslated(tx, ty, 0);
        glTranslated(0, 0, z_dis);
        glRotated(-theta*1.1, 1, 0, 0);
        glTranslated(-6.5, 0, z_viewPoint*(-1));
        rocket_assembly();
        glPopMatrix();

    }
*/
    else{
        glPushMatrix();
        glTranslated(6.5, 0, z_viewPoint);
        glRotated(-50, 1, 0, 0);
        glTranslated(-6.7,0,z_viewPoint*(-1));

        glPushMatrix();
        glTranslated(6.5, 0, z_viewPoint); //posisi
        glRotated(-alpha, 0, 1, 0);
        alpha = alpha+2;
        glTranslated(-6.5, 0, z_viewPoint*(-1));
        rocket_assembly();
        if(z_dis > 3000)
            z_viewPoint-=0.10;
        glPopMatrix();

        glPopMatrix();
    }
    glPopMatrix();
    glutSwapBuffers();
}

void idle(void){
    theta = (theta <360) ? theta+dt:dt;
    tx= tx;
    ty = ty;
    //glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("roket");
    glClearColor(0, 0, 0, 1);       //warna bg
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0, 10, 10000);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, front_amb_diff);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, back_amb_diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spe);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 45);

    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glEnable(GL_NORMALIZE);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);


    glutDisplayFunc(display);
    glutIdleFunc(idle); //jadikan komentar / hapus fungsi ini supaya diam


    glutMainLoop();
    return 0;
}





