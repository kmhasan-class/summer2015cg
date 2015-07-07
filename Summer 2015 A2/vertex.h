#ifndef _VERTEX_H_
#define _VERTEX_H_

class Vertex {
private:
    float x, y, z;

public:
    Vertex();
    Vertex(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
};

#endif
