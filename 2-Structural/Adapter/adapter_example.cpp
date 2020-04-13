#include <bits/stdc++.h>

using std::cout;
using std::string;

// My Application with interface IError
struct IError
{
protected:
    int error_id;
    string error_description;

public:
    virtual void print() const = 0;
};

struct DBError : IError
{
    DBError(int e_id, string e_dest)
    {
        error_id = e_id;
        error_description = e_dest;
    }
    void print() const override
    {
        cout << "DB Error with error id: " << error_id << "\nDescription: " << error_description << "\n";
    }
};

struct ServiceError : IError
{
    ServiceError(int e_id, string e_dest)
    {
        error_id = e_id;
        error_description = e_dest;
    }

    void print() const override
    {
        cout << "Service Error with error id: " << error_id << "\nDescription: " << error_description << "\n";
    }
};

// Adaptee
struct Fax
{
    int fax_error_id;
    string fax_error_description;
    Fax(int f_eid, string f_edest)
        : fax_error_id(f_eid), fax_error_description(f_edest) {}
};
// Adapter Class for adapting the Fax to our system with composition
struct FaxAdapter : IError
{
    FaxAdapter(Fax *fax) : fax(fax) {}
    void print() const override
    {
        cout << "Service Error with error id: " << fax->fax_error_id << "\nDescription: " << fax->fax_error_description << "\n";
    }

private:
    Fax *fax;
};

int main()
{
    Fax *fax = new Fax(3000, "Connection Problem with other fax");
    std::vector<std::unique_ptr<IError>> errors;
    errors.push_back(std::make_unique<DBError>(1000, "DB error occured with queries\n"));
    errors.push_back(std::make_unique<ServiceError>(2000, "Service Authentication problem!\n"));
    errors.push_back(std::make_unique<FaxAdapter>(fax));
    for (const auto &e : errors)
        e->print();

    delete fax;
}