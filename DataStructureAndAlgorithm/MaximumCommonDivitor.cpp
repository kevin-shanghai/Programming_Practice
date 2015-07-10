/*************************************************************************
	> File Name: MaximumCommonDivitor.cpp
	> Author: Kevin1985
	> Mail: fuliangcheng1985@126.com 
	> Created Time: Fri 10 Jul 2015 10:50:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int getMaximumCommonDivitor(int a, int b)
{
    while (b!=0)
    {
        int mod = a%b;
        a = b;
        b = mod;
    }
    return a;
}


int getMaximumCommonDivitorRecurtion(int a, int b)
{
    if (a%b == 0) return b;
    return getMaximumCommonDivitorRecurtion(b , a%b);
}

int main()
{
    std::cout << "getMaximumCommonDivitor(16, 6) is:" 
              << getMaximumCommonDivitor(16, 6) 
              << std::endl;

    std::cout << "getMaximumCommonDivitorRecurtion(32, 16) is:" 
              << getMaximumCommonDivitor(32,16) 
              << std::endl;

}
