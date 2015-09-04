// CppTestFramework.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdlib.h>
#include "unit_test.h"
#include "test.h"
#include "testcasebase.h"


class Calculator
{
public:
    Calculator(int a, int b)
    {
        m_a = a;
        m_b = b;
    }

	~Calculator()
	{
	}

     int add(int a, int b)
     {
         return a+b;
     }

     int sub(int a, int b)
     {
         return a-b;
     }

private:
    int m_a;
    int m_b;
};                  

class CalculatorUT :public TestCaseBase
{
public:
    CalculatorUT()
    {
        std::cout << "CalculatorUT::CalculatorUT()" << std::endl;
    }


	static void SetupTestCase()
	{
		std::cout << "CalculatorUT::SetupTestCase()" << std::endl;
		m_pCalculator = new Calculator(0, 0);
	}

	static void TearDownTestCase()
	{
		std::cout << "CaculatorUT::TearDownTestCase()" << std::endl;
		delete m_pCalculator;
		m_pCalculator = NULL;
	}
    
public:
    static Calculator* m_pCalculator;
};

Calculator* CalculatorUT::m_pCalculator = NULL;


TEST_F(CalculatorUT, ADD)
{
    EXPECT_EQ(5, CalculatorUT::m_pCalculator->add(1, 2));
}

/*

TEST_F(CalculatorUT, ADD1)
{
    EXPECT_EQ(4, CalculatorUT::m_pCalculator->add(1, 2));
}

TEST(CalculatorUT, Hello)
{
	EXPECT_EQ(4, CalculatorUT::m_pCalculator->add(1, 2));
}
*/
int main(int argc, char* argv[])
{
    std::cout << "Hello world..." << std::endl;
    UnitTest::GetInstance()->RunningAllTestCases();
    //system("pause");
	return 0;
}

