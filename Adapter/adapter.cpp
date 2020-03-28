#include <bits/stdc++.h>

using std::cout;
using std::string;

struct Target
{
    virtual ~Target() = default;
    virtual string Request() const
    {
        return "Target: The default target's behavior.";
    }
};

struct Adaptee
{
    string SpecificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// Adapter 1: with composition
struct Adapter : Target
{
    Adapter(Adaptee *adaptee) : adaptee(adaptee) {}
    string Request() const override
    {
        string to_reverse = adaptee->SpecificRequest();
        std::reverse(begin(to_reverse), end(to_reverse));
        return "Adapter: (TRANSLATED) " + to_reverse;
    }

private:
    Adaptee *adaptee;
};
// Adapter 2: with multiple inhertiance
// class Adapter : public Target, public Adaptee
// {
// public:
//     Adapter() {}
//     std::string Request() const override
//     {
//         std::string to_reverse = SpecificRequest();
//         std::reverse(to_reverse.begin(), to_reverse.end());
//         return "Adapter: (TRANSLATED) " + to_reverse;
//     }
// };

void ClientCode(const Target *target)
{
    cout << target->Request();
}

int main()
{
    cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target;
    ClientCode(target);
    cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    cout << "Adaptee: " << adaptee->SpecificRequest();
    cout << "\n\n";
    cout << "Client: But I can work with it via the Adapter:\n";
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);
    cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}