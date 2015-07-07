#include "object.h"
#include <iostream>
using namespace std;

Object::Object() {
    name = "UNDEFINED";
    parentModel = NULL;
}

Object::Object(string name, ObjModel *parentModel) {
    this->name = name;
    this->parentModel = parentModel;
}

void Object::render() {
    int n = f.size();
    for (int i = 0; i < n; i++)
        f[i].render(parentModel->getVertices());
}

void Object::addFace(Face face) {
    f.push_back(face);
}

void Object::print() {
    cout << name << ", V: " << parentModel->getVertices()->size() << ", F: " << f.size() << endl;
}

bool Object::isNull() {
    return parentModel == NULL;
}
