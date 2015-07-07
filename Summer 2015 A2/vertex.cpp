#include "vertex.h"

Vertex::Vertex() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vertex::Vertex(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vertex::getX() { return x; }

float Vertex::getY() { return y; }

float Vertex::getZ() { return z; }
