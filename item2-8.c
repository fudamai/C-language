#include <stdio.h>

main2_8()
{
	int x = 2;
	printf("%u", rightrox(x, 3));
}

unsigned rightrox(unsigned x, int n)
{
	int wordlength(void);
	int rbit;
	
	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() - 1);  // 减一的原因是：移动n位 ，需要字符有n+1个位
		x = x >> 1;  // 右移
		x = x | rbit; // 对最左位进行填充
	}
	return x;
}

/* 计算出计算机使用的字长 */
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;

	for (i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}



/*
题干：该函数返回将x循环右移（即从最右端移出的位将从最左端移入）n（二进制）位后所得到的值。
*/

/* 题干解释：从最左端移入的意思是，从数据类型位长度的最左端移入 */