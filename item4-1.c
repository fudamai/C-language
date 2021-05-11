#include <stdio.h>
#include <ctype.h>
#include <string.h>

int strindex_char(char s[], char t);

main4_1()
{
	char str1[] = "abcdefghijklmn";
	char a[] = "i";

	printf("%d\n", strindex_rev(str1, a));
}

/* 返回字符串t 在 s 中最右边出现的位置 */
int strindex_rev(char s[], char t[])
{
	int i, j, k, ls, lt;

	ls = strlen(s);
	lt = strlen(t);
	for (i = ls - 1; i >= 0; i--) {  // 倒序查找
		//for (j = i, k = lt - 1; k >= 0 && s[j] == t[k]; j--, k--)  // if在循环外判断，节省资源，但k会多减一次
		//	;
		//if (k == -1)  // k为-1，说明所有t中字符都进行了判断，且与s中相同
		//	return i;
		for (j = i, k = lt - 1; k >= 0 && s[j] == t[k]; j--, k--)  // if在循环内判断
			if (k == 0)
				return i;
		;
	}
	return -1;
}

/* 返回字符在 s 中出现的位置 */
int strindex_char(char s[], char t)
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