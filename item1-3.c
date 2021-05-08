#include <stdio.h>
#define MAXLINE 100  // ����������е���󳤶�

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* ��ӡ������� */
main3()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		printf("%s", line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

/* getline��������һ�ж��뵽s�в������䳤�� */
int getline(char s[], int lim)
{
	int c, i;
	/*��forѭ���ڣ������ı���������ʱ������ѭ��
	�������ı�����δ�������ʲ���ִ��if(c =='\n'),ֱ��ִ��s[i] = c
	����ִ��copy
	��ʼ��whileѭ��ִ�еڶ��ֶ�ȡc����ʣ�µ�cд�뵽����s�������һ�ֶ�ȡ��ȫ���ı����ͼ�⵽'\n'����'\n'���뵽
	����s�У���һ���������s�������д�ˣ�
	*/
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		printf("%d, [40]", i);
		++i;
	}
	s[i] = '\0';
	printf("%d, [44]", i);
	return i;
}

/* copy��������from���Ƶ�to������ٶ�to�㹻�� */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}