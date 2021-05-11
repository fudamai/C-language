#include <stdio.h>
#include <string.h>
/* 连续赋值时，赋值表达式的值是 */
//while (isdigit(s[++i] = c = getch()))  // 这里会进行两个赋值操作
//			;

int __cdecl strcmp(
	_In_z_ char const* _Str1,
	_In_z_ char const* _Str2
) {
	return 0;
}

main()
{
	register int x;
	register char c;

	int i = 0, a = 1;
	char s[100];

	int d;
	int e;
	d = e = 2;

	s[0] = 0;

	d = strcmp("abc", "dcb");
	while (s[++i] = a = getchar()) {  // 连续赋值时，从右往左执行
		printf("%dok", a);
	}
}