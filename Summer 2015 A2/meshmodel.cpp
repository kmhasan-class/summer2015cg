#include "meshmodel.h"
#include <GL/glut.h>

MeshModel::MeshModel() : Model() {}

MeshModel::~MeshModel() {}

void MeshModel::render() {
    Model::render();    // make sure super classe's render function is called
}

void MeshModel::readFile(char* filename) {}
