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

	for (i = 0; s2[i] != '\0'; i++)  // ��������s1��λ����s1��ÿһλ����s2��ȫ��λ���бȽ�
	{
		for (j = 0; s1[j] != '\0'; j++)
			if (s2[i] == s1[j])
				return j;
		return -1;
	}
}