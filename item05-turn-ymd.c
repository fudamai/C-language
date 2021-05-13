#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);
void *month_name(int n);

main05_turn_ymd()
{
	int days = 99;

	int re[2];
	month_day(2019, days, &re[0], &re[1]);
	printf("%d,%d\n", re[0], re[1]);

	printf("%s\n", month_name(5));
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31,30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year��������ĳ��ĳ�յ����ڱ�ʾ��ʽת��Ϊĳ���еڼ���ı�ʾ��ʽ */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];  // ��ǰ�µ���������֮ǰ�µ�������
	return day;
}

/* month_day��������ĳ���еڼ�������ڱ�ʾ��ʽת��Ϊĳ��ĳ�յı�ʾ��ʽ */
void month_day(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;  // i�������� leap��ƽ����

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)  // ʣ������������������ִ��ѭ�����
		yearday -= daytab[leap][i];  // ʣ��������ȥ��һ������
	*pmonth = i;  // ��ָ��ָ��Ķ���ֵ��Ϊi
	*pday = yearday;
}

/* month_name ���������ص�n���·ݵ����� */
void *month_name(int n)  // ��ʾ������char���ͣ��޷�����
{
	static char* name[] = {  // ָ������ĳ�ʼ��
		"Illegal month", "January", "February",
		"March", "April", "May", "June", "July",
		"August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}