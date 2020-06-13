/**
 * @file test_metrics.c
 * @author yumeng (imyumeng@qq.com)
 * @brief  this is a sample c unittest framework.also realization some 
 *         sample function like memcmp/mem_disp for debug.
 * @version 0.1
 * @date 2019-07-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "common.h"
#include "unittest.h"

/**
 * @brief test list exe
 * 
 * @param CaseList 
 * @param NumOfCase 
 * @return dword_t 
 */
dword_t test_list_exe(TestCase_t *CaseList, dword_t NumOfCase)
{
    dword_t idx;
    TestReport_t test_report;
    TestSuite_t test_suite =
        {
            __FILE__,
            __DATE__,
            __TIME__,
            "yumeng,s HC(sata) unittest",
            CaseList,
            NumOfCase,
        };

    LOG_COLOR(GREEN_LOG, "%s-%s %s start:\n", test_suite.Date, test_suite.Time, test_suite.TestSuiteTitle);

    memset((void *)&test_report, 0, sizeof(TestReport_t));
    test_report.tests = test_suite.NumOfTestCase;

    LOG_INFO("CaseNum|Enable|TestFuncName\n");
    for (idx = 0; idx < test_suite.NumOfTestCase; idx++)
    {
        LOG_INFO("%4d   |%4d  |%-26s\n", idx, test_suite.TestCase[idx].En, test_suite.TestCase[idx].CaseName);
    }
    /* Execute test cases */
    for (idx = 0; idx < test_suite.NumOfTestCase; idx++)
    {
        if (test_suite.TestCase[idx].En)
        {
            LOG_COLOR(GREEN_LOG, "\nCase:%d,%s() Start:\n", idx, test_suite.TestCase[idx].CaseName);
            // if(test_suite.TestCase[idx].PreFunc != NULL)
            // {
            //     test_suite.TestCase[idx].PreFunc();
            // }
            test_report.executed++;
            test_suite.TestCase[idx].Result = test_suite.TestCase[idx].CaseFunc();
            if (test_suite.TestCase[idx].Result == SUCCEED)
            {
                test_report.passed++;
            }
            else
            {
                test_report.failed++;
            }
            // if(test_suite.TestCase[idx].EndFunc != NULL)
            // {
            //     test_suite.TestCase[idx].EndFunc();
            // }
        }
    }
    LOG_INFO("\n------------------------------------------------------------------\n");
    LOG_COLOR(GREEN_LOG, "%s result:\n", test_suite.TestSuiteTitle);
    LOG_INFO("CaseNum|Enable|Result|TestFuncName\n");
    for (idx = 0; idx < test_suite.NumOfTestCase; idx++)
    {
        if (test_suite.TestCase[idx].Result == SUCCEED)
            LOG_INFO("%4d   |%4d  | %s |%-26s\n", idx, test_suite.TestCase[idx].En, "PASS", test_suite.TestCase[idx].CaseName);
        else
            LOG_COLOR(PURPLE_LOG, "%4d   |%4d  | %s |%-26s\n", idx, test_suite.TestCase[idx].En, "FAIL", test_suite.TestCase[idx].CaseName);
    }
    LOG_INFO("Summary: %d Tests, %d Executed, %d Passed, %d Failed, %d Warnings.\n",
             test_report.tests,
             test_report.executed,
             test_report.passed,
             test_report.failed,
             test_report.warnings);
    return 0;
}

/**
 * @brief memery data display
 * 
 * @param mem_addr 
 * @param data_size display size
 */
void mem_disp(void *mem_addr, dword_t data_size)
{
    dword_t columns, rows;
    dword_t column_cnt, row_cnt;
    dword_t *ptr = NULL;
    column_cnt = 8;
    row_cnt = data_size / column_cnt / 4;
    if (column_cnt == 16)
        LOG_INFO("<--addr---dword-->: 03----00 07----04 11----08 15----12 19----16 23----20 27----24 31----28 "
                 "35----32 39----36 43----40 47----44 51----48 55----52 59----56 63----60\n");
    else
        LOG_INFO("<--addr---dword-->: 03----00 07----04 11----08 15----12 19----16 23----20 27----24 31----28\n");

    ptr = (dword_t *)mem_addr;
    for (rows = 0; rows < row_cnt; rows++)
    {
        // LOG(LOG_INFO,"%p: ", mem_addr + rows * 4 * column_cnt);
        LOG_INFO("0x%016lx: ", (qword_t)(mem_addr + rows * 4 * column_cnt));
        // LOG(LOG_INFO,"0x%-16lx: ", (qword_t)(+ rows * 4 * column_cnt));
        for (columns = 0; columns < column_cnt; columns++)
        {
            LOG_INFO("%08x ", ptr[columns]);
        }
        LOG_INFO("\n");
        ptr += column_cnt;
    }
}
/**
 * @brief memery data compare
 * 
 * @param mem_addr1 
 * @param mem_addr2 
 * @param data_size 
 * @return int_t 
 */
int_t mem_cmp(dword_t *mem_addr1, dword_t *mem_addr2, dword_t data_size)
{
    int_t idx = 0;
    idx = memcmp(mem_addr1, mem_addr2, data_size);
    if (idx)
        LOG_ERROR("Compare ERROR!!! idx:%d\n", idx);
    else
        LOG_DBUG("Compare OK!!! \n");
    return idx;
}
/**
 * @brief set memery data as pattern data
 * 
 * @param mem_addr1 
 * @param pattern 
 * @param data_size 
 * @return int_t 
 */
int_t mem_set(dword_t *mem_addr1, dword_t pattern, dword_t data_size)
{
    dword_t idx = 0;
    if (mem_addr1 == NULL)
        return idx;
    for (idx = 0; idx < (data_size / 4); idx++)
    {
        mem_addr1[idx] = pattern;
    }
    return idx;
}
/**
 * @brief get dw memery data, compare with pattern data 
 * 
 * @param mem_addr1 
 * @param pattern 
 * @param data_size 
 * @return int_t 
 */
int_t pat_cmp(dword_t *mem_addr1, dword_t pattern, dword_t data_size)
{
    dword_t idx = 0;
    byte_t flg = 0;
    if (mem_addr1 == NULL)
        return idx;
    for (idx = 0; idx < (data_size / 4); idx++)
    {
        if (mem_addr1[idx] != pattern)
            flg = 1;
    }
    if (flg)
        LOG_ERROR("Compare ERROR!!! idx:%d\n", idx);
    else
        LOG_DBUG("Compare OK!!! \n");
    return idx;
}
