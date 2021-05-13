#define ALLOCSIZE 10000  // 空用空间大小

static char allocbuf[ALLOCSIZE];  // alloc使用的存储区
static char *allocp = allocbuf;  // 下一个空闲位置

char *alloc(int n)  // 返回指向n个字符的指针
{  // 初始地址 + 总大小 = 最远可用地址 ，最远可用 - 已用地址 = 剩余空间大小
	if (allocbuf + ALLOCSIZE - allocp >= n) {  // 有足够的空闲时间
		allocp += n;
		return allocp - n;  // 分配前的指针p
	}
	else {  // 空闲空间不够
		return 0;
	}
}

void afree(char *p)  // 释放p指向的存储区
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}