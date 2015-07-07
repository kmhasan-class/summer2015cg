#include "light.h"
#include <cstring>

Light::Light() {
    on = true;
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

Light::Light(GLenum l):Light() {
    lightnum = l;
    setLightParameters();
    glEnable(lightnum);
}

void Light::setLightParameters() {
    glLightfv(lightnum, GL_POSITION, lightPosition);
    glLightfv(lightnum, GL_AMBIENT, lightAmbient);
    glLightfv(lightnum, GL_DIFFUSE, lightDiffuse);
    glLightfv(lightnum, GL_SPECULAR, lightSpecular);
    glLightf(lightnum, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(lightnum, GL_LINEAR_ATTENUATION, 0.001f);
    glLightf(lightnum, GL_QUADRATIC_ATTENUATION, 0.005f);
}

bool Light::isOn() {
    return on;
}

void Light::setOn(bool mode) {
    on = mode;
    if (on) glEnable(lightnum);
    else glDisable(lightnum);
}

void Light::render() {
    setLightParameters();
    glPushMatrix();
        glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
        if (on)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        else glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, lightAmbient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lightDiffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lightSpecular);
        glutSolidCube(0.2);
    glPopMatrix();
}


void Light::setPosition(float p[4]) {
    memcpy(lightPosition, p, sizeof(float) * 4);
    glLightfv(lightnum, GL_POSITION, lightPosition);
}
