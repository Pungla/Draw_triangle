#pragma once

#include <windows.h>

using namespace System;
using namespace System::Drawing;

public ref class Points
{
public:
    int x, y;
};

public ref class Triangle
{
public:
    Points^ p1;
    Points^ p2;
    Points^ p3;
    Color color;

    Triangle(Points^ point1, Points^ point2, Points^ point3, Color clr)
    {
        p1 = point1;
        p2 = point2;
        p3 = point3;
        color = clr;
    }
};
