main3_1()
{
	int list[100];
	int i;
	for (i = 0; i < 10; i++)
		list[i] = i;
	printf("%d\n", binsearch3_1(9, list, 10));
}

/* 在一个递增数组中查找x */
int binsearch3_1(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid])
	{
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == v[mid])
		return mid;
	else
		return -1;
}