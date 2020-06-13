/**
 * @file common_define.h
 * @author meng_yu (imyumeng@qq.com)
 * @brief 
 * @version 0.1
 * @date 2020-06-06
 * 
 * @copyright imyumeng@qq.com Copyright (c) 2020
 * 
 */
#ifndef _COMMON_DEFINE_H_
#define _COMMON_DEFINE_H_

#define FAILED (0)
#define SUCCEED (1)

#define DISABLE (0)
#define ENABLE (1)

#ifndef NULL
#define NULL (0)
#endif

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define MEM32_GET(n) (*(volatile dword_t *)(n))
#define MEM16_GET(n) (*(volatile word_t *)(n))
#define MEM8_GET(n) (*(volatile byte_t *)(n))

#define RAND_INIT() (srand(time(NULL)))
#define BYTE_RAND() ((byte_t)rand())
#define WORD_RAND() ((word_t)rand())
#define DWORD_RAND() ((dword_t)rand() << 16 | rand())
#define RAND_RANGE(s, e) (rand() % ((e) - (s) + 1) + (s))

#define ASSERT_WARN(message, test) \
    do                             \
    {                              \
        if (!(test))               \
            return message;        \
    } while (0)
#define ASSERT_ERROR(message, test) \
    do                              \
    {                               \
        if (!(test))                \
            return message;         \
    } while (0)
#define ASSERT_FAILED(message, test) \
    do                               \
    {                                \
        if (!(test))                 \
            return message;          \
    } while (0)
#define ASSERT_PASSED(message, test) \
    do                               \
    {                                \
        if (!(test))                 \
            return message;          \
    } while (0)

// /* Assertions and test results */
// #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
// #define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

#endif
