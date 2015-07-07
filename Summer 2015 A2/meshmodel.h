#ifndef _MESHMODEL_H_
#define _MESHMODEL_H_

#include "model.h"

#include <GL/glut.h>
#include <string>
using namespace std;

/**
@file meshmodel.h
\brief Base class for all mesh models for which we will read data from files.
@author Monirul Hasan <kmhasan@gmail.com>
@date March 2014

Ideally, this class should never be instantiated. We'll be creating subclasses where the render() function
will say how the model will be rendered, and readFile() function will say how data for the model will be loaded.
*/
class MeshModel : public Model {
public:
    /**
    \brief Default constructor does nothing but calling the Model() constructor.
    */
    MeshModel();

    /**
    \brief Unimplemented destructor.
    */
    virtual ~MeshModel();

    /**
    \brief Renders the MeshModel.
    */
    void render();

    /**
    \brief Reads MeshModel data from a file.
    @param filename is the name of the data file.
    */
    virtual void readFile(char* filename);

};

#endif

