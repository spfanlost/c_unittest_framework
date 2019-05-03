/*-----------------------------------------------------------------------------
 *      Name:         ut_fw.h 
 *      Purpose:      unittest framework types and structures description
 *----------------------------------------------------------------------------
 *      Copyright(c) 
 *----------------------------------------------------------------------------*/

#ifndef __UT_FW_H__
#define __UT_FW_H__

#include <stdio.h>
#include <string.h>

// JUST FOR DEBUG
#define BLACK_LOG "30"  //黑色
#define RED_LOG "31"    //红色
#define GREEN_LOG "32"  //绿色
#define YELLOW_LOG "33" //黄色
#define BLUE_LOG "34"   //蓝色
#define PURPLE_LOG "35" //紫色
#define SKBLU_LOG "36"  //天蓝
#define WHITE_LOG "37"  //白色

#define DISP_LOG_COLOR
#ifdef DISP_LOG_COLOR
#define LOG_COLOR(color, format, ...) printf("\033[" color "m" format "\033[0m", ##__VA_ARGS__)
#define COLOR_STR(color, str) ("\033[" color "m" str "\033[0m")
#else
#define LOG_COLOR(color, format, ...) ((void)0)
#endif
//--------------------------------------------------------------------------------
//   LOG LEVEL
//   DEBUG<INFO<WARN<ERROR<FATAL
#define LOG_DBUG 0x10000000
#define LOG_INFO 0x20000000
#define LOG_WARN 0x40000000
#define LOG_ERROR 0x80000000
#define ALL_LOG 0xFFFFFFFF
#define LOG_FILTER (LOG_INFO | LOG_WARN | LOG_ERROR) //|LOG_DBUG)
// #define LOG_FILTER (ALL_LOG)
#define LOG(filter, fmt, ...)                                                                                        \
    do                                                                                                               \
    {                                                                                                                \
        if (filter & LOG_FILTER)                                                                                     \
        {                                                                                                            \
            if ((filter & LOG_ERROR) == LOG_ERROR)                                                                   \
            {                                                                                                        \
                printf("\033[31mERROR!!! %s:%d %s()\033[0m: " fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
            }                                                                                                        \
            else if ((filter & LOG_WARN) == LOG_WARN)                                                                \
            {                                                                                                        \
                printf("\033[33mWARNING! %s:%d %s()\033[0m: " fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
            }                                                                                                        \
            else                                                                                                     \
                printf(fmt, ##__VA_ARGS__);                                                                          \
        }                                                                                                            \
    } while (0)
//--------------------------------------------------------------------------------

/* Test case definition macro */
#define DISABLE 0
#define ENABLE 1

#define SUCCEED 0
#define FAILED -1

#ifndef __cplusplus
#define NULL ((void *)0)  /* C++ */
#else  
#define NULL 0  /* C */
#endif

// TestCaseDefine
#define TCD(en , tf) {tf, #tf, en, tf##_pre, tf##_end, FAILED}
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define ASSERT_WARN(message, test) do { if (!(test)) return message; } while (0)
#define ASSERT_ERROR(message, test) do { if (!(test)) return message; } while (0)
#define ASSERT_FAILED(message, test) do { if (!(test)) return message; } while (0)
#define ASSERT_PASSED(message, test) do { if (!(test)) return message; } while (0)

// /* Assertions and test results */
// #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
// #define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

typedef unsigned int    tc_dword;
typedef unsigned short  tc_word;
typedef unsigned char   tc_byte;
typedef int             tc_int;
typedef short           tc_short;
typedef char            tc_char;
typedef int (*CaseFunc_t)(void);
typedef void (*VoidFunc_t)(void);

/* Test case description structure */
typedef struct _TestCase_t
{
    CaseFunc_t CaseFunc;        /* Case function                        */
    const char *CaseName;       /* Case function name string            */
    tc_dword En;                /* Case function enabled                */
    VoidFunc_t PreFunc;
    VoidFunc_t EndFunc;
    tc_int Result;
} TestCase_t;

/* Test suite description structure */
typedef struct _TestSuite_t
{
    const char *FileName;       /* Test module file name                */
    const char *Date;           /* Compilation date                     */
    const char *Time;           /* Compilation time                     */
    const char *TestSuiteTitle; /* Title or name of module under test   */
    TestCase_t *TestCase;       /* Array of test cases                  */
    tc_dword NumOfTestCase;     /* Number of test cases (sz of TC array)*/
} TestSuite_t;

/* Assertion statistics */
typedef struct _AssertStat_t
{
    tc_dword passed;            /* Total assertions passed              */
    tc_dword failed;            /* Total assertions failed              */
    tc_dword warnings;          /* Total assertions warnings            */
} AssertStat_t;

/* Test global statistics */
typedef struct _TestReport_t
{
    tc_dword tests;             /* Total test cases count               */
    tc_dword executed;          /* Total test cases executed            */
    tc_dword passed;            /* Total test cases passed              */
    tc_dword failed;            /* Total test cases failed              */
    tc_dword warnings;          /* Total test cases warnings            */
    AssertStat_t assertions;    /* Total assertions statistics          */
} TestReport_t;

tc_dword test_list_exe(TestCase_t * TestList, tc_dword NumOfCase);

#endif
