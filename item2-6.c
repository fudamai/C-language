main2_6()
{
	unsigned int num1, num2;
	num1 = 45;
	num2 = 7;
	
	printf("%d\n", setbits(num1, 2, 2, num2));
}

/* 将x的部分值用y的值覆盖 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p+1-n);
}

/*
首先需要将x的p位开始的n位进行清零。提取位与0进行按位与
将y的最右边的n位提取出来，往右移p+1-n位（对齐x待替换位），前后填充为0.。提取位与1进行按位与运算
执行按位或，x在前
*/