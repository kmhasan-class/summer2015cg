#include <GL/freeglut.h>

float aspectRatio = 1.0;
float theta = 0.0;

void reshape(int width, int height) {
    aspectRatio = ((float) width) / height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 0.001, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    theta += 0.1;
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 0.001, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
    glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        //glRotatef(theta, 0, 1, 0);
        //glutSolidTeapot(3.0);
        glTranslatef(0, 2, 0);
        glRotatef(90, 1, 0, 0);
        glutWireCylinder(0.5, 4, 6, 4);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("3D Viewing");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
