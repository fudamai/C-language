#include <stdio.h>
#include <string.h>

/* ���Գ��������в������汾1 */
main05_cmd(int argc, char* argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
	return 0;
}

/* ��DEBUGĿ¼�ҵ�exe�ļ���ʹ��������ִ��exe�ļ�ʱ���������׺
�ڵ���������Ҳ�������������
*/

#define MAXLINE 1000

int getline(char* line, int max);

/* find��������ӡ���һ������ָ����ģʽƥ����� */
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

/* find��������ӡ���һ������ָ����ģʽƥ�����
���ӿ�ѡ����
*/
main05_find(int argc, char* argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int found = 0, number = 0, except = 0, c;

	while (--argc > 0 && (*++argv)[0] == '-') {  // ��argc�����Լ���argv����������Ĭ��argv[0]ָ���������argv��ָ������
		while (c = *++argv[0]) {  // *++argv[0] = *++(argv[0]) ȡ��λָ�����ȡ��һ�������ָ�룬ȡ������
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