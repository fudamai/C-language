#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'  // ��ʶ�ҵ�һ����


int getch(void);
void ungetch(int);

/* getop��������ȡ��һ�����������ֵ������ */
int getop4_11(char s[])
{
	int i, c;
	static int lastc = 0;

	if (lastc == 0)
		c = getch();
	else {
		c = lastc;  // �ӻ�����ȡֵ
		lastc = 0;
	}
	
	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;  // ������
	i = 0;
	if (isdigit(c))  // �ռ���������
		while (isdigit(s[++i] = c = getch()))  // С�����������Ѿ���ֵ��ɣ���ǰ����һ���ַ�
			;
	if (c == '.')  // �ռ�С������
		while (isdigit(s[++i] = c = getch()))  // �ȸ�ֵ����getch����ֵʱִ�е��Ǹ��ǲ�����getch����ʱ��Ҳ���ȸ�ֵ�����ж�
			;
	s[i] = '\0';
	if (c != EOF)  // ��⵽��ǰ�ַ����ǽ�β��ѹ��
		lastc = c;
	return NUMBER;
}