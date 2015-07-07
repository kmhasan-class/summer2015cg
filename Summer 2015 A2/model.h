#ifndef _MODEL_H_
#define _MODEL_H_

#include <GL/glut.h>
#include <string>
using namespace std;

/**
@file model.h
\brief Base class for all models.
@author Monirul Hasan <kmhasan@gmail.com>
@date March 2014

Ideally, this class should never be instantiated. We'll be creating subclasses where the render() function
will say how the model will be rendered.
*/
class Model {
private:
    bool wireFrame; /**< boolean flag marks whether to display as wireframe or as solid. */

public:
    /**
    \brief Default constructor: only sets wireframe mode to false.
    */
    Model();

    /**
    \brief Unimplemented destructor.
    */
    virtual ~Model();

    /** \brief Placeholder for the render function.

    Make sure you call this base (Model) class' render function right at the start of your render function
    in the subclass. This one sets up the model so that the model can be viewed as both wireframe and solid.
    As we'll be placing the models on a turntable, one should ensure that the model is appropriately translated
    so that the lowest y-coordinate is set to zero.
    */
    virtual void render();

    /** \brief Setter function for wireframe/solid mode.

    @param w is a boolean value indicating whether the model should be rendered as wireframe (true) or solid (false).
    */
    void setWireFrame(bool w);
};

#endif
