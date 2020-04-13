#include <bits/stdc++.h>

using std::string;
struct Shape
{
    virtual void draw() = 0;
};

struct Circle : Shape
{
    void draw() override
    {
        std::cout << "Circle";
    }
};
struct Square : Shape
{
    void draw() override
    {
        std::cout << "Square";
    }
};

struct GroupShapes : Shape
{
    string name;
    std::vector<Shape*> objects;
    GroupShapes(string name) : name(name) {}
    GroupShapes& add(Shape* shape)
    {
        objects.push_back(shape);
        return *this;
    }
    void draw() override
    {
        std::cout << "Group name: " << name << "\n";
        for (auto &elem : objects)
        {
            
            elem->draw();
            std::cout << " ";
        }
        std::cout << "\n";
    }

    GroupShapes *begin() { return this; }
    GroupShapes *end() { return this + 1; }
};
int main()
{
    Circle c1, c2;
    Square s1, s2;

    GroupShapes group1("Group 1");
    group1.add(&c1).add(&s2).draw();
    
    GroupShapes group2("Group 2");
    group2.add(&c2).add(&s1).add(&group1).draw();

    return 0;
}