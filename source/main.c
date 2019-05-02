
#include "ut_fw.h"

int ut_case_int_msix(void){
    LOG(LOG_INFO,"this case is tests msix interrupt!\n");
    return SUCCEED;
}
void ut_case_pre(void){
    LOG(LOG_INFO,"ut_case_pre\n");
}
void ut_case_end(void){
    LOG(LOG_INFO,"ut_case_end\n");
}

int ut_case_reg_scan(void){
    LOG(LOG_INFO,"this case is tests register scan!\n");
    return SUCCEED;
}
int ut_case_admin_q_write(void){
    LOG(LOG_INFO,"this case is tests admin q write cmd!\n");
    return FAILED;
}
int ut_case_io_q_write(void){
    LOG(LOG_INFO,"this case is tests io q write cmd!\n");
    return SUCCEED;
}

static TestCase_t TestCaseList[] = {
    TCD(ut_case_int_msix,         ENABLE, ut_case_pre, ut_case_end, FAILED),
    TCD(ut_case_reg_scan,         ENABLE, ut_case_pre, ut_case_end, FAILED),
    TCD(ut_case_admin_q_write,    ENABLE, ut_case_pre, ut_case_end, FAILED),
    TCD(ut_case_io_q_write,       ENABLE, ut_case_pre, ut_case_end, FAILED),
};

int main(void)
{
    test_list_exe(TestCaseList, ARRAY_SIZE(TestCaseList));
    return 0;    
}
