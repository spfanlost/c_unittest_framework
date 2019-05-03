
#include "ut_comm.h"


void ut_case_b_pre(void) {}
void ut_case_b_end(void) {}
int ut_case_b(void){
    LOG(LOG_INFO,"this case is tests b function!\n");
    return FAILED;
}

void ut_case_c_pre(void) {}
void ut_case_c_end(void) {}
int ut_case_c(void){
    LOG(LOG_INFO,"this case is tests c function!\n");
    return SUCCEED;
}

TestCase_t TestCaseList[] = {
    TCD(ENABLE , ut_case_a),
    TCD(ENABLE , ut_case_b),
    TCD(DISABLE, ut_case_c),
    TCD(ENABLE , ut_case_c),
};

//  int tests_run = 0;
 
//  int foo = 7;
//  int bar = 4;
 
//  static char * test_foo() {
//      mu_assert("error, foo != 7", foo == 7);
//      return 0;
//  }
 
//  static char * test_bar() {
//      mu_assert("error, bar != 5", bar == 5);
//      return 0;
//  }
 
//  static char * all_tests() {
//      mu_run_test(test_foo);
//      mu_run_test(test_bar);
//      return 0;
//  }
 
 int main(void) {
    //  char *result = all_tests();
    //  if (result != 0)  {
    //      printf("%s\n", result);
    //  }
    //  else {
    //      printf("ALL TESTS PASSED\n");
    //  }
    //  printf("Tests run: %d\n", tests_run);
    //  return result != 0;

     test_list_exe(TestCaseList, ARRAY_SIZE(TestCaseList));

 }