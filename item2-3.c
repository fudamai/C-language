#include <stdio.h>

#define YES 1
#define NO 0

main2_3()
{
	int aa;

	
	aa = "0x100";
	
	printf("%d\n", htois(aa));
}

/* 将十六进制字符串转换为整型 */
int htois(char s[])
{
	int hexdigit, i, inhex, n;
	
	i = 0;
	/* 跳过可选的0x 或 0X */
	if (s[i] == '0') {
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	/* 到这里时i 为1 */

	n = 0;
	inhex = YES;
	for (; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';  // 十六进制中数字的字面值，与十进制相同
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;  // 十六进制字母距离a的长度，加上十，就是它在十进制中的字面值
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
		{
			inhex = NO;  // 不是一个有效的十六进制数字
		}
		if (inhex == YES)
			n = 16 * n + hexdigit;  // 高位字面值（转换后） * 进制（原进制） + 最低位字面值（转换后） = 有效计数
	}
	return n;
}

/*
整个函数是由下面这条语句控制的：
for ( ; inhex == YES; ++i)
其中整型变量i 是数组 s 的下标。当s[i]是一个合法的十六进制数字时，inhex的取值将
保持为YES，而循环也将继续执行。整型变量hexdigit的取值范围是0-15。
语句
if (inhex == YES)
保证数组元素s[i]是一个合法的十六进制数字字符，其值在hexdigit的范围之内。当循环
结束时，函数htoi将返回变量n的值。
这个函数与atoi很像，需要读者对字符集有了解
*/