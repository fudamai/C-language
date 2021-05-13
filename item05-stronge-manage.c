#define ALLOCSIZE 10000  // ���ÿռ��С

static char allocbuf[ALLOCSIZE];  // allocʹ�õĴ洢��
static char *allocp = allocbuf;  // ��һ������λ��

char *alloc(int n)  // ����ָ��n���ַ���ָ��
{  // ��ʼ��ַ + �ܴ�С = ��Զ���õ�ַ ����Զ���� - ���õ�ַ = ʣ��ռ��С
	if (allocbuf + ALLOCSIZE - allocp >= n) {  // ���㹻�Ŀ���ʱ��
		allocp += n;
		return allocp - n;  // ����ǰ��ָ��p
	}
	else {  // ���пռ䲻��
		return 0;
	}
}

void afree(char *p)  // �ͷ�pָ��Ĵ洢��
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}