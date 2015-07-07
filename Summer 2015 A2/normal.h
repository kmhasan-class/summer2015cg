#ifndef _NORMAL_H_
#define _NORMAL_H_

class Normal {
private:
    float i, j, k;

public:
    Normal();
    Normal(float i, float j, float k);
    void normalize();
    void useNormal();
};

#endif
