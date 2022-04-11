#ifndef MOTOROLA_FENCE_H
#define MOTOROLA_FENCE_H

#include <iostream>
#include <vector>

using namespace std;

class Fence{
    vector<int> bestB; //vector collecting "b" values that give us maximized farm area

public:

    int maxSize = 0; //maximum farm are
    int length; //length of fence we can use

    Fence();

    void calc();

    void info();

};


#endif //MOTOROLA_FENCE_H
