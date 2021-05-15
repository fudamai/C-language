#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 1000

struct tnode {  // 树的节点
	char* word;  // 指向单词的指针
	int count;  // 单词出现的次数
	struct tnode* left;  // 左子节点
	struct tnode* right; // 右子节点
};

struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char*, int);

/* 单词出现的频率 */
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

/* addtree函数：在p的位置或下方增加一个w节点 */
struct tnode* addtree(struct tnode* p, char* w)
{
	int cond;

	if (p == NULL) {  // 该单词是一个新单词
		p = talloc();  // 创建一个新节点
		p->word = _strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;  // 新单词与节点中的单词匹配
	else if (cond < 0)  // 如果小于该节点中的单词，则进入左子树
		p->left = addtree(p->left, w);
	else  // 如果大于该节点中的单词，则进入右子树
		p->right = addtree(p->right, w);
	return p;  // 返回指向新节点的指针
}

/* treeprint函数：按序打印树p */
void treeprint(struct tnode* p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* talloc函数：创建一个tnode */
struct tnode* talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}

/* 复制s到某个位置 */
char* _strdup(char* s)
{
	char* p;

	p = (char*)malloc(strlen(s) + 1);  // 执行加1操作是为了在结尾加上字符'\0'
	if (p != NULL)
		strcpy_s(p, strlen(s)+1, s);  // 报错：用于调用的参数太少。strcpy_s要三个参数
	return p;
}