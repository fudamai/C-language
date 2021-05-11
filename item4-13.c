#include <string.h>
#include <stdio.h>

void reverse_recur(char);

main4_13()
{
	char str13[] = "abcdefg";

	reverse_recur(str13);
	printf(str13);
}

void reverse_recur(char s[])
{
	void reverser(char [], int, int);
	reverser(s, strlen(s), 0);
}


/* 传入参数：字符、长度、标识深度的i=0 */
void reverser(char s[], int l, int i) {
	int c, j;
	j = l - (i + 1);
	if(i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, l, ++i);
	}
}

//void reverse34(char s[])
//{
//	int c, i, j;
//
//	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
//	{
//		c = s[i];
//		s[i] = s[j];
//		s[j] = c;
//	}
//}

/*
题干：
编写一个递归版本的reverse(s)函数，以将字符串s倒置
*/