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
		rbit = (x & 1) << (wordlength() - 1);  // ��һ��ԭ���ǣ��ƶ�nλ ����Ҫ�ַ���n+1��λ
		x = x >> 1;  // ����
		x = x | rbit; // ������λ�������
	}
	return x;
}

/* ����������ʹ�õ��ֳ� */
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;

	for (i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}



/*
��ɣ��ú������ؽ�xѭ�����ƣ��������Ҷ��Ƴ���λ������������룩n�������ƣ�λ�����õ���ֵ��
*/

/* ��ɽ��ͣ���������������˼�ǣ�����������λ���ȵ���������� */