#include <bits/stdc++.h>

class Singleton
{
    Singleton() {}
    static Singleton *singleton;
    std::string data;
    // For multithreading
    static std::mutex mu;

public:
    Singleton(const Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *get_instance()
    {
        // For multithreading
        std::lock_guard<std::mutex> lock(mu);
        if (singleton == nullptr)
        {
            singleton = new Singleton;
        }
        return singleton;
    }

    void set_data(std::string str)
    {
        data = str;
    }

    std::string get_data() const
    {
        return data;
    }
};

Singleton *Singleton::singleton = nullptr;
// For multithreading
std::mutex Singleton::mu;

int main()
{
    Singleton *s1 = Singleton::get_instance();
    s1->set_data("First Data");
    std::cout << s1->get_data() << "\n";
    Singleton *s2 = Singleton::get_instance();
    std::cout << s2->get_data() << "\n";
    s2->set_data("Second Data");
    std::cout << "S1: " << s1->get_data() << " - S2: " << s2->get_data() << "\n";

    return 0;
}