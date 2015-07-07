#ifndef _TEAPOT_H_
#define _TEAPOT_H_

#include "model.h"

/**
@file teapot.h
\brief Simple example of a subclass created from Model class.
@author Monirul Hasan <kmhasan@gmail.com>
@date March 2014

This class sets up a golden teapot.
*/
class Teapot : public Model {
private:
    double size;                                                /**< relative size of the teapot */
    float ambient[4]   = {0.24725, 0.2245, 0.0645, 1.0};        /**< ambient value for gold material */
    float diffuse[4]   = {0.34615, 0.3143, 0.0903, 1.0};        /**< diffuse value for gold material */
    float specular[4]  = {0.797357, 0.723991, 0.208006, 1.0};   /**< specular value for gold material */
    float shininess[1] = {51.2};                                /**< shininess value for gold material */

public:
    /**
    \brief Default constructor does nothing but calling the Model() constructor.
    */
    Teapot();

    /**
    \brief Overloaded constructor that takes size of the teapot as input.

    @param s is the relative size of the teapot.
    */
    Teapot(double s);

    /**
    \brief Unimplemented destructor. Doesn't have anything to free up.
    */
    ~Teapot();

    /**
    \brief Renders the teapot.
    */
    void render();
};

#endif
