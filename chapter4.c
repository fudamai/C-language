#include <stdio.h>
#include <ctype.h>

void printd(int n);
void qsort(int v[], int left, int right);

main()
{
	int days[] = { 1, 1, 3, 9, 2, 3, 4 };
	char pattern[] = "ooll";
	int num1 = 123;

	printf("%d\n", pattern[3]);
	printf("%d\n", num1);

	qsort(days, 0, 6);
	printf("%d\n", days[6]);
}

void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

/* qsort�������Ե���˳���v[left]...v[right]�������� */
void qsort(int v[], int left, int right)  // left��right�������±�
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)  // �����������Ԫ������������
		return;  // ��ִ���κβ���
	swap(v, left, (left + right) / 2);  // �������Ӽ���Ԫ���ƶ���v[0]
	last = left;  // ������ߵ�Ԫ���ƶ���
	for (i = left + 1; i <= right; i++) {  // �����Ӽ�
		if (v[i] < v[left]) {  // ����ߵ�Ԫ���������жϵ�Ԫ��
			swap(v, ++last, i);  // ִ��ʱlast����ɼ�һ
		}
	}
	swap(v, left, last);  // �ָ������Ӽ���Ԫ�أ�last�Ҳ��Ǵ��ڵ���v[left]��ֵ
	qsort(v, left, last-1);  // ��Ԫ�����ִ������
	qsort(v, last+1, right);  // ��Ԫ���Ҳ�ִ������
}

/* swap����������v[i] �� v[j]��ֵ */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}