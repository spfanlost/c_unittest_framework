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
#define TYPE_OFST(type,field) ((dword_t)&(((type*)0)->field))

#define MEM32_GET(n) (*(volatile dword_t *)(n))
#define MEM16_GET(n) (*(volatile word_t *)(n))
#define MEM8_GET(n) (*(volatile byte_t *)(n))

#define RAND_INIT() (srand(time(NULL)))
#define BYTE_RAND() ((byte_t)rand())
#define WORD_RAND() ((word_t)rand())
#define DWORD_RAND() ((dword_t)rand() << 16 | rand())
#define RAND_RANGE(s, e) (rand() % ((e) - (s) + 1) + (s))

#define BYTE_MASK (0xFF)
#define WORD_MASK (0xFFFF)
#define DWORD_MASK (0xFFFFFFFF)
#define QWORD_MASK (0xFFFFFFFFFFFFFFFF)

#define PRINT_IF printf

#define _VAL(x) #x
#define _STR(x) _VAL(x)

#endif
