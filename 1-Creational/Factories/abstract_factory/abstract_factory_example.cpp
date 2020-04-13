#include <bits/stdc++.h>
using namespace std;

struct IButton
{
    virtual void paint() = 0;
};

struct WinButton : IButton
{
    void paint()
    {
        cout << "Win Button Painted" << endl;
    }
};

struct MacButton : IButton
{
    void paint()
    {
        cout << "Mac Button Painted" << endl;
    }
};

struct ICheckBox
{
    virtual void paint() = 0;
};

struct WinCheckBox : ICheckBox
{
    void paint()
    {
        cout << "Win CheckBox Painted" << endl;
    }
};

struct MacCheckBox : ICheckBox
{
    void paint()
    {
        cout << "Mac CheckBox Painted" << endl;
    }
};

struct IGUIFactory
{
    virtual IButton *create_button() = 0;
    virtual ICheckBox *create_checkBox() = 0;
};

struct WinFactory : IGUIFactory
{
    IButton *create_button()
    {
        return new WinButton();
    }
    ICheckBox *create_checkBox()
    {
        return new WinCheckBox();
    }
};

struct MacFactory : IGUIFactory
{
    IButton *create_button()
    {
        return new MacButton();
    }
    ICheckBox *create_checkBox()
    {
        return new MacCheckBox();
    }
};

struct Application
{
private:
    IGUIFactory *gui_factory;
    IButton *button;
    ICheckBox *check_box;

public:
    Application(IGUIFactory *gui_factory) : gui_factory(gui_factory) {}
    void create_ui()
    {
        button = gui_factory->create_button();
        check_box = gui_factory->create_checkBox();
    }
    void paint()
    {
        button->paint();
        check_box->paint();
    }
};

int main()
{
    string config = "win";
    // string config = "mac";
    IGUIFactory *gui_fac;
    if (config == "win")
        gui_fac = new WinFactory();
    else if (config == "mac")
        gui_fac = new MacFactory();

    Application *app = new Application(gui_fac);
    app->create_ui();
    app->paint();

    return 0;
}