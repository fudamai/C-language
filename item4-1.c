#include <stdio.h>
#include <ctype.h>

int strrindex(char s[], char t);

main()
{
	char str1[] = "abcdefghijklmn";
	char a = 'g';

	printf("%d\n", strrindex(str1, a));
}

int strrindex(char s[], char t)
{
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == t) {
			return i;
		}
	}
	return -1;
}

/* 题干：
编写函数strrindex(s, t)，它返回字符串t在s中最右边出现的位置。
如果s中不包含t，则返回-1。
*/