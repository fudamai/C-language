#include <stdio.h>
#define MAXLINE 80  // 允许的输入行的最大长度

int getline04(char line[], int maxline);
void copy04(char to[], char from[]);

/* 练习1-17打印长度大于80个字符的所有输入行 */
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
			printf("line：%s", line);
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

/* getline函数：将一行读入到s中并返回其长度 */
int getline04(char s[], int lim)
{
	int c, i;
	/*当for循环内，输入文本大于限制时，跳出循环
	但由于文本流尚未结束，故不会执行if(c =='\n'),直接执行s[i] = c
	跳回执行copy
	开始在while循环执行第二轮读取c，将剩下的c写入到数组s。如果这一轮读取了全部文本，就检测到'\n'，将'\n'插入到
	数组s中（这一轮里的数组s被清空重写了）
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

/* copy函数：将from复制到to；这里假定to足够大 */
void copy04(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}