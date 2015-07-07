#include "material.h"
#include <GL/glut.h>

bool Material::isNull() {
    return name == "UNDEFINED";
}

Material::Material() {
    name = "UNDEFINED";
}

Material::Material(string name) {
    this->name = name;
}

void Material::setAmbient(float ka[3]) {
    for (int i = 0; i < 3; i++)
        this->ka[i] = ka[i];
}

void Material::setDiffuse(float kd[3]) {
    for (int i = 0; i < 3; i++)
        this->kd[i] = kd[i];
}

void Material::setSpecular(float ks[3]) {
    for (int i = 0; i < 3; i++)
        this->ks[i] = ks[i];
}

void Material::setShininess(float shininess[1]) {
    this->shininess[0] = shininess[0];
}

void Material::useMaterial() {
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ka);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kd);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ks);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

string Material::getName() {
    return name;
}
