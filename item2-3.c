#include <stdio.h>

#define YES 1
#define NO 0

main2_3()
{
	int aa;

	
	aa = "0x100";
	
	printf("%d\n", htois(aa));
}

/* ��ʮ�������ַ���ת��Ϊ���� */
int htois(char s[])
{
	int hexdigit, i, inhex, n;
	
	i = 0;
	/* ������ѡ��0x �� 0X */
	if (s[i] == '0') {
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	/* ������ʱi Ϊ1 */

	n = 0;
	inhex = YES;
	for (; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';  // ʮ�����������ֵ�����ֵ����ʮ������ͬ
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;  // ʮ��������ĸ����a�ĳ��ȣ�����ʮ����������ʮ�����е�����ֵ
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
		{
			inhex = NO;  // ����һ����Ч��ʮ����������
		}
		if (inhex == YES)
			n = 16 * n + hexdigit;  // ��λ����ֵ��ת���� * ���ƣ�ԭ���ƣ� + ���λ����ֵ��ת���� = ��Ч����
	}
	return n;
}

/*
�������������������������Ƶģ�
for ( ; inhex == YES; ++i)
�������ͱ���i ������ s ���±ꡣ��s[i]��һ���Ϸ���ʮ����������ʱ��inhex��ȡֵ��
����ΪYES����ѭ��Ҳ������ִ�С����ͱ���hexdigit��ȡֵ��Χ��0-15��
���
if (inhex == YES)
��֤����Ԫ��s[i]��һ���Ϸ���ʮ�����������ַ�����ֵ��hexdigit�ķ�Χ֮�ڡ���ѭ��
����ʱ������htoi�����ر���n��ֵ��
���������atoi������Ҫ���߶��ַ������˽�
*/