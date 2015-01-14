#include "object_ref.h"
#include<iostream>
using namespace std;

class Test:public RefObject
{
public:
    Test()
    {
        std::cout<<"Test::Test"<<std::endl;
    }

    ~Test()
    {
    	std::cout<<"Test::~Test()."<<std::endl;
    }

    void print()
    {
    	std::cout<<"print()"<<std::endl;
    }
};

int main(int argc, char const *argv[])
{
    shared_ptr<Test> sp(new Test);
    shared_ptr<Test> sp1 = sp;
    std::cout<<"sp1.use_count"<<sp1.use_count()<<std::endl;
    sp1->print();
    
    return 0;
}


