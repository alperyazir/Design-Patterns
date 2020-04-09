#include <iostream>

struct ISubject
{
    virtual void request() = 0;
};

struct RealSubject: ISubject {
    void request() override {
        std::cout << "I am handling the real Subject\n";
    }
};
class Proxy : public ISubject {

private:
    RealSubject *real_subject_;

    bool CheckAccess() const {
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }
    void LogAccess() const {
        std::cout << "Proxy: Logging the time of request.\n";
    }

public:
    Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {
    }

    ~Proxy() {
        delete real_subject_;
    }

    void request()  override {
        if (this->CheckAccess()) {
            this->real_subject_->request();
            this->LogAccess();
        }
    }
};

void ClientCode(ISubject &subject) {
    subject.request();
}

int main()
{

    std::cout << "Client: Executing the client code with a real subject:\n";
    RealSubject *real_subject = new RealSubject;
    ClientCode(*real_subject);
    std::cout << "\n";
    std::cout << "Client: Executing the same client code with a proxy:\n";
    Proxy *proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;

    return 0;
}
