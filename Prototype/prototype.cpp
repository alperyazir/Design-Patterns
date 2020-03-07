/**
 * Prototype is a creational design pattern that lets you copy existing objects without making your code dependent on their classes.
 */
#include <bits/stdc++.h>
using namespace std;

enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype
{
protected:
    string prototype_name_;
    float prototype_field_;

public:
    Prototype() {}
    Prototype(string prototype_name)
        : prototype_name_(prototype_name)
    {
    }
    virtual ~Prototype() {}
    virtual Prototype *Clone() const = 0;
    virtual void Method(float prototype_field)
    {
        this->prototype_field_ = prototype_field;
        cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << endl;
    }
};

class ConcretePrototype1 : public Prototype
{
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field)
    {
    }

    /**
   * Notice that Clone method return a Pointer to a new ConcretePrototype1
   * replica. so, the client (who call the clone method) has the responsability
   * to free that memory. I you have smart pointer knowledge you may prefer to
   * use unique_pointer here.
   */
    Prototype *Clone() const override
    {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype
{
private:
    float concrete_prototype_field2_;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field)
    {
    }
    Prototype *Clone() const override
    {
        return new ConcretePrototype2(*this);
    }
};

class PrototypeFactory
{
private:
    unordered_map<Type, Prototype *, hash<int>> prototypes_;

public:
    PrototypeFactory()
    {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
    }

    /**
   * Be carefull of free all memory allocated. Again, if you have smart pointers
   * knowelege will be better to use it here.
   */

    ~PrototypeFactory()
    {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    /**
   * Notice here that you just need to specify the type of the prototype you
   * want and the method will create from the object with this type.
   */
    Prototype *CreatePrototype(Type type)
    {
        return prototypes_[type]->Clone();
    }
};

void Client(PrototypeFactory &prototype_factory)
{
    cout << "Let's create a Prototype 1\n";

    Prototype *prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->Method(90);
    delete prototype;

    cout << "\n";

    cout << "Let's create a Prototype 2 \n";

    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->Method(10);

    delete prototype;
}

int main()
{
    PrototypeFactory *prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}