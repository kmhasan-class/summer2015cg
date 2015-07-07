#ifndef _OBJMODEL_H_
#define _OBJMODEL_H_

#include "meshmodel.h"
#include "vertex.h"
#include "face.h"
#include "normal.h"
#include "material.h"
#include "object.h"

#include <GL/glut.h>
#include <string>
#include <vector>
using namespace std;

/**
@file objmodel.h
\brief Class that handles models described in .obj files.
\authors Monirul Hasan <kmhasan@gmail.com>, ADD_YOUR_OWN_NAME
@date March 2014

This is the class you'd be playing with! You need to properly implement the readFile() function so that
model's mesh can be read from .obj file and the material properties can be read from the corresponding .mtl file. You
will most likely end up creating classes to handle Objects (parts of the models), Vertex, Face, Normal, Material and
perhaps some more. Store the mesh and material data in appropriate data structures in this class. Then implement the
render() function so that the model can be rendered properly.
*/

class Object;
class ObjModel;

class ObjModel : public MeshModel {
private:
    bool ready; /**< flag to indicate if the model is ready for rendering */
    vector<Vertex> v;
    vector<Material> m;
    vector<Object> o;
    void readObj(char* basename);
    void readMtl(char* basename);

public:
    /**
    \brief Default constructor does nothing but calling the Model() constructor.
    */
    ObjModel();

    /**
    \brief Unimplemented destructor.
    */
    virtual ~ObjModel();

    /**
    \brief Renders the ObjModel.

    You need to implement this function properly. Make sure you translate your model so that it stands on the zx-plane.
    The lowest y-coordinate needs to be at zero.
    */
    void render();

    /**
    \brief Reads ObjModel mesh data from a .obj file and material data from .mtl file.
    @param filename is the base name (without extension) of the data files (for example: teapot, not teapot.obj).

    You need to implement this function properly.

    \warning you need to uncomment a line in this function to let main.cpp know that we're ready to render.
    */
    virtual void readFile(char* filename);

    /**
    \brief Returns true if the model is ready to be rendered, false otherwise.
    */
    bool isReady();

    vector<Vertex>* getVertices();
};

#endif


