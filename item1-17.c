#include <stdio.h>
#define MAXLINE 80  // ����������е���󳤶�

int getline04(char line[], int maxline);
void copy04(char to[], char from[]);

/* ��ϰ1-17��ӡ���ȴ���80���ַ������������� */
main04()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	int num = 0;

	max = 0;
	while ((len = getline04(line, MAXLINE)) > 0)
	{
		
		if (len >= max) {
			max = len;
			copy04(longest, line);
		}
		if (len == 79 && num == 0) {
			++num;
			printf("line��%s", line);
		}
		else if (len < 79 && num == 1) {
			--num;
			printf("%s", line);
		}
		else if (len == 79 && num ==1) {
			printf("%s", line);
		}
	}
	/*if (max > 0)
		printf("%s", longest);*/
	return 0;
}

/* getline��������һ�ж��뵽s�в������䳤�� */
int getline04(char s[], int lim)
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
		//printf("%d, [40]", i);
		++i;
	}
	s[i] = '\0';
	//printf("%d, [44]", i);
	return i;
}

/* copy��������from���Ƶ�to������ٶ�to�㹻�� */
void copy04(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}