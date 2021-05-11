#include <stdio.h>
#define MAXLINE 1000

int getline19(char line[], int maxline);
void reverse19(char s[]);

// 打印最长输出行
int main()
{
	char line[MAXLINE];

	while (getline19(line, MAXLINE) > 0)
	{
		reverse19(line);
		printf("%s", line);
	}
	return 0;
}

void reverse19(char s[])
{
	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0')
	{
		i++; // 计算出数组的长度
	}
	i--;
	if (s[i] == '\n')
	{
		i--;
	}

	j = 0;
	while (j < i)
	{
		temp = s[j];  // 输出数组第一个值
		s[j] = s[i];  // 将数组第一个值与最后一个值进行替换
		s[i] = temp;  // 将最后一个值与第一个值替换
		--i;
		++j;
	}
}

//读入一行到s中并且返回长度
int getline19(char s[], int lim)
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