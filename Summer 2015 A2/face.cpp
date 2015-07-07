#include "face.h"
#include "material.h"

#include <GL/glut.h>

#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

Face::Face() {
    m = NULL;
}

Face::Face(Material *m) {
    this->m = m;
}

void Face::render(vector<Vertex> *v) {
    int vn = vid.size();
    glBegin(GL_POLYGON);
    if (m != NULL)
        m->useMaterial();
    n.useNormal();
    for (int i = 0; i < vn; i++) {
        glVertex3f(v->at(vid[i]).getX(), v->at(vid[i]).getY(), v->at(vid[i]).getZ());
    }
    glEnd();
}

void Face::addVid(int n) {
    vid.push_back(n - 1);
}

void Face::computeNormal(vector<Vertex> *v) {
    // need two vectors a (from point 0 to 1) and b (from point 0 to n-1)
    float x, y, z;
    int vn = vid.size();
    x = v->at(vid[1]).getX() - v->at(vid[0]).getX();
    y = v->at(vid[1]).getY() - v->at(vid[0]).getY();
    z = v->at(vid[1]).getZ() - v->at(vid[0]).getZ();
    Vertex a(x, y , z);
    x = v->at(vid[vn - 1]).getX() - v->at(vid[0]).getX();
    y = v->at(vid[vn - 1]).getY() - v->at(vid[0]).getY();
    z = v->at(vid[vn - 1]).getZ() - v->at(vid[0]).getZ();
    Vertex b(x, y, z);
    n = Normal( a.getY() * b.getZ() - a.getZ() * b.getY(),
                a.getZ() * b.getX() - a.getX() * b.getZ(),
                a.getX() * b.getY() - a.getY() * b.getX() );
    n.normalize();
}
