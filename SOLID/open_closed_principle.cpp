#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
#define _USE_MATH_DEFINES // for pi number

struct Shape
{
    virtual double area() = 0;
};

struct Rectangle : Shape
{
    double width;
    double height;
    Rectangle(double width, double height) : width(width), height(height) {}
    double area() override { return width * height; }
};
struct Circle : Shape
{
    double radius;
    Circle(double radius) : radius(radius) {}
    double area() override { return radius * radius * M_PI; }
};

struct AreaCalculator
{
    static double area(Shape *shape) { return shape->area(); }
};
int main()
{
    Rectangle r(10, 20);
    Circle c(5);
    cout << AreaCalculator::area(&r) << "\n";
    cout << AreaCalculator::area(&c) << "\n";
    return 0;
}