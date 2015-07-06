//$sudo apt-get install freeglut3-dev

#include <GL/freeglut.h>
#include <iostream>
using namespace std;

float dx = 0.0;
float theta = 0.0;

void drawObject() {
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.25, 0.25, 0.0);

        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
    glEnd();
}

void drawAxis() {
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(+1.0, 0.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, -1.0, 0.0);
        glVertex3f(0.0, +1.0, 0.0);
    glEnd();
}

void render() {
    dx += 0.001;
    theta -= 1;
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glPushMatrix();
        glRotatef(theta, 0, 0, 1);
        glTranslatef(0.25, 0.0, 0.0);
        drawObject();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Demo");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}
