#include <stdio.h>
#define IN 1   /* 在单词内 */
#define OUT 0  /* 在单词外 */

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
	* 练习1-15
	华氏温度与摄氏温度对照表
	执行浮点数预算
	返回一个结果
	*/
	printf("一个华氏度与摄氏度的计算\n\n");
	float celsius;

	celsius = (5.0 / 9.0) * (fahr - 32.0);
	return celsius;
}

int power(int base, int n)
{
	/*执行幂运算*/
	int i, p;
	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}

print_histogram_str()
{
	/*
	练习1-14
	打印各个字符出现频度的直方图

	*/
}

print_histogram_word()
{
	/*
	打印单词的总长度
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
	练习 1-13
	打印输入中单词长度的直方图
	将每个单词单独打印出来，用特殊符号替换字符
	筛选单词、打印单词
	打印下一个单词，换行
	TODO：输出多个单词，结束程序时统一打印
	需要使用数组保存每个单词的长度
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
			;  // 数字不输出
		else if (cutline == 0)
		{
			//putchar(c);
			//printf("_");
			++histogram[nother];  // 对当前单词长度自增
		}
		else if (cutline == 1)
		{
			cutline = OUT;
			++nother;  // 单词数自增1
			++histogram[nother];  // 对当前单词长度自增
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
	以每行一个单词的形式打印其输入
	遇见新单词就换行。设置一个状态值，出现单词分隔时，更改状态值。
	判断到状态更改时，输出前先输出换行
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
	练习1-10
	没有学习else语句，只能使用if、while语句
	在碰到制表符、回退符、反斜杠时，使用打印以字符串的形式将这些符号打印出来
	使用putchar无法将这些特殊字符串输出
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
	练习1-9
	合并连续空格为一个
	n代表空格数，默认为0，遇非空格赋值为0，遇空格自减1
	*/
	// 首先需要一个复制程序
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
	练习1-8
	统计空格、制表符、换行符个数 
	空格 " "
	制表符 "\t"
	换行符 "\n"
	注意要使用单引号
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
	printf("空格数：%d，缩进数：%d，换行数：%d", spaceNum, tabNum, enterNum);
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
	/*程序只有在退出时才输出长度
	换行符计数，但只记一位
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