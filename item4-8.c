#define BUFSIZE 100

char buf4_8 = '0';  // ����ungetch�����Ļ�����
int bufp4_8 = 0;  // buf����һ������λ��

int getch4_8(void)  // ȡһ���ַ���������ѹ�ص��ַ���
{
	return (bufp4_8 > 0) ? buf4_8 : getchar();
	/* ��������ȡ��Ҫ�ָ� */
	int c;
	
	if (buf4_8 != '0') {
		c = buf4_8;
		buf4_8 = '0';
	}
	else {
		c = getchar();
	}
	return c;
}

void ungetch(int c)  // ���ַ�ѹ��������
{
	if (buf4_8 != '0')
		printf("ungetch: too many characters\n");
	else
		buf4_8 = c;
}

/* 
��ɣ��ٶ����ֻѹ��һ���ַ�������Ӧ�޸�getch��ungetch����������
*/