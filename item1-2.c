#include <stdio.h>

ftoc_float()
{
	/* ��ӡ�����¶��������¶ȶ��ձ�
	ִ�и�����Ԥ��
	*/
	printf("һ�����϶������϶ȵĶ��ձ�\n\n");
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;  /*�¶ȱ������*/
	upper = 300;  /*�¶ȱ������*/
	step = 20;  /*����*/

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);  /*��ʽ�����*/
		fahr = fahr + step;
	}
}

ftoc_int()
{
	printf("hello C world\n");
	printf("����");
	printf("no enter\\ss\\n"); printf("only one line\n");

	/* ��ӡ�����¶��������¶ȶ��ձ� */
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;  /*�¶ȱ������*/
	upper = 300;  /*�¶ȱ������*/
	step = 20;  /*����*/

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%3d %6d\n", fahr, celsius);  /*��ʽ�����*/
		fahr = fahr + step;
	}
}

ctof()
{
	/*��ӡ�����¶��뻪���¶ȵ�ת����*/
	printf("��ӡ�����¶��뻪���¶ȵ�ת����\n\n");
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 500;
	step = 20;

	celsius = lower;
	while (celsius <= upper) {
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

ctof_rever()
{
	/*��ӡ�¶ȣ��������*/
	printf("��ӡ�����¶��뻪���¶ȵ�ת����\n\n");
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 500;
	step = 20;

	for (celsius = 500; celsius >= 0; celsius = celsius - 20)
	{
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
	}
}