#include <stdio.h>

ftoc_float()
{
	/* 打印华氏温度与摄氏温度对照表
	执行浮点数预算
	*/
	printf("一个华氏度与摄氏度的对照表\n\n");
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;  /*温度表的下限*/
	upper = 300;  /*温度表的上限*/
	step = 20;  /*步长*/

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);  /*格式化输出*/
		fahr = fahr + step;
	}
}

ftoc_int()
{
	printf("hello C world\n");
	printf("中文");
	printf("no enter\\ss\\n"); printf("only one line\n");

	/* 打印华氏温度与摄氏温度对照表 */
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;  /*温度表的下限*/
	upper = 300;  /*温度表的上限*/
	step = 20;  /*步长*/

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%3d %6d\n", fahr, celsius);  /*格式化输出*/
		fahr = fahr + step;
	}
}

ctof()
{
	/*打印摄氏温度与华氏温度的转换表*/
	printf("打印摄氏温度与华氏温度的转换表\n\n");
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
	/*打印温度，逆序输出*/
	printf("打印摄氏温度与华氏温度的转换表\n\n");
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