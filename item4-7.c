#include <string.h>
#include <stdio.h>

main4_7()
{
	char str7[] = "adcf";
	printf("%d\n", strlen(str7));
}

void ungets(char s[])
{
	int i = strlen(s);  // ������õ�strlen��item2-4���Լ�����ĺ���
	void ungetch(int);

	while (i > 0) {
		ungetch(s[--i]);
	}
}

/*
��ɣ���дһ������ungets(s)���������ַ���sѹ�ص������С�ungets������Ҫʹ��buf��bufp�����ܷ��ʹ��ungetch����
*/