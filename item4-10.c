#include <stdio.h>
#include <stdlib.h>  // Ϊ��ʹ��atof()����
#include <ctype.h>

#define MAXOP 100  // �����������������󳤶�
#define NUMBER '0'  // ��ʶ�ҵ�һ����
#define BUFSIZE 100

char buf4_10[BUFSIZE];  // ����ungetch�����Ļ�����
int bufp4_10 = 0;  // buf����һ������λ��
extern int getline(char, int);

/* getop��������ȡ��һ�����������ֵ������ */
int getop4_10(char s[])
{
	int i, c;

	if (buf4_10[bufp4_10] == '\0') {  // ��ȡ����ǰ�ж���һ���Ƿ������
		if (getline(buf4_10, BUFSIZE) == 0) {
			return EOF;  // û�л�ȡ��
		}
		else {
			bufp4_10 = 0;  // ������ϣ�ָ�����
		}
	}

	while ((s[0] = c = buf4_10[bufp4_10++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;  // ������
	i = 0;
	if (isdigit(c))  // �ռ���������
		while (isdigit(s[++i] = c = buf4_10[bufp4_10++]))  // С�����������Ѿ���ֵ��ɣ���ǰ����һ���ַ�
			;
	if (c == '.')  // �ռ�С������
		while (isdigit(s[++i] = c = buf4_10[bufp4_10++]))  // �ȸ�ֵ����getch����ֵʱִ�е��Ǹ��ǲ�����getch����ʱ��Ҳ���ȸ�ֵ�����ж�
			;
	s[i] = '\0';
	if (c != EOF)  // ��Windows���Ǹ�������ж�
		bufp4_10--;
	return NUMBER;
}