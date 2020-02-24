/*
    Separate the construction of a complex object from its representation so that the same construction process can create different representations
    1) Director - This object is responsible for target object creation using builder object
    2) Builder  - This object is responsible for target object creation .
    3) Product  - This is the target object.
*/
#include <bits/stdc++.h>
using namespace std;

// This is target object Product
struct Pizza
{
    void set_dought(const string &dought) { m_dough = dought; }
    void set_sauce(const string &sauce) { m_sauce = sauce; }
    void set_topping(const string &topping) { m_topping = topping; }
    void open() const
    {
        cout << "The Pizza have " << m_dough << " dough, " << m_sauce << " sauce, " << m_topping << " topping." << endl;
    }

private:
    string m_dough;
    string m_sauce;
    string m_topping;
};

// This Abstract Builder class
struct PizzaBuilder
{
    virtual ~PizzaBuilder(){};
    virtual void build_dought() = 0;
    virtual void build_sauce() = 0;
    virtual void build_topping() = 0;

    void create_new_pizza()
    {
        m_pizza = make_unique<Pizza>();
    }
    Pizza *get_pizza()
    {
        return m_pizza.release();
    }

protected:
    unique_ptr<Pizza> m_pizza;
};

struct HawaiiPizzaBuilder : public PizzaBuilder
{
    virtual ~HawaiiPizzaBuilder(){};
    virtual void build_dought() override
    {
        m_pizza->set_dought("Hawaiian");
    }
    virtual void build_sauce() override
    {
        m_pizza->set_sauce("Hawaiian");
    }
    virtual void build_topping() override
    {
        m_pizza->set_topping("Hawaiian");
    }
};

struct YozgatPizzaBuilder : public PizzaBuilder
{
    virtual ~YozgatPizzaBuilder(){};
    virtual void build_dought() override
    {
        m_pizza->set_dought("Yozgat");
    }
    virtual void build_sauce() override
    {
        m_pizza->set_sauce("Yozgat");
    }
    virtual void build_topping() override
    {
        m_pizza->set_topping("Yozgat");
    }
};
// Director
struct Cook
{
    void open_pizza() const
    {
        m_pBuilder->get_pizza()->open();
    }
    Cook &create_pizza(PizzaBuilder *pizzaBuilder)
    {
        m_pBuilder = pizzaBuilder;
        m_pBuilder->create_new_pizza();
        m_pBuilder->build_dought();
        m_pBuilder->build_sauce();
        m_pBuilder->build_topping();
        return *this;
    }

private:
    PizzaBuilder *m_pBuilder;
};

int main()
{
    Cook cook;
    cook.create_pizza(new HawaiiPizzaBuilder).open_pizza();
    cook.create_pizza(new YozgatPizzaBuilder).open_pizza();
}