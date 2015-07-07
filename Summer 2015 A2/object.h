#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "objmodel.h"

#include <string>

class ObjModel;
class Object;

class Object {
private:
    ObjModel *parentModel;
    string name;
    vector<Face> f;

public:
    Object();
    Object(string name, ObjModel *parentModel);
    void render();
    void addFace(Face face);
    void print();
    bool isNull();
};

#endif
