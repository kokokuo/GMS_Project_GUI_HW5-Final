#ifndef LINE_H
#define LINE_H

#include <string>
#include <vector>
#include "component.h"
using namespace std;

class Line : public Component
{
public:
    Line(int id, string componentType, string name);
    bool CheckBePressed(float x,float y);
};

#endif // LINE_H
