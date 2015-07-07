/**
@file main.cpp
@author Monirul Hasan <kmhasan@gmail.com>
@date July 7, 2015

\brief Summer 2015 Assignment #2

Submission deadline: 11:59 PM Friday July 24, 2014

Email subject line: CSE4013Spring2014A3

Task: Load a car model (preferably the one you submitted for the previous assignment) and drive it. As it is, the model loads up just fine, but the faces render flat shaded.
You need to export the obj with the vertex normals written out in the .obj file. You also need to modify the file reading code so that it can handle vertex normal information.
Figure out how you can set normals in OpenGL and how to get OpenGL to show the model smooth shaded. As for driving the car, at the very least you need to have the wheels rotate
and the car move forward.

@warning Any sign of copying will result in a zero score for everyone involved. Depending on the severity of the offense,
I may issue further penalty.
*/

#include <GL/glut.h>
#include <cmath>
#include <chrono>
#include <iostream>
#include <string>
#include <pthread.h>

#include "model.h"
#include "teapot.h"
#include "turntable.h"
#include "light.h"
#include "meshmodel.h"
#include "objmodel.h"

using namespace std;

//timers
chrono::time_point<chrono::system_clock> last;      /**< \brief C++11 extension chrono classes to track time spent in between frames -- last time_point */
chrono::time_point<chrono::system_clock> current;   /**< \brief C++11 extension chrono classes to track time spent in between frames -- current time_point */

const double turntableHeight = 0.5; /**< \brief base height of the Turntable -- used to translate the model so that it sits on zx-plane */
const double turntableRadius = 7.0; /**< \brief base radius of the Turntable */

double t = 0; /**< \brief time t in seconds */

float spin = 0.0;           /**< \brief the spin angle to control the rotation of turntable about the y-axis */
double aspect = 1.0;        /**< \brief aspect ratio (width:height) of the window */
bool pause = false;         /**< \brief flag to toggle turntable rotation on or off */
char axisSelection = '\0';  /**< \brief marks which axis is selected for camera movement */
char lightSelection = '\0'; /**< \brief marks which light is selected to be turned on or off */

double cam[3] = {18, 6, 18};    /**< \brief initial location of the camera */
Model *turntable;               /**< \brief pointer to the Turntable */
Model *model;                   /**< \brief pointer to the Model to be placed on the Turntable */
Light *light[3];                /**< \brief pointers to the Light (s) in the scene */
Model *anotherModel;
/**
\brief Draws a 2D grid on zx-plane.

Dimension of the grid drawn is 20 x 20.
*/
void drawGrid() {
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
        for (int i = -10; i <= +10; i++) {
            if (i % 2 == 0)
                glColor3f(0.5, 0.5, 0.5);
            else glColor3f(0.2, 0.2, 0.2);
            glVertex3f(-10.0, -0.0, i);
            glVertex3f(+10.0, -0.0, i);
        }
        for (int i = -10; i <= +10; i++) {
            if (i % 2 == 0)
                glColor3f(0.5, 0.5, 0.5);
            else glColor3f(0.2, 0.2, 0.2);
            glVertex3f(i, -0.0, -10.0);
            glVertex3f(i, -0.0, +10.0);
        }
        glEnd();
    glPopMatrix();
}

/**
\brief Spins the Turntable along with the Model on top of it about the y-axis.

This function does a full spin of 360 degrees within a set amount of time (declared as constant inside the function). After the
full spin it waits half the time it took and displays the model in wireframe mode. Then it repeats the process. The chrono
classes from C++11 are used to compute time elapsed between two spinMe() calls to determine the rotation speed.
*/
void spinMe() {
    const double fullSpinTime = 30; // should take 10 seconds to do a full circle around the model

    current = chrono::system_clock::now();
    chrono::duration<double> elapsed = current - last;
    t = t + elapsed.count();

    // idea is to do a full spin of 360 degrees in full spin time as solid object
    // then wait for half the time it took to do full spin as wireframe
    // then start all over again
    if (t >= 1.5 * fullSpinTime) {
        pause = false;
        model->setWireFrame(false);
        t = 0;
        spin = 0;
    } else if (t >= fullSpinTime) {
        pause = true;
        model->setWireFrame(true);
    }

    // need to spin another 360 - spin degrees
    // time left to do the spin 5 - t
    if (!pause)
        spin = spin + (360 - spin) / (fullSpinTime - t) * elapsed.count();
    glRotatef(spin, 0, 1, 0);
    last = current;
}

/**
\brief Initialization function to instantiate objects and to do related tasks.

Instantiates a Turntable, a Teapot for a model, two lights and sets backface culling on.
*/
void init() {
    last = chrono::system_clock::now();
    turntable = new Turntable(turntableRadius, turntableHeight);
    model = new Teapot(3.0);
    ObjModel* objmodel = new ObjModel();
    objmodel->readFile("FerrariFF2011v2");    // we want to read model.obj and model.mtl
    if (objmodel->isReady())
        model = (Model *) objmodel;
    ObjModel* newModel = new ObjModel();
    newModel->readFile("reverb");
    anotherModel = newModel;
    light[0] = new Light(GL_LIGHT0);
    light[1] = new Light(GL_LIGHT1);
    light[2] = new Light(GL_LIGHT2);
    float p[4] = {-10, 10, +10, 1.0}; light[0]->setPosition(p);
    float q[4] = {+10,  8, +10, 1.0}; light[1]->setPosition(q);
    float r[4] = { +0,  5, -10, 1.0}; light[2]->setPosition(r);
    glCullFace(GL_BACK);
}

/**
\brief The display() callback function.
*/
void display() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspect, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gluLookAt(cam[0], cam[1], cam[2], 0, 0, 0, 0, 1, 0);
    drawGrid();
    glPushMatrix();
        spinMe();
        model->render();
    glPopMatrix();
    /*glPushMatrix();
        glTranslatef(10, 0, 0);
        glScalef(2, 2, 2);
        anotherModel->render();
    glPopMatrix();*/

    glutSwapBuffers();
    glutPostRedisplay();
    glFinish();
}

/**
\brief The reshape() callback function.

This function is called for reshaphing whenever the window size is changed.
@param width is the new width of the window
@param height is the new height of the window
*/
void reshape(int width, int height) {
    aspect = ((float) width) / height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
\brief The keyboard() callback function.

@param ch is the character that's pressed.
@param x is the x-coordinate of the mouse when key is pressed
@param y is the y-coordinate of the mouse when key is pressed

ESC (character code 27) to Exit

'P' for pause/animate toggle

'X', 'Y' or 'Z' to select the axis on which the camera needs to be moved

'+' or '-' to move in the positive or negative direction on the axis selected

'0', '1' or '2' to select the light to turn on or off

'L' to toggle the selected light on or off

'F' to go full screen
*/
void keyboard(unsigned char ch, int x, int y) {
    switch (ch) {
        case 27:
            exit(0);
            break;
        case 'p': case 'P':
            pause = !pause;
            break;
        case 'x': case 'y': case 'z': case 'X': case 'Y': case 'Z':
            axisSelection = ch;
            lightSelection = '\0';
            break;
        case '0': case '1':
            lightSelection = ch;
            axisSelection = '\0';
            break;
        case 'l': case 'L':
            switch (lightSelection) {
                case '0':
                    light[0]->setOn(!light[0]->isOn());
                    break;
                case '1':
                    light[1]->setOn(!light[1]->isOn());
                    break;
                case '2':
                    light[1]->setOn(!light[1]->isOn());
                    break;
                default: break;
            }
            break;
        case 'f': case 'F':
            glutFullScreen();
            break;
        case '+':
            switch (axisSelection) {
                case 'x': cam[0] += 0.1; break;
                case 'y': cam[1] += 0.1; break;
                case 'z': cam[2] += 0.1; break;
            }
            break;
        case '-':
            switch (axisSelection) {
                case 'x': cam[0] -= 0.1; break;
                case 'y': cam[1] -= 0.1; break;
                case 'z': cam[2] -= 0.1; break;
            }
            break;
    }
}

/**
\brief The main function to start it all!

Initializes glut and registers the callback functions.

@param argc the number of parameters passed from command line
@param argv the command line parameters in one array
*/
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // something new here
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("Summer 2015 A2");
    pthread_getconcurrency(); // <-- junk code as workaround for weird linking error
    // reference: http://stackoverflow.com/questions/20007961/error-running-a-compiled-c-file-uses-opengl-error-inconsistency-detected
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
