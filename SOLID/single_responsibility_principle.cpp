#include <bits/stdc++.h>

using namespace std;

struct Journal
{
    string title;
    vector<string> entries;
    Journal(const string &title) : title(title) {}
    void add_entry(const string &entry)
    {
        static int count = 1;

        entries.push_back(to_string(count++) + ": " + entry);
    }
    /*
    * Should not use this function this violate the SRP. 
    * 
    */
    void save(const string &filename)
    {
        ofstream ofs(filename);
        for (auto &e : entries)
            ofs << e << endl;
    }
};

struct PersistenceManager
{
    static void save(const Journal &j, const string &filename)
    {
        ofstream ofs(filename);
        for (auto &e : j.entries)
            ofs << e << endl;
    }
};

int main()
{
    Journal j("Dear Diary");
    j.add_entry("I ate a bug");
    j.add_entry("I cried today");

    //j.save("log.txt");

    PersistenceManager p;
    p.save(j, "log.txt");
    return 0;
}