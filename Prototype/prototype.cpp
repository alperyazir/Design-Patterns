
#include <bits/stdc++.h>
using std::cout;
using std::string;

enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2 = 1
};
class Prototype
{
protected:
    string prototype_name;
    float prototype_field;

public:
    Prototype() {}
    Prototype(string prototype_name) : prototype_name(prototype_name) {}
    virtual ~Prototype() {}
    virtual Prototype *Clone() const = 0;
    virtual void Method(float prototype_field)
    {
        this->prototype_field = prototype_field;
        cout << "Method from " << prototype_name << " with field :" << prototype_field << "\n";
    }
};

class ConcretePrototype1 : public Prototype
{
private:
    float concrete_prototype_field1;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field) : Prototype(prototype_name), concrete_prototype_field1(concrete_prototype_field) {}
    Prototype *Clone() const { return new ConcretePrototype1(*this); }
};

class ConcretePrototype2 : public Prototype
{
private:
    float concrete_prototype_field2;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field) : Prototype(prototype_name), concrete_prototype_field2(concrete_prototype_field) {}
    Prototype *Clone() const { return new ConcretePrototype2(*this); }
};

class PrototypeFactory
{
private:
    std::unordered_map<Type, Prototype *> prototypes;

public:
    PrototypeFactory()
    {
        prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1", 10.f);
        prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2", 20.f);
    }
    ~PrototypeFactory()
    {
        delete prototypes[Type::PROTOTYPE_1];
        delete prototypes[Type::PROTOTYPE_2];
    }
    Prototype *create_prototype(Type type)
    {
        return prototypes[type]->Clone();
    }
};

void Client(PrototypeFactory &pFactory)
{
    cout << "Lets Create Prototype1\n";
    Prototype * prototype = pFactory.create_prototype(Type::PROTOTYPE_1);
    prototype->Method(90);
    delete prototype;

    cout << "Lets Create Prototype2\n";
    prototype = pFactory.create_prototype(Type::PROTOTYPE_2);
    prototype->Method(66);
    delete prototype;

}

int main()
{
    PrototypeFactory pf;
    Client(pf);
    return 0;
}