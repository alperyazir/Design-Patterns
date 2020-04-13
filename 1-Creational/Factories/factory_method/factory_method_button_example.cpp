#include <bits/stdc++.h>
using namespace std;

struct IButton
{
    virtual void on_click(string) = 0;
    virtual void render() = 0;
    virtual ~IButton() {}
};

struct WindowsButton : IButton
{
    void on_click(string str)
    {
        cout << "Windows Button is Clicked " << str << endl;
    }
    void render()
    {
        cout << "Windows Button is renderind" << endl;
    }
};

struct LinuxButton : IButton
{
    void on_click(string str)
    {
        cout << "Linux Button is Clicked " << str << endl;
    }
    void render()
    {
        cout << "Linux Button is renderind" << endl;
    }
};

struct Dialog
{
private:
    virtual IButton *create_button() = 0;

public:
    void some_operation()
    {
        IButton *button = create_button();
        button->on_click("Hello World!");
        button->render();
    }
};

struct WindowsDialog : Dialog
{
private:
    IButton *create_button()
    {
        return new WindowsButton;
    }
};
struct LinuxDialog : Dialog
{
private:
    IButton *create_button()
    {
        return new LinuxButton;
    }
};

int main()
{
    //string config = "windows";
    string config = "linux";

    Dialog *d;
    if (config == "windows")
        d = new WindowsDialog;
    else if (config == "linux")
        d = new LinuxDialog;
    d->some_operation();
    return 0;
}
