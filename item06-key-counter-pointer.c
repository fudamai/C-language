#include <stdio.h>
#include <ctype.h>
#include <string.h>

//#define MAXWORD 100
//#define NKEYS (sizeof keytab / sizeof(struct key))  // ����Ӧ����3
//
//int getword(char*, int);
//struct key *binsearch(char*, struct key*, int);
//
//struct key {
//	char* word;
//	int count;
//} keytab[] = {
//"auto", 0, "break", 0, "case", 0
//};
//
///* ͳ��������C���Թؼ��ֵĳ��ִ���������ָ�뷽ʽʵ�ֵİ汾 */
//main()
//{
//	char word[MAXWORD];
//	struct key *p;
//
//	while (getword(word, MAXWORD) != EOF)
//	{
//		if (isalpha(word[0]))
//			if ((p = binsearch(word, keytab, NKEYS)) != NULL)
//				p->count++;
//	}
//	for (p = 0; p < keytab + NKEYS; p++)
//		if (p->count > 0)
//			printf("%4d %s\n", p->count, p->word);
//	return 0;
//}
//
///* binsearch��������tab[0]...tab[n-1]�в�������뵥��ƥ���Ԫ�� */
//struct key *binsearch(char *word, struct key *tab, int n)
//{
//	int cond;
//	struct key *low = &tab[0];
//	struct key *high = &tab[n];
//	struct key *mid;
//
//	
//	while (low < high) {
//		mid = low + (high - low) / 2;  // ȡ��λԪ��ָ��
//		if ((cond = strcmp(word, mid->word)) < 0)
//			high = mid;
//		else if (cond > 0)
//			low = mid + 1;
//		else
//			return mid;
//	}
//	return NULL;
//}