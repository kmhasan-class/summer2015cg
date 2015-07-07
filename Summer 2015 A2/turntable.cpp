#include "turntable.h"
#include <GL/glut.h>

Turntable::Turntable() : Model() {}

Turntable::Turntable(double r, double h):Turntable() {
    baseRadius = r;
    baseHeight = h;
}

void Turntable::render() {
    Model::render();
    glEnable(GL_LIGHTING);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
    GLUquadric* qobj = gluNewQuadric();
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    gluCylinder(qobj, baseRadius, baseRadius * 0.95, baseHeight, 50, 10);
    glTranslatef(0, 0, baseHeight);
    gluCylinder(qobj, baseRadius * 0.95, 0.0, 0.0, 50, 10);
    glPopMatrix();
}
