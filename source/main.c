
#include "ut_comm.h"

void ut_case_b_pre(void) {}
void ut_case_b_end(void) {}
int ut_case_b(void)
{
    LOG(LOG_INFO, "this case is tests b function!\n");
    return FAILED;
}

void ut_case_c_pre(void) {}
void ut_case_c_end(void) {}
int ut_case_c(void)
{
    LOG(LOG_INFO, "this case is tests c function!\n");
    return SUCCEED;
}

TestCase_t TestCaseList[] = {
    TCD(ENABLE, ut_case_a),
    TCD(ENABLE, ut_case_b),
    TCD(DISABLE, ut_case_c),
    TCD(ENABLE, ut_case_c),
};

int main(void)
{
    test_list_exe(TestCaseList, ARRAY_SIZE(TestCaseList));
}