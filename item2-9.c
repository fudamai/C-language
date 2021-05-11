main2_9()
{
	unsigned a;
	a = 3;
	printf("%d\n", bitcount3(a));
}

int bitcount2(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)  // 先执行for语句，再执行x >>= 1
		if (x & 01)
			b++;
	return b;
}

/* 利用位与机制，当二进制位出现多个零时，快速消除零计算下一个一 */
int bitcount3(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &= x - 1)
		++b;
	return b;

}