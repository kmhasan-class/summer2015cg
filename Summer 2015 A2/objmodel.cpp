#include "objmodel.h"

#include <GL/glut.h>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

ObjModel::ObjModel() : MeshModel() {
    ready = false;
}

ObjModel::~ObjModel() {
    // You got to do something here. There will be plenty of data to store for a mesh model. When you're done with this
    // model, those need to be freed up.
}

void ObjModel::render() {
    // Render your model!
    if (!ready)
        return;
    Model::render();
    int n = o.size();
    //cout << "Rendering " << n << " objects" << endl;
    for (int i = 0; i < n; i++)
        o[i].render();
}

void ObjModel::readObj(char *basename) {
    // Read the data files and store what needs to be stored!

	// next 3 lines creates the filename by adding ".obj" at the end of basename
	char *filename = new char[strlen(basename) + 5];
	strcpy(filename, basename);
	strcat(filename, ".obj");

	ifstream in(filename);	// handle to read the file
	string line;			// string to hold one line of input

	cout << "Started reading " << filename << endl;

	Vertex vertex;
    Object object;
    Face face;
    istringstream iss;
    Material *currentMaterial = NULL;

    char ch;
    int n;
    string name;

	while (getline(in, line)) {		// keep reading one line at a time till we reach EOF
		switch (line[0]) {
			case '#':
				// ignore comment lines
				break;
			case 'o':
				// at first instantiate a new object
				name = line.substr(2);
				if (!object.isNull())
                    o.push_back(object);
				object = Object(name, this);
				break;
			case 'v':
				// reading a vertex information
				iss.clear();
				iss.str(line);
				float x, y, z;

				iss >> ch >> x >> y >> z;	// think of string stream as reading from keyboard or a file
				vertex = Vertex(x, y, z);			// create an object of our custom Vertex class
				v.push_back(vertex);				// insert that vertex at the end of the vector
				break;
			case 'f':
                iss.clear();
                iss.str(line);
                iss >> ch;
                face = Face(currentMaterial);
                while (iss >> n)
                    face.addVid(n);
                face.computeNormal(&v);
                object.addFace(face);
                break;
            case 'u':
            // usemtl command
                iss.clear();
                iss.str(line);
                iss >> name; iss >> name;
                for (int i = 0; i < m.size(); i++)
                    if (m[i].getName() == name)
                        currentMaterial = &m[i];
                break;
		}
	}
	o.push_back(object);

	cout << "Done reading " << filename << endl;
	cout << "Read " << v.size() << " vertices" << endl;		// use the size() function to know the total number of elements in a vector
	cout << "First vertex: " << v[0].getX() << ", " << v[0].getY() << ", " << v[0].getZ() << endl;					// use array like subscripts [] to access particular indices
    cout << "Read " << o.size() << " objects" << endl;
    for (int i = 0; i < o.size(); i++)
        o[i].print();
}

void ObjModel::readMtl(char *basename) {
    // Read the data files and store what needs to be stored!

	// next 3 lines creates the filename by adding ".obj" at the end of basename
	char *filename = new char[strlen(basename) + 5];
	strcpy(filename, basename);
	strcat(filename, ".mtl");

	ifstream in(filename);	// handle to read the file
	string line;			// string to hold one line of input

	cout << "Started reading " << filename << endl;

    Material material;
    istringstream iss;

    float color[3], shininess[1];
    string name;

	while (getline(in, line)) {		// keep reading one line at a time till we reach EOF
        string start = line.substr(0, 2);
        if (start == "ne") {
            if (!material.isNull())
                m.push_back(material);
            material = line.substr(7);
        } else if (start == "Ka") {
            iss.clear();
            iss.str(line);
            iss >> start >> color[0] >> color[1] >> color[2];
            material.setAmbient(color);
        } else if (start == "Kd") {
            iss.clear();
            iss.str(line);
            iss >> start >> color[0] >> color[1] >> color[2];
            material.setDiffuse(color);
        } else if (start == "Ks") {
            iss.clear();
            iss.str(line);
            iss >> start >> color[0] >> color[1] >> color[2];
            material.setSpecular(color);
        } else if (start == "Ns") {
            iss.clear();
            iss.str(line);
            iss >> start >> shininess[0];
            material.setShininess(shininess);
        }
    }
    if (!material.isNull())
        m.push_back(material);
}

void ObjModel::readFile(char* basename) {
    // After we're done reading, we're ready to render
    // When you're done, you should uncomment the following line
    readMtl(basename);
    readObj(basename);
    ready = true;
}

bool ObjModel::isReady() {
    return ready;
}

vector<Vertex>* ObjModel::getVertices() {
    return &v;
}
