
#include <stdio.h>
#define MAXLINE 10	//允许输入行的最大长度

int getline18(char line[], int maxline);
int remove18(char s[]);

//打印最长输入行
int main18()
{
	char line[MAXLINE];		//当前输入行

	while (getline18(line, MAXLINE) > 0)
	{
		if (remove18(line) > 0)
		{
			printf("%s", line);
		}
	}

	return 0;
}

int remove18(char s[])
{
	int i;

	i = 0;
	while (s[i] != '\n')
	{
		++i; // 换行符前的字符数
	}
	--i;

	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
	{
		--i;  // 去掉空格和缩进的字符数
	}

	if (i >= 0)
	{
		++i;
		s[i] = '\n';  // 添加换行
		++i;
		s[i] = '\0';  // 添加字符串结束符
	}

	return i;
}

//读入一行到s中并且返回长度
int getline18(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < lim - 2)
		{
			s[j] = c;
			++j;
		}

	}
	if (c == '\n')
	{
		s[j] = c;
		++i;
		++j;
	}

	s[j] = '\0';

	return i;
}