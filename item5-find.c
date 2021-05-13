#include <stdio.h>
#include <string.h>

/* 回显程序命令行参数：版本1 */
main05_cmd(int argc, char* argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
	return 0;
}

/* 在DEBUG目录找到exe文件，使用命令行执行exe文件时可以输入后缀
在调试属性中也可配置命令参数
*/

#define MAXLINE 1000

int getline(char* line, int max);

/* find函数：打印与第一个参数指定的模式匹配的行 */
main05_cmd_pattern(int argc, char* argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (getline(line, MAXLINE) > 0)
		{
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
		}
	return found;
}

/* find函数：打印与第一个参数指定的模式匹配的行
增加可选参数
*/
main05_find(int argc, char* argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int found = 0, number = 0, except = 0, c;

	while (--argc > 0 && (*++argv)[0] == '-') {  // 对argc进行自减，argv进行自增。默认argv[0]指向程序名。argv是指针数组
		while (c = *++argv[0]) {  // *++argv[0] = *++(argv[0]) 取零位指针对象，取下一个对象的指针，取出对象
			switch (c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
		}
	}

	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (getline(line, MAXLINE) > 0)
		{
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}