
#include "common.h"
#include "unittest.h"
#include "ut_case.h"

void ut_case_b_pre(void) {}
void ut_case_b_end(void) {}
dword_t ut_case_b(void)
{
    LOG_INFO("this case is tests b function!\n");
    return FAILED;
}

void ut_case_c_pre(void) {}
void ut_case_c_end(void) {}
dword_t ut_case_c(void)
{
    LOG_INFO("this case is tests c function!\n");
    return SUCCEED;
}

TestCase_t TestCaseList[] = {
    TCD(ut_case_a, ENABLE),
    TCD(ut_case_b, ENABLE),
    TCD(ut_case_c, DISABLE),
    TCD(ut_case_c, ENABLE),
};

int main(void)
{    
    test_list_exe(TestCaseList, ARRAY_SIZE(TestCaseList));
}