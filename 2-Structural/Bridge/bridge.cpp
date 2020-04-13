#include <bits/stdc++.h>
#define _USE_MATH_DEFINES

using std::string;
struct IColor
{
protected:
    string color;
    IColor(string color) : color(color) {}

public:
    virtual string print() = 0;
};

struct Red : IColor
{
    Red(string color) : IColor(color) {}
    virtual string print() override
    {
        return "Red";
    }
};
struct Green : IColor
{
    Green(string color) : IColor(color) {}
    virtual string print() override
    {
        return "Green";
    }
};

struct Shape
{
protected:
    IColor &color;
    string name;
    Shape(string name, IColor &color) : name(name), color(color) {}

public:
    virtual void area() = 0;
};

struct Square : Shape
{
private:
    int x;

public:
    Square(string name, int x, IColor &color) : Shape(name, color), x(x) {}
    void area() override
    {
        std::cout << name << " area: " << x * x << " with the color: " << color.print() << "\n";
    }
};

struct Circle : Shape
{
private:
    int radius;

public:
    Circle(string name, int radius, IColor &color) : Shape(name, color), radius(radius) {}
    void area() override
    {
        std::cout << name << " area: " << M_PI * radius * radius << " with the color: " << color.print() << "\n";
    }
};

int main()
{
    Red r("red");
    Green g("green");
    IColor &col = r;
    Circle c("circle", 5, col);
    c.area();
    IColor &col1 = g;
    Square s("Square", 15, col1);
    s.area();
}