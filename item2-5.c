main2_5()
{
	int ch1, ch2;
	ch1 = "animal";
	ch2 = "l";

	printf("%d\n", any(ch1, ch2));
}

int any (char s1[], char s2[])
{
	int i, j;

	for (i = 0; s2[i] != '\0'; i++)  // 迭代所有s1的位，让s1的每一位都与s2的全部位进行比较
	{
		for (j = 0; s1[j] != '\0'; j++)
			if (s2[i] == s1[j])
				return j;
		return -1;
	}
}