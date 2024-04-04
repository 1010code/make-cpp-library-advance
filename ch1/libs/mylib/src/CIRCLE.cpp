#include <stdio.h>
#include "CIRCLE.h"

CIRCLE::CIRCLE()
{
    printf("create and init default radius 5.\n");
    _radius = 5;
}
CIRCLE::CIRCLE(double radius)
{
    _radius = radius;
}

void CIRCLE::GetArea()
{
    double area = _radius * _radius * 3.14;
    Display(area);
}
void CIRCLE::SetRadius(double radius)
{
    _radius = radius;
}

void CIRCLE::Display(double area)
{
    printf("Area of a circle: %lf\n", area);
}