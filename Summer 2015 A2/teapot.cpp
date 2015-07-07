#include "teapot.h"
#include <GL/glut.h>

Teapot::Teapot() : Model() {}

Teapot::Teapot(double s) : Teapot() {
    size = s;
}

Teapot::~Teapot() {}

void Teapot::render() {
    Model::render();    // make sure super classe's render function is called
    glEnable(GL_LIGHTING);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    glPushMatrix();
        glTranslatef(0, size * 3 / 4.0, 0);
        glutSolidTeapot(size);
    glPopMatrix();
}
