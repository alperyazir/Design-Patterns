/*
* Functions that use pointers or references to base classes must be able to use objects of derived classes without knowing it.
*/
#include <bits/stdc++.h>

using namespace std;

struct Bird
{
public:
    virtual void setLocation(double longitude, double latitude) = 0;
    virtual void setAltitude(double altitude) = 0;
    virtual void draw() = 0;
};

struct Pigeon : Bird
{
    double longitude;
    double latitude;
    double altitude;
    void setLocation(double longitude, double latitude)
    {
        longitude = longitude;
        latitude = latitude;
    }
    void setAltitude(double altitude)
    {
        altitude = altitude;
    }
    void draw()
    {
        // Draws anything
    }
};

struct Penguin : Bird
{
    double longitude;
    double latitude;
    void setLocation(double longitude, double latitude)
    {
        longitude = longitude;
        latitude = latitude;
    }
    void setAltitude(double altitude)
    {
        // Penguins can't fly
        // This function does nothing
        // Violate the LSP
    }
    void draw()
    {
        // Draws anything
    }
};

// Solution
/* by this way we can split up birds, who can fly or who can't
struct Bird
{
    virtual void draw() = 0;
    virtual void setLocation(double longitude, double latitude) = 0;
};

struct FlightfulBird : Bird
{

    virtual void setAltitude(double altitude) = 0;
};
*/

int main()
{

    return 0;
}