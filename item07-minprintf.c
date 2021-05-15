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
	//while ((s = getchar()) != EOF) {  // getchar��õ�ֻ���ַ������ǵ�ַ
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

	/* sscanf��win32�²���ʹ�ã�ʹ��sscanf_sʱ�������� */
	while (getline(line, sizeof(line)) > 0) {
		if (sscanf_s(line, "%d %s %d", &day, monthname, &year, (rsize_t)sizeof(line)) == 3) {  // ִ�и�ʽ�ж�
			printf("valid: %s\n", line);
		}
		else if (sscanf_s(line, "%d/%d/%d", &month, &day, &year, (rsize_t)sizeof(line))) {
			printf("valid: %s\n", line);
		}
		else
			printf("invalid: %s\n", line);
	}

}

/* minprintf���������пɱ������ļ򻯵�printf���� */
void minprintf(char *fmt, ...)
{
	va_list ap;  // ����ָ��ÿ����������
	char* p, * sval;
	int ival;
	double dval;

	va_start(ap, fmt);  // ��apָ���һ����������
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
	va_end(ap);  // ����ʱ��������
}