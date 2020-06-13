
#include "common.h"

void ut_case_a_pre(void)
{
    LOG_INFO("ut_case_a_pre\n");
}

void ut_case_a_end(void)
{
    LOG_INFO("ut_case_a_end\n");
}

dword_t ut_case_a(void)
{
    LOG_INFO("this case is tests case_a function!\n");
    return SUCCEED;
}
