#include <stdio.h>
#define IN 1   /* �ڵ����� */
#define OUT 0  /* �ڵ����� */

int power(int m, int n);
float ftoc_float_function(float f);

main01()
{
	/*int i;

	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	return 0;*/
	/*int c;

	while ((c = getchar()) != EOF)
	{
		printf("%6.2f\n", ftoc_float_function(c));
	}*/
	/*int fnum, i;
	fnum = 10;
	for (i = 0; i<fnum; ++i)
		printf("%6.2f\n", ftoc_float_function(i));*/
	char sq[3];
	sq[2] = 9;
	printf("%s", sq);
}



float ftoc_float_function(float fahr)
{
	/* 
	* ��ϰ1-15
	�����¶��������¶ȶ��ձ�
	ִ�и�����Ԥ��
	����һ�����
	*/
	printf("һ�����϶������϶ȵļ���\n\n");
	float celsius;

	celsius = (5.0 / 9.0) * (fahr - 32.0);
	return celsius;
}

int power(int base, int n)
{
	/*ִ��������*/
	int i, p;
	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}

print_histogram_str()
{
	/*
	��ϰ1-14
	��ӡ�����ַ�����Ƶ�ȵ�ֱ��ͼ

	*/
}

print_histogram_word()
{
	/*
	��ӡ���ʵ��ܳ���
	*/
	int c, i, w,  nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits	");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
	printf("nwhite:");
	for (w = 0; w < nwhite; ++w)
	{
		printf("-");
	}
	printf("\nnother:");
	for (w = 0; w < nother; ++w)
	{
		printf("-");
	}
}

print_histogram()
{
	/*
	��ϰ 1-13
	��ӡ�����е��ʳ��ȵ�ֱ��ͼ
	��ÿ�����ʵ�����ӡ����������������滻�ַ�
	ɸѡ���ʡ���ӡ����
	��ӡ��һ�����ʣ�����
	TODO�����������ʣ���������ʱͳһ��ӡ
	��Ҫʹ�����鱣��ÿ�����ʵĳ���
	*/
	int c, i, s, l, cutline, nother;
	int histogram[10];

	cutline = OUT;
	nother = 0;
	l = 0;
	for (i = 0; i < 10; ++i)
		histogram[i] = 0;

	while ((c = getchar()) != EOF && nother <= 10)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			cutline = IN;
			//putchar(c);
			//printf("\n");
		}
		else if (c >= '0' && c <= '9')
			;  // ���ֲ����
		else if (cutline == 0)
		{
			//putchar(c);
			//printf("_");
			++histogram[nother];  // �Ե�ǰ���ʳ�������
		}
		else if (cutline == 1)
		{
			cutline = OUT;
			++nother;  // ����������1
			++histogram[nother];  // �Ե�ǰ���ʳ�������
			//putchar(c);
			//printf("_");
		}
	}
	for (i = 0; i < 10; ++i)
	{
		l = histogram[i];
		for (s = 0; s < l; s++)
		{
			printf("-");
		}
		printf("\n");
	}
}

count_digit_other()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits	");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}

print_single_word()
{
	/*
	��ÿ��һ�����ʵ���ʽ��ӡ������
	�����µ��ʾͻ��С�����һ��״ֵ̬�����ֵ��ʷָ�ʱ������״ֵ̬��
	�жϵ�״̬����ʱ�����ǰ���������
	*/
	int c, cutline;
	cutline = OUT;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			cutline = IN;
			putchar(c);
		}
		else if (cutline == 0)       
		{
			putchar(c);
		}
		else if (cutline == 1)
		{
			cutline = OUT;
			printf("\n");
			putchar(c);
		}
	}
}

count_line_word_str()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("\n%d %d %d\n", nl, nw, nc);
}

replaceEscape()
{
	/*
	��ϰ1-10
	û��ѧϰelse��䣬ֻ��ʹ��if��while���
	�������Ʊ�������˷�����б��ʱ��ʹ�ô�ӡ���ַ�������ʽ����Щ���Ŵ�ӡ����
	ʹ��putchar�޷�����Щ�����ַ������
	*/
	int c;
	while ((c = getchar()) != EOF)
	{
		/*putchar(c);
		printf("\n%d", A);*/
		if (c == '\\')
			printf("\\");
			//putchar("\\\\");
		if (c == '\t')
			printf("\\t");
			//putchar("\\t");
		if (c == '\b')
			printf("\\b");
			//putchar("\\b");
		putchar(c);
	}
}

mergeSpace()
{
	/*
	��ϰ1-9
	�ϲ������ո�Ϊһ��
	n����ո�����Ĭ��Ϊ0�����ǿո�ֵΪ0�����ո��Լ�1
	*/
	// ������Ҫһ�����Ƴ���
	int c;
	int n;
	n = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
		{
			if (n == 0)
			{
				putchar(c);
			}
			--n;
		}
		if (c != ' ')
		{
			n = 0;
			putchar(c);
		}

		/*c = getchar();*/
	}
}

count_space_tab_line()
{
	/* 
	��ϰ1-8
	ͳ�ƿո��Ʊ�������з����� 
	�ո� " "
	�Ʊ�� "\t"
	���з� "\n"
	ע��Ҫʹ�õ�����
	*/
	int c, spaceNum, tabNum, enterNum;

	spaceNum = 0;
	tabNum = 0;
	enterNum = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++spaceNum;
		if (c == '\t')
			++tabNum;
		if (c == '\n')
			++enterNum;
	}
	printf("�ո�����%d����������%d����������%d", spaceNum, tabNum, enterNum);
}

countline()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}

doublnc()
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}

longnc()
{
	long nc;
	/*����ֻ�����˳�ʱ���������
	���з���������ֻ��һλ
	*/
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
	inout();
}

inout()
{
	int c;
	printf("%d", EOF);
	while (c = getchar() != EOF) {
		putchar(c);

		/*c = getchar();*/
	}

}