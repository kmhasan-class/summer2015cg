#include "model.h"

Model::Model() {
    wireFrame = false;
}

Model::~Model() {}

void Model::render() {
    if (wireFrame)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_LIGHTING);
}

void Model::setWireFrame(bool w) {
    wireFrame = w;
}
