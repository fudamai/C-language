#include <ctype.h>
#include <stdio.h>

main3_3()
{
	char str1[] = "0-9qqq-A-f-";
	char str2[1000];
	expand01(str1, str2);

	printf("%s\n", str2);
}

/* ���ַ���s1��䵽s2
���ʱ��Ѵ�д��ĸ��ʽ��ΪСд
*/
expand(char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;

	while ((c = s1[i]) != '\0')
	{
		if (s1[i] == '-' && i >= 1 && i <= strlen(s1)-1 && isalnum(s1[i-1]) && isalnum(s1[i + 1])) {
			char upstr = lower2(s1[i - 1]);  // ����ֵ�����͡�����д��ĸתΪСд
			char downstr = lower2(s1[i + 1]);
			int num = downstr - upstr;

			if (isalpha(s1[i - 1]) && isalpha(s1[i + 1])) {  // �ж��Ƿ�����ĸ
				if (upstr < downstr) {
					// ִ����䣬ͳһ���ΪСд��ĸ
					int x;
					for (x = 0; x <= num; x++) {
						s2[j++] = upstr++;  // ����ֵһ��Ҫ�ǵ����ı���
					}
					i += 2;
				}
			}
			else if (isdigit(s1[i - 1]) && isdigit(s1[i + 1])) {  // �ж��Ƿ�������
			if (upstr < downstr) {
				// ����ַ�
				int x;
				for (x = 0; x <= num; x++) {
					s2[j++] = upstr++;
				}
				i += 2;
			}
			}
			
		}
		else {
			s2[j++] = c;
			i++;
		}
	}
	s2[j] = '\0';  // ����������Ҫ
}

/* ���ַ���s1��䵽s2
���expand�������������ʱλ�ص�����
�������ӷ�"-"ǰ���С�޷�����������
*/
expand01(char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;

	while ((c = s1[i]) != '\0')
	{
		char upstr = lower2(s1[i]);  // ����ֵ�����͡�����д��ĸתΪСд
		char downstr = lower2(s1[i + 2]);
		int num = downstr - upstr;

		if (s1[i+1] == '-' && isalnum(s1[i]) && isalnum(s1[i + 2]) && num > 0) {

			if (isalpha(s1[i]) && isalpha(s1[i + 2])) {  // �ж��Ƿ�����ĸ
				// ִ����䣬ͳһ���ΪСд��ĸ
				int x;
				for (x = 0; x <= num; x++) {
					s2[j++] = upstr++;  // ����ֵһ��Ҫ�ǵ����ı���
				}
				i += 3;
			}
			else if (isdigit(s1[i]) && isdigit(s1[i + 2])) {  // �ж��Ƿ�������
				// ����ַ�
				int x;	
				for (x = 0; x <= num; x++) {
					s2[j++] = upstr++;
				}
				i += 3;				
			}
		}
		else {
			s2[j++] = c;
			i++;
		}
	}
	s2[j] = '\0';  // ����������Ҫ
}

/* �α����Ĵ� */
expand_sap(char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-' && s1[i + 1] >= c) {  // �ж�ʱi���������1��Ҳ����˵c = s1[0]��s1[1]
			i++;
			while (c < s1[i])
				s2[j++] = c++;  // c�ǵ����ַ�������������Ϊʲô
		}
		else
			s2[j++] = c;
	s2[j] = '\0';
}