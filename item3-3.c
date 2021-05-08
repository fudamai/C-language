#include <ctype.h>
#include <stdio.h>

main3_3()
{
	char str1[] = "0-9qqq-A-f-";
	char str2[1000];
	expand01(str1, str2);

	printf("%s\n", str2);
}

/* 把字符串s1填充到s2
填充时会把大写字母格式化为小写
*/
expand(char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;

	while ((c = s1[i]) != '\0')
	{
		if (s1[i] == '-' && i >= 1 && i <= strlen(s1)-1 && isalnum(s1[i-1]) && isalnum(s1[i + 1])) {
			char upstr = lower2(s1[i - 1]);  // 返回值是整型。将大写字母转为小写
			char downstr = lower2(s1[i + 1]);
			int num = downstr - upstr;

			if (isalpha(s1[i - 1]) && isalpha(s1[i + 1])) {  // 判断是否是字母
				if (upstr < downstr) {
					// 执行填充，统一填充为小写字母
					int x;
					for (x = 0; x <= num; x++) {
						s2[j++] = upstr++;  // 自增值一定要是单独的变量
					}
					i += 2;
				}
			}
			else if (isdigit(s1[i - 1]) && isdigit(s1[i + 1])) {  // 判断是否是数字
			if (upstr < downstr) {
				// 填充字符
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
	s2[j] = '\0';  // 结束符很重要
}

/* 把字符串s1填充到s2
相对expand函数消除了填充时位重叠问题
消除连接符"-"前大后小无法跳过的问题
*/
expand01(char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;

	while ((c = s1[i]) != '\0')
	{
		char upstr = lower2(s1[i]);  // 返回值是整型。将大写字母转为小写
		char downstr = lower2(s1[i + 2]);
		int num = downstr - upstr;

		if (s1[i+1] == '-' && isalnum(s1[i]) && isalnum(s1[i + 2]) && num > 0) {

			if (isalpha(s1[i]) && isalpha(s1[i + 2])) {  // 判断是否是字母
				// 执行填充，统一填充为小写字母
				int x;
				for (x = 0; x <= num; x++) {
					s2[j++] = upstr++;  // 自增值一定要是单独的变量
				}
				i += 3;
			}
			else if (isdigit(s1[i]) && isdigit(s1[i + 2])) {  // 判断是否是数字
				// 填充字符
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
	s2[j] = '\0';  // 结束符很重要
}

/* 课本给的答案 */
expand_sap(char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-' && s1[i + 1] >= c) {  // 判断时i以完成自增1，也就是说c = s1[0]，s1[1]
			i++;
			while (c < s1[i])
				s2[j++] = c++;  // c是单个字符，可以自增。为什么
		}
		else
			s2[j++] = c;
	s2[j] = '\0';
}