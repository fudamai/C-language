main2_6()
{
	unsigned int num1, num2;
	num1 = 45;
	num2 = 7;
	
	printf("%d\n", setbits(num1, 2, 2, num2));
}

/* ��x�Ĳ���ֵ��y��ֵ���� */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p+1-n);
}

/*
������Ҫ��x��pλ��ʼ��nλ�������㡣��ȡλ��0���а�λ��
��y�����ұߵ�nλ��ȡ������������p+1-nλ������x���滻λ����ǰ�����Ϊ0.����ȡλ��1���а�λ������
ִ�а�λ��x��ǰ
*/