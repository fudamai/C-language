#include <stdarg.h>
#include <stdio.h>

void minprintf(char* fmt, ...);

main07_m()
{
	int a = 13;

	minprintf("%d", a);

	/* scanf */
	double sum, v;
	char c;
	char *s;
	//while ((s = getchar()) != EOF) {  // getchar获得的只是字符，不是地址
	//	/*putchar(c, "\n");*/
	//	/*s = &c;*/
	//	printf("%p\n", s);
	//}
		

	/*sum = 0;
	while (scanf_s("%lf", &v) == 1) {
		printf("\t%.2f\n", sum += v);
	}
	return 0;*/

	unsigned int day, year, month;
	char monthname[20];
	char line[1000];

	/* sscanf在win32下不能使用，使用sscanf_s时参数不对 */
	while (getline(line, sizeof(line)) > 0) {
		if (sscanf_s(line, "%d %s %d", &day, monthname, &year, (rsize_t)sizeof(line)) == 3) {  // 执行格式判断
			printf("valid: %s\n", line);
		}
		else if (sscanf_s(line, "%d/%d/%d", &month, &day, &year, (rsize_t)sizeof(line))) {
			printf("valid: %s\n", line);
		}
		else
			printf("invalid: %s\n", line);
	}

}

/* minprintf函数：带有可变参数表的简化的printf函数 */
void minprintf(char *fmt, ...)
{
	va_list ap;  // 依次指向每个无名参数
	char* p, * sval;
	int ival;
	double dval;

	va_start(ap, fmt);  // 将ap指向第一个无名参数
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char*); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);  // 结束时的清理工作
}