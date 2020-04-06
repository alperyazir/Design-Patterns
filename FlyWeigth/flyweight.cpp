#include <bits/stdc++.h>

class Piece
{
public:
    Piece(std::string color, int speed, bool reversible) : color(color), speed(speed), reversible(reversible) {}
    virtual void print() = 0;

protected:
    std::string color;
    int speed;
    bool reversible;
};

class I : public Piece
{
    std::string label;

public:
    void print() override
    {
        std::cout << "label: " << label
                  << " color: " << color
                  << " speed: " << speed
                  << " reverible: " << reversible << "\n";
    }
    I(std::string color, int speed, bool reversible) : label("I"), Piece(color, speed, reversible) {}
};

class T : public Piece
{
    std::string label;

public:
    void print() override
    {
        std::cout << "label: " << label
                  << " color: " << color
                  << " speed: " << speed
                  << " reverible: " << reversible << "\n";
    }
    T(std::string color, int speed, bool reversible) : label("T"), Piece(color, speed, reversible) {}
};

class J : public Piece
{
    std::string label;

public:
    void print() override
    {
        std::cout << "label: " << label
                  << " color: " << color
                  << " speed: " << speed
                  << " reverible: " << reversible << "\n";
    }
    J(std::string color, int speed, bool reversible) : label("J"), Piece(color, speed, reversible) {}
};

class PieceFactory
{
    static std::map<std::string, Piece *> piece_map;

public:
    static Piece *get_piece(std::string type)
    {
        auto iter = piece_map.find(type);

        if (iter == end(piece_map))
        {
            if (type == "I")
                piece_map.insert({type, new I("Red", 66, true)});
            else if (type == "T")
                piece_map.insert({type, new T("Blue", 67, false)});
            else if (type == "J")
                piece_map.insert({type, new J("Green", 68, true)});
            return piece_map[type];
        }
        else
        {
            return piece_map[type];
        }
    }
};
std::map<std::string, Piece *> PieceFactory::piece_map;

int main()
{
    std::vector<Piece*> mvec{
        PieceFactory::get_piece("I"),
        PieceFactory::get_piece("J"),
        PieceFactory::get_piece("I"),
        PieceFactory::get_piece("T"),
        PieceFactory::get_piece("J")};

    for (const auto &p : mvec)
    {
        p->print();
    }


}