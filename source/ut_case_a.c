
#include "ut_comm.h"

void ut_case_a_pre(void)
{
    LOG(LOG_INFO, "ut_case_a_pre\n");
}

void ut_case_a_end(void)
{
    LOG(LOG_INFO, "ut_case_a_end\n");
}

int ut_case_a(void)
{
    LOG(LOG_INFO, "this case is tests case_a function!\n");
    return SUCCEED;
}
