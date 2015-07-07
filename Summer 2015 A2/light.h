#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <GL/glut.h>

/**
@file light.h
\brief A simple Light class to facilitate light control in the scene.
@author Monirul Hasan <kmhasan@gmail.com>
@date March 2014
*/
class Light {
private:
    float lightPosition[4] = {8.0, 6.0, 5.0, 1.0};  /**< position of the light */
    float lightAmbient[4]  = {0.2, 0.2, 0.2, 1.0};  /**< ambient color of the light */
    float lightDiffuse[4]  = {1.0, 1.0, 1.0, 1.0};  /**< diffuse color of the light */
    float lightSpecular[4] = {1.0, 1.0, 1.0, 1.0};  /**< specular color of the light */
    GLenum lightnum;                                /**< light number */
    bool on;                                        /**< flag indicating whether this light is on or not */

    /**
    \brief private function setting up the light parameters for proper rendering.
    */
    void setLightParameters();

public:
    /**
    \brief Default constructor: sets the light to be on, enables lighting and enables depth testing.
    */
    Light();

    /**
    \brief Overloaded constructor that works for a particular light number.

    Calls the default constructor Light() and then sets up the different light parameters for the given light number.
    @param l is the light number, valid values are GL_LIGHT0, GL_LIGHT1, ... GL_LIGHT7
    */
    Light(GLenum l);

    /**
    \brief Function to check if this light is on or not.

    @return true if the light is on, false otherwise.
    */
    bool isOn();

    /**
    \brief Setter function to turn this light on or off.

    @param mode value true indicates that this light should be turned on, false indicates that it will be turned off.
    */
    void setOn(bool mode);

    /**
    \brief Setter function to set the new position of the light.

    @param p is the new position vector for this light.
    */
    void setPosition(float p[4]);

    /**
    \brief Renders this light in the scene as a cube.

    If the light is turned on, the render will be a solid cube. Otherwise it will be a wire cube. The light will be drawn
    with material properties following the light's color.
    */
    void render();
};

#endif
