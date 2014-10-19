/*************************************************************************
	> File Name: test.cpp
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年06月15日 星期日 15时06分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Window
{
public:
    Window()
    {
        cout<<"Window ctor."<<endl;
    }

    Window(const Window& rhs)
    {
        cout<<"In Window copy ctor."<<endl;
    }

    virtual void Display(void)
    {
        cout<<"In Window::Display()"<<endl;
    }
private:
};

class UnixWindow:public Window
{
public:
    UnixWindow()
    {
        cout<<"UnixWindow ctor."<<endl;
    }

    UnixWindow(const UnixWindow& rhs)
    {
        cout<<"UnixWindow copy ctor."<<endl;
    }

    virtual void Display(void)
    {
        cout<<"In UnixWindow::Display()"<<endl;
    }
};

void DisplayWindow(Window& w)
{
    w.Display();
}

int main()
{
    UnixWindow uw;
    DisplayWindow(uw);
    return 0;
}
