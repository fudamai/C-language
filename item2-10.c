#include <stdio.h>

main2_10()
{
	int c;
	/*char a[] = "AAaaa";
	printf("%s\n", a[1]);*/

	while ((c = getchar()) != EOF)
		printf("%s\n", lower2(c));
}

int lower1(int c)  // int cʵ�����ǽ��������ת��Ϊint ����
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
	{
		return c;
	}
}

int lower2(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

/* ��д����д��ĸת��ΪСд��ĸ�ĺ��� lower �������������ʽ������е�if-else�ṹ */