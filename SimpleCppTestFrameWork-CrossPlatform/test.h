#ifndef TEST_H__
#define TEST_H__


#include "testcasebase.h"
#include "unit_test.h"
#include <iostream>

#define TEST_CASE_NAME(test_case_name, test_name) test_case_name##test_name##TEST
#define TEST_(test_case_name, test_name, parent_class) \
class TEST_CASE_NAME(test_case_name, test_name): public parent_class , private NonCopyable  \
{      \
public:  \
	TEST_CASE_NAME(test_case_name, test_name) () {}\
    virtual void TestBody();\
private:          \
    static TestInfo*  m_pTestInfo;    \
};    \
TestInfo* TEST_CASE_NAME(test_case_name, test_name)::m_pTestInfo = \
    UnitTest::GetInstance()->MakeAndRegisterTestCase\
    (#test_case_name, #test_name, parent_class::SetupTestCase, parent_class::TearDownTestCase, \
    new TEST_CASE_NAME(test_case_name, test_name)() );\
void TEST_CASE_NAME(test_case_name, test_name)::TestBody() 
#define TEST(test_case_name, test_name) TEST_(test_case_name, test_name, TestCaseBase)
#define TEST_F(test_fixture, test_name) TEST_(test_fixture, test_name, test_fixture)
#define EXPECT_EQ(expected, actual) \
{ \
    if (expected != actual)\
    {      \
        std::cout << "Failed" << std::endl; \
        std::cout << "Expect:" << expected << std::endl; \
        std::cout << "Actual:" << actual << std::endl; \
    }   \
	else\
	{\
		std::cout << "Success..." << std::endl;\
	}\
}
#endif
