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

/* ���ַ���s1���κ����ַ���s2���ַ�ƥ����ַ���ɾ�� */
squeeze(char s1[], char s2[])
{
	int i, j, k;

	for (i = k = 0; s1[i] != '\0'; i++)  // ��������s1��λ����s1��ÿһλ����s2��ȫ��λ���бȽ�
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')  // �ҵ���ͬλʱ��������Ϊ��
			s1[k++] = s1[i];  // ����Ϊ�٣�k���������´θ�ֵʱ�Ḳ����ͬλ
	}
	s1[k] = '\0';
}

/* squeeze�����ķ���ֵ����Ϊvoid������ʽ˵�������������κ�ֵ */