#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 1000

struct tnode {  // ���Ľڵ�
	char* word;  // ָ�򵥴ʵ�ָ��
	int count;  // ���ʳ��ֵĴ���
	struct tnode* left;  // ���ӽڵ�
	struct tnode* right; // ���ӽڵ�
};

struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char*, int);

/* ���ʳ��ֵ�Ƶ�� */
main06_w_c()
{
	struct tnode* root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	treeprint(root);
	return 0;
}

struct tnode* talloc(void);
char* _strdup(char*);

/* addtree��������p��λ�û��·�����һ��w�ڵ� */
struct tnode* addtree(struct tnode* p, char* w)
{
	int cond;

	if (p == NULL) {  // �õ�����һ���µ���
		p = talloc();  // ����һ���½ڵ�
		p->word = _strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;  // �µ�����ڵ��еĵ���ƥ��
	else if (cond < 0)  // ���С�ڸýڵ��еĵ��ʣ������������
		p->left = addtree(p->left, w);
	else  // ������ڸýڵ��еĵ��ʣ������������
		p->right = addtree(p->right, w);
	return p;  // ����ָ���½ڵ��ָ��
}

/* treeprint�����������ӡ��p */
void treeprint(struct tnode* p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* talloc����������һ��tnode */
struct tnode* talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}

/* ����s��ĳ��λ�� */
char* _strdup(char* s)
{
	char* p;

	p = (char*)malloc(strlen(s) + 1);  // ִ�м�1������Ϊ���ڽ�β�����ַ�'\0'
	if (p != NULL)
		strcpy_s(p, strlen(s)+1, s);  // �������ڵ��õĲ���̫�١�strcpy_sҪ��������
	return p;
}