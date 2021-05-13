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

/* day_of_year函数：将某月某日的日期表示形式转换为某年中第几天的表示形式 */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];  // 当前月的天数加上之前月的总天数
	return day;
}

/* month_day函数：将某年中第几天的日期表示形式转换为某年某日的表示形式 */
void month_day(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;  // i，月数。 leap，平闰年

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)  // 剩余天数大于月天数，执行循环语句
		yearday -= daytab[leap][i];  // 剩余天数减去上一月天数
	*pmonth = i;  // 将指针指向的对象，值设为i
	*pday = yearday;
}

/* month_name 函数：返回第n个月份的名字 */
void *month_name(int n)  // 演示代码是char类型，无法编译
{
	static char* name[] = {  // 指针数组的初始化
		"Illegal month", "January", "February",
		"March", "April", "May", "June", "July",
		"August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}