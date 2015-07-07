#include "normal.h"
#include <GL/glut.h>
#include <cmath>

Normal::Normal() {
    i = 0.0f;
    j = 0.0f;
    k = 0.0f;
}

Normal::Normal(float i, float j, float k) {
    this->i = i;
    this->j = j;
    this->k = k;
}

void Normal::normalize() {
    float d = sqrt(i * i + j * j + k * k);
    i = i / d;
    j = j / d;
    k = k / d;
}

void Normal::useNormal() {
    glNormal3f(i, j, k);
}
