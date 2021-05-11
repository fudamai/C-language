#include <string.h>
#include <stdio.h>

main4_7()
{
	char str7[] = "adcf";
	printf("%d\n", strlen(str7));
}

void ungets(char s[])
{
	int i = strlen(s);  // 这里调用的strlen是item2-4中自己定义的函数
	void ungetch(int);

	while (i > 0) {
		ungetch(s[--i]);
	}
}

/*
题干：编写一个函数ungets(s)，将整个字符串s压回到输入中。ungets函数需要使用buf和bufp吗？他能否仅使用ungetch函数
*/