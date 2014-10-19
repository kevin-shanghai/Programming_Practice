/*  
 * File:   main.cpp 
 * Author: Vicky.H 
 * 
 */  
#include <iostream>  
  
class myexception : public std::exception {  
public:  
  
    const char* what() const throw () {  
        std::cout << "my exception" << std::endl;  
    }  
};  
  
void f1(bool flag = true) {  
    if (flag) throw myexception();  
}  
  
void f2(bool flag = true) throw () {  
    if (flag) throw myexception();  
}  
  
/* 
 *  
 */  
int main(void) {  
  
    try 
    {  
        f1();  
    } 
    catch (...) 
    {  
    }  
    std::cout << "f1()抛出的异常将会被捕获,程序不会中断,将继续执行" << std::endl;  
      
    try 
    {  
        f2();  
    } 
    catch (...) 
    {  
    }  
    std::cout << "f2()抛出的异常不会被捕获,程序会中断,将不会执行该条语句" << std::endl;  
  
    return 0;  
}  