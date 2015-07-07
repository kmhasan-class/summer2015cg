#ifndef _FACE_H_
#define _FACE_H_

#include "material.h"
#include "vertex.h"
#include "normal.h"

#include <vector>
using namespace std;

class Face {
private:
    Material* m;
    bool smooth;
    vector<int> vid;
    Normal n;

public:
    Face();
    Face(Material* m);
    void render(vector<Vertex> *v);
    void addVid(int n);
    void computeNormal(vector<Vertex> *v);
};

#endif
