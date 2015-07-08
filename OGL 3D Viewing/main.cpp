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

void setMaterial(float a[], float d[], float s[], float f[]) {
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, a);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, d);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display() {
    theta += 0.1;
    float ambient[] = {0.1, 0.1, 0.0};
    float diffuse[] = {0.4, 0.4, 0.1};
    float specular[] = {0.8, 0.8, 0.8};
    float shininess[] = {50};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 0.001, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
    glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glRotatef(theta, 0, 1, 0);
        setMaterial(ambient, diffuse, specular, shininess);
        glutSolidTeapot(3.0);
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
