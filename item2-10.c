#include <stdio.h>

main2_10()
{
	int c;
	/*char a[] = "AAaaa";
	printf("%s\n", a[1]);*/

	while ((c = getchar()) != EOF)
		printf("%s\n", lower2(c));
}

int lower1(int c)  // int c实际上是将输入参数转换为int 类型
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
	{
		return c;
	}
}

int lower2(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

/* 重写将大写字母转换为小写字母的函数 lower ，并用条件表达式替代其中的if-else结构 */