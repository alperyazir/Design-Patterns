#include <bits/stdc++.h>
#define _USE_MATH_DEFINES

using std::cout;
using std::string;

enum Type
{
	Rect,
	Circ
};

// Abstract Class for shape
struct ShapePrototype
{
	ShapePrototype() {}
	ShapePrototype(int x, int y, string color)
		: x(x), y(y), color(color) {
	}
	std::unique_ptr<ShapePrototype> Clone() const
	{
		return std::unique_ptr<ShapePrototype>(this->clone_imp());
	}
	virtual void area() = 0;
    virtual ~ShapePrototype(){}
private:
	virtual ShapePrototype* clone_imp() const = 0;
protected:
	int x;
	int y;
	string color;
};

struct Rectangle : ShapePrototype
{
	Rectangle(int x, int y, string color, int width, int height)
		: ShapePrototype(x, y, color), m_width(width), m_height(height) {}

	Rectangle(const Rectangle& rec)
		: ShapePrototype(rec), m_width(rec.m_width), m_height(rec.m_height) {}

	std::unique_ptr<ShapePrototype> Clone() const
	{
		return std::unique_ptr<Rectangle>(this->clone_imp());
	}
	void area() override
	{
		cout << "I am a triangle with area: " << m_width * m_height << "\n";
	}
	~Rectangle(){}

private:
	int m_width;
    int m_height;

	virtual Rectangle* clone_imp() const override
	{
		return new Rectangle(*this);
	}
};

struct Circle : ShapePrototype
{
	Circle(int x, int y, string color, int radius)
		: ShapePrototype(x, y, color), radius(radius) {}
	Circle(const Circle& circle)
		: ShapePrototype(circle), radius(circle.radius) {}
	std::unique_ptr<ShapePrototype> Clone() const
	{
		return std::unique_ptr<ShapePrototype>(this->clone_imp());
	}
	~Circle(){}
	void area() override
	{
		cout << "I am a circle with area: " << M_PI * pow(radius, 2) << "\n";
	}

private:
	int radius;

	virtual Circle* clone_imp() const override
	{
		return new Circle(*this);
	}
};

class ShapeFactory
{
	std::unordered_map<Type, std::unique_ptr<ShapePrototype>> prototypes;

public:
	ShapeFactory()
	{
		prototypes[Type::Rect] = std::make_unique<Rectangle>(100, 100, "black", 30, 60);
		prototypes[Type::Circ] = std::make_unique<Circle>(50, 50, "yellow", 10);
	}
	~ShapeFactory()	{}

	std::unique_ptr<ShapePrototype> produce_shape(Type type)
	{
		return prototypes[type]->Clone();
	}
};

int main()
{
    ShapeFactory sf;
	auto prototoype = sf.produce_shape(Type::Rect);
	prototoype->area();
	prototoype = sf.produce_shape(Type::Circ);
	prototoype->area();
	return 0;
}