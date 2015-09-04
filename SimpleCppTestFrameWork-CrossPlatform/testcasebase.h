#ifndef TEST_CASE_BASE_H__
#define TEST_CASE_BASE_H__
#include <iostream>
#include <string>
#include "noncopyable.h"

typedef void (*SetupTestCaseFunc)();
typedef void (*TearDownTestCaseFunc)();

class TestCaseBase : NonCopyable  
{
public:
    TestCaseBase(){}

    ~TestCaseBase(){}

    std::string GetTestCaseName() const {return std::string(m_TestcaseName);} 

    static void SetupTestCase(){}

    static void TearDownTestCase(){}

    virtual void TestBody() = 0;

private:
    std::string m_TestcaseName;

};

struct TestInfo : NonCopyable
{
public:
    std::string m_sTestCaseName;
    std::string m_sTestName;
    TestCaseBase* m_pTestCaseInstance;
	SetupTestCaseFunc m_func_set_up;
	TearDownTestCaseFunc m_func_tear_down;
	TestInfo(const char* test_case_name, const char* test_name, SetupTestCaseFunc set_up_func, \
			TearDownTestCaseFunc tear_down_func, TestCaseBase* pTestCase)
               : m_sTestCaseName(test_case_name)
               , m_sTestName(test_name)
			   , m_func_set_up(set_up_func)
			   , m_func_tear_down(tear_down_func)
               , m_pTestCaseInstance(pTestCase)
    {

    }
};
#endif