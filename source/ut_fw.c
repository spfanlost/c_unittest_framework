


#include "ut_fw.h"

/**
 * test cases list exe
 * 
*/
tc_dword test_list_exe(TestCase_t * CaseList, tc_dword NumOfCase)
{
    tc_dword idx;
    TestReport_t test_report;
    TestSuite_t test_suite =
    {
        __FILE__,
        __DATE__,
        __TIME__,
        "spfanlost unittest",
        CaseList,
        NumOfCase,
    };

    LOG_COLOR(GREEN_LOG, "%s-%s %s start:\n", test_suite.Date, test_suite.Time, test_suite.TestSuiteTitle);

    memset((void *)&test_report,0,sizeof(TestReport_t));
    test_report.tests = test_suite.NumOfTestCase;

    LOG(LOG_INFO, "CaseNum|Enable|TestFuncName\n");
    for (idx = 0; idx < test_suite.NumOfTestCase; idx++)
    {
        LOG(LOG_INFO,"%4d   |%4d  |%-26s\n", idx, test_suite.TestCase[idx].En, test_suite.TestCase[idx].CaseName);
    }
    /* Execute test cases */
    for (idx = 0; idx < test_suite.NumOfTestCase; idx++)
    {
        if (test_suite.TestCase[idx].En)
        {
            LOG_COLOR(GREEN_LOG, "\nCase:%d,%s() Start:\n", idx, test_suite.TestCase[idx].CaseName);
            if(test_suite.TestCase[idx].PreFunc != NULL)
            {
                test_suite.TestCase[idx].PreFunc();
            }
            test_report.executed++;
            test_suite.TestCase[idx].Result = test_suite.TestCase[idx].CaseFunc();
            if(test_suite.TestCase[idx].Result == SUCCEED)
            {
                test_report.passed++;
            }
            else
            {
                test_report.failed++;
            }
            if(test_suite.TestCase[idx].EndFunc != NULL)
            {
                test_suite.TestCase[idx].EndFunc();
            }
        }
    }
    LOG(LOG_INFO, "\n------------------------------------------------------------------\n");
    LOG_COLOR(GREEN_LOG, "%s result:\n", test_suite.TestSuiteTitle);
    LOG(LOG_INFO, "CaseNum|Enable|Result|TestFuncName\n");
    for (idx = 0; idx < test_suite.NumOfTestCase; idx++)
    {
        if(test_suite.TestCase[idx].Result == SUCCEED)
            LOG(LOG_INFO,"%4d   |%4d  | %s |%-26s\n", idx, test_suite.TestCase[idx].En, "PASS", test_suite.TestCase[idx].CaseName);
        else
            LOG_COLOR(PURPLE_LOG,"%4d   |%4d  | %s |%-26s\n", idx, test_suite.TestCase[idx].En, "FAIL", test_suite.TestCase[idx].CaseName);
    }
    LOG(LOG_INFO,"Summary: %d Tests, %d Executed, %d Passed, %d Failed, %d Warnings.\n", 
        test_report.tests, 
        test_report.executed, 
        test_report.passed, 
        test_report.failed, 
        test_report.warnings); 
    return 0;
}

