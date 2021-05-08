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

/* qsort函数：以递增顺序对v[left]...v[right]进行排序 */
void qsort(int v[], int left, int right)  // left、right是数组下标
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)  // 若数组包含的元素数少于两个
		return;  // 则不执行任何操作
	swap(v, left, (left + right) / 2);  // 将划分子集的元素移动到v[0]
	last = left;  // 将最左边的元素移动到
	for (i = left + 1; i <= right; i++) {  // 划分子集
		if (v[i] < v[left]) {  // 最左边的元素是用来判断的元素
			swap(v, ++last, i);  // 执行时last以完成加一
		}
	}
	swap(v, left, last);  // 恢复划分子集的元素，last右侧是大于等于v[left]的值
	qsort(v, left, last-1);  // 对元素左侧执行排序
	qsort(v, last+1, right);  // 对元素右侧执行排序
}

/* swap函数：交换v[i] 与 v[j]的值 */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}