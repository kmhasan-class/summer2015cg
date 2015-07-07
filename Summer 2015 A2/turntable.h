#ifndef _TURNTABLE_H_
#define _TURNTABLE_H_

#include "model.h"

/**
@file turntable.h
\brief A simple extention of Model class to create a circular turntable on which the models will be placed.
@author Monirul Hasan <kmhasan@gmail.com>
@date March 2014
*/
class Turntable : public Model {
private:
    double baseRadius; /**< the base radius of the turntable */
    double baseHeight; /**< the base height of the turntable */

    float ambient[4]   = {195.0 / 255 * 0.20, 196.0 / 255 * 0.20, 197.0 / 255 * 0.20, 1.0}; /**< ambient value for aluminium */
    float diffuse[4]   = {195.0 / 255 * 0.75, 196.0 / 255 * 0.75, 197.0 / 255 * 0.75, 1.0}; /**< diffuse value for aluminium */
    float specular[4]  = {1.0, 1.0, 1.0, 1.0};                                              /**< specular value for aluminium */
    float shininess[1] = {41.0};                                                            /**< shininess value for aluminium */

public:
    /**
    \brief Default constructor for the Turntable class.

    Simply calls the Model() constructor of the base class Model.
    */
    Turntable();

    /**
    \brief Overloaded constructor that takes radius and height as parameters.

    Calls the default constructor Turntable() first and then sets up radius and height as passed.
    @param r is the radius
    @param h is the height
    */
    Turntable(double r, double h);

    /**
    \brief Renders the turntable flat out on the zx-plane.

    The turntable is created with 3 tapered cylinders using gluCylinder() function calls. The topmost cylinder has
    top radius set to zero giving an appearance of closed off lid to the base cylinder.
    */
    void render();
};

#endif

