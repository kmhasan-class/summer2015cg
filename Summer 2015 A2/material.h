#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include <string>
using namespace std;

class Material {
private:
    string name;
    float ka[3];
    float kd[3];
    float ks[3];
    float shininess[1];

public:
    Material();
    Material(string name);
    void setAmbient(float ka[3]);
    void setDiffuse(float kd[3]);
    void setSpecular(float ks[3]);
    void setShininess(float shininess[1]);
    void useMaterial();
    bool isNull();
    string getName();
};

#endif
