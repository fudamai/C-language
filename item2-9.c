main2_9()
{
	unsigned a;
	a = 3;
	printf("%d\n", bitcount3(a));
}

int bitcount2(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)  // ��ִ��for��䣬��ִ��x >>= 1
		if (x & 01)
			b++;
	return b;
}

/* ����λ����ƣ���������λ���ֶ����ʱ�����������������һ��һ */
int bitcount3(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &= x - 1)
		++b;
	return b;

}