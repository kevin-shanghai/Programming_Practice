#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <assert.h>
#include "testcasebase.h"
#include "noncopyable.h"

class UnitTest :NonCopyable
{
public:
    TestInfo* MakeAndRegisterTestCase(const char* test_case_name, 
                                          const char* test_name, 
                                          SetupTestCaseFunc set_up_tc,
                                          TearDownTestCaseFunc tear_down_tc,
                                          TestCaseBase* pTestCase
                                          ) 

    {
        assert (pTestCase != NULL && test_case_name != NULL && test_name != NULL);
        TestInfo* test_info = new TestInfo(test_case_name, test_name, set_up_tc, tear_down_tc, pTestCase);
    m_TestInfoList.push_back(test_info);
    m_setAllTestCases.insert(test_case_name);
        return test_info;
    }

    void RunningAllTestCases() const
    {
    int test_case_num = m_setAllTestCases.size();
    int test_num = m_TestInfoList.size();
    std::cout << "-------Running " << test_num << " tests from " << test_case_num << " test cases...." << std::endl;
    
    std::vector<TestInfo*>::const_iterator test_info_it;

    for (test_info_it = m_TestInfoList.begin(); test_info_it != m_TestInfoList.end(); test_info_it++)
    {
      (*test_info_it)->m_func_set_up();
      (*test_info_it)->m_pTestCaseInstance->TestBody();
      (*test_info_it)->m_func_tear_down();
    } 
    }

    static UnitTest* GetInstance() 
    {
        static UnitTest uniteTestInstance;
        return &uniteTestInstance; 
    }

protected:
    virtual void SetUp(){}
    virtual void TearDown(){}

private:
    UnitTest(){}
    std::map<std::string, TestCaseBase*> m_mapCaseName2TestCase;
    std::vector<TestInfo*> m_TestInfoList;
  std::set<std::string> m_setAllTestCases;
  
};

