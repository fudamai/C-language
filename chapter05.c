#include <stdio.h>
#include <string.h>

void swap(int, int);
void swap01(int, int);
void strcpy05_1(char, char);
void strcpy05_2(char, char);
void strcpy05_3(char , char);

main05()
{
	int x = 1, y = 2, z[10];
	int *ip;
	char s[11] = "abcdefghli", s2[11];

	ip = &x;
	ip += 1;
	y = *ip;
	*ip = 0;
	//ip = &z[0];
	ip = &*(z + 0);
	ip = s[0];  // 指针只能用来保存地址

	char a = 'a', b = 'b';
	/*swap(a, b);*/
	swap01(&a, &b);

	printf("%d\n", strlen("pla"));
	printf("%d\n", strlen05_2("pla"));
	printf("%d\n", strlen(s));
	printf("%d\n", strlen05_2(s));

	//strcpy05_1(s2, s);
	//strcpy05_2(s2, s);
	strcpy05_3(s2, s);
}

void swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void swap01(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

/* strlen函数：返回字符串s的长度 */
int strlen05_1(char *s)  // 数组名所代表的就是该数组最开始的一个元素的地址
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

/* strlen函数：返回字符串s的长度
使用指针运算得到长度
*/
int strlen05_2(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p -  s;
}

/* strcpy函数：将指针t指向的字符串复制到指针s指向的位置。使用数组下标实现的版本 */
void strcpy05_1(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

/* strcpy函数：将指针t指向的字符串复制到指针s指向的位置。使用指针方式实现的版本 */
void strcpy05_2(char* s, char* t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

/* strcpy函数：将指针t指向的字符串复制到指针s指向的位置；使用指针方式实现的版本2 */
void strcpy05_3(char* s, char* t)
{
	while ((*s++ = *t++) != '\0')
		;
}
