/*
Clients should not be forced to depend upon interfaces that they do not use.
*/
#include <bits/stdc++.h>

using namespace std;

/* This vialote the Interface segregation principle(ISP)
* We must split the interfaces
*/
/*
struct IAnimal
{
    virtual void fly() = 0;
    virtual void bark() = 0;
    virtual void swim() = 0;
};

struct Dog : IAnimal
{
    void fly() override
    {
        // Do nothing
    }
    void bark() override
    {
        cout << "Barking\n";
    }
    void swim() override
    {
        // Do nothing
    }
};
*/

struct IFlyable
{
    virtual void fly() = 0;
};
struct IBarkable
{
    virtual void bark() = 0;
};
struct ISwimable
{
    virtual void swim() = 0;
};
struct IRunable
{
    virtual void run() = 0;
};

struct Dog : IBarkable, IRunable
{
    void bark() override
    {
        cout << "Barking\n";
    }
    void run() override
    {
        cout << "Running\n";
    }
};

int main()
{
    

    return 0;
}