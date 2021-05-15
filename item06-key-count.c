#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))  // 这里应该是3

int getword(char *, int);
//int binsearch(char*, struct key*, int);
struct key *binsearch(char *, struct key *, int);

struct key {
	char* word;
	int count;
} keytab[] = {
"auto", 0, "break", 0, "case", 0
};


/* 统计输入中C语言关键字的出现次数；采用指针方式实现的版本 */
main06_k_c_p()
{
	char word[MAXWORD];
	struct key *p;

	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
			if ((p = binsearch(word, keytab, NKEYS)) != NULL)
				p->count++;
	}
	for (p = keytab; p < keytab + NKEYS; p++)  // 对地址进行循环判断
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}

/* binsearch函数：在tab[0]...tab[n-1]中查找与读入单词匹配的元素 */
struct key *binsearch(char *word, struct key *tab, int n)  // 声明内容：函数返回值的类型，参数的类型。涉及到类型转换
{
	int cond;
	struct key* low = &tab[0];
	struct key* high = &tab[n];
	struct key* mid;


	while (low < high) {
		mid = low + (high - low) / 2;  // 取中位元素指针。得到指针间距，除以2
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

/* 统计输入中C语言关键字的出现次数 */
//main06_k_c()
//{
//	int n;
//	char word[MAXWORD];
//
//	while (getword(word, MAXWORD) != EOF)
//	{
//		if (isalpha(word[0]))
//			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
//				keytab[n].count++;
//	}
//	for (n = 0; n < NKEYS; n++)
//		printf("%4d %s\n", keytab[n].count, keytab[n].word);
//	return 0;
//}

/* binsearch函数：在tab[0]到tab[n-1]中查找单词
只能在递增序列中实现查找
*/
//int binsearch(char* word, struct key tab[], int n)
//{
//	int cond;
//	int low, high, mid;
//
//	low = 0;
//	high = n - 1;
//	while (low <= high) {
//		mid = (low + high) / 2;
//		if ((cond = strcmp(word, tab[mid].word)) < 0)
//			high = mid - 1;
//		else if (cond > 0)
//			low = mid + 1;
//		else
//			return mid;
//	}
//	return -1;
//}

/* getword函数：从输入中读取下一个单词或字符 */
int getword(char* word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char* w = word;

	while (isspace(c = getch()))
	{
		;
	}
	if (c != EOF) {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {  // 保存数据在此进行
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
}