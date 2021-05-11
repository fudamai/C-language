#include <stdio.h>
#include <limits.h>

/* determine ranges of type */
print_range_by_limits()
{
	//signed type
	printf("signed char min : %d\n", SCHAR_MIN);
	printf("signed char max : %d\n", SCHAR_MAX);
	printf("signed short min : %d\n", SHRT_MIN);
	printf("signed short max : %d\n", SHRT_MAX);
	printf("signed int min : %d\n", INT_MIN);
	printf("signed int max : %d\n", INT_MAX);
	printf("signed long min : %ld\n", LONG_MIN);
	printf("signed long max : %ld\n", LONG_MAX);
	// unsigned type
	printf("unsigned char max : %u\n", UCHAR_MAX);
	printf("unsigned short max : %u\n", USHRT_MAX);
	printf("unsigned int max : %u\n", UINT_MAX);
	printf("unsigned long max : %u\n", ULONG_MAX);
}

/* ANSI C标准规定：各种类型的取值范围必须在头文件<limits.h>中定义。short、int、long
类型在不同硬件上有不同的长度，所以他们在不同机器上的取值范围也往往会不同。上面是利用
标准头文件来确定类型取值范围的解决方案，*/

print_range_by_bit()
{
	//signed type
	printf("signed char min : %d\n", -(char)((unsigned char) ~0 >> 1));
	printf("signed char max : %d\n", (char)((unsigned char) ~0 >> 1));
	printf("signed short min : %d\n", -(short)((unsigned char) ~0 >> 1));
	printf("signed short max : %d\n", (short)((unsigned char) ~0 >> 1));
	printf("signed int min : %d\n", -(int)((unsigned int) ~0 >> 1));
	printf("signed int max : %d\n", (int)((unsigned int) ~0 >> 1));
	printf("signed long min : %ld\n", -(long)((unsigned long) ~0 >> 1));
	printf("signed long max : %ld\n", (long)((unsigned long) ~0 >> 1));
	// unsigned type
	printf("unsigned char max : %u\n", (unsigned char) ~0);
	printf("unsigned short max : %u\n", (unsigned short) ~0);
	printf("unsigned int max : %u\n", (unsigned int) ~0);
	printf("unsigned long max : %u\n", (unsigned long) ~0);
}

/* 另一解决方案是利用按位运算符（本书2.9）进行计算。表达式
(char)((unsigned char) ~0 >> 1)
先把数字0的各个二进制位全部转换为1：
~0
然后，将结果值转换为unsigned char类型：
(unsigned char) ~0
再把这个unsigned char 类型值右移一位以清除符号位：
(unsigned char) ~0 >> 1
最后，把它转换为char 类型：
(char)((unsigned char) ~0 >> 1)
这一系列操作的最终结果就得到了signed类型字符的最大值。
*/