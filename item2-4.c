#include <stdio.h>

main2_4()
{
	int i;
	char ch1, ch2;
	ch1 = " animal";
	ch2 = "mall";

	squeeze(ch1, ch2);
	
	printf("hello");
	printf("%d",strlen(ch1));
	
}


int strlen(char s[])
{
	int i;
	i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return i;
}

/* 将字符串s1中任何与字符串s2中字符匹配的字符都删除 */
squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = k = 0; s1[i] != '\0'; i++)  // 迭代所有s1的位，让s1的每一位都与s2的全部位进行比较
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')  // 找到相同位时，此条件为假
			s1[k++] = s1[i];  // 条件为假，k不自增。下次赋值时会覆盖相同位
	}
	s1[k] = '\0';
}

/* squeeze函数的返回值类型为void，它显式说明函数不返回任何值 */