#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* �򵥼��������� */
main4_2()
{
	double sum, atof_d_4_2(char[]);
	char line[MAXLINE];
	int getline4_2(char line[], int max);

	sum = 0;
	while (getline4_2(line, MAXLINE) > 0)
		//printf("\t%g\n", sum += atof_d_4_2(line));
		printf("\t%g\n", atof_d_4_2(line));
	return 0;


}

/* atof���������ַ���sת��Ϊ��Ӧ��˫���ȸ����� */
double atof_d_4_2(char s[])
{
	double val, power;
	int i, sign, esign;
	int powernum = 0;


	esign = 1;
	power = 1.0;
	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');  // valֻͳ����Чλ��ֵ
		power *= 10.0;  // С�����ÿ��һλ��power��һ��ʮ
	}

	/* �����ѧ������ */
	if (s[i] == 'e') {
		i++;
	}
	/* ͳ���ݵĴ�С������ */
	while (s[i] != EOF && s[i] != '\n') {
		switch (s[i]) {
		case '-':
			esign = 0;
			break;
		case '+':
			esign = 1;
			break;
		default:
			powernum = 10 * powernum + (s[i] - '0');
			break;
		}
		i++;
	}
	/* �ϲ���λ */
	if (esign) {
		for (int n = 1; n <= powernum; n++) {  // ��'0'�����ַ���תΪ����
					
			power /= 10.0;  // û�и��ţ�С����ǰ�ơ�����ʱ�ٳ�һ�Σ�С�������
		}
	}
	else
	{
		for (int n = 1; n <= powernum; n++) {
			power *= 10.0;  // �и��ţ�С������ơ�����ʱ�ٳ�һ�Σ�С����ǰ��
		}
	}
	return sign * val / power;  // ��Чֵ����С�������λ����������
}


/* getline���������б��浽s�У������ظ��еĳ��� */
int getline4_2(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')  // �����˳���
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* ��ɣ�
����atof������ʹ֮�ܴ����ѧ��������ʾ�����֡�
�ַ��� 123.45e-6 ת�� ������ 0.00012345.
*/