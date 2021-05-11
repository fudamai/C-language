#define BUFSIZE 100

char buf4_8 = '0';  // 用于ungetch函数的缓冲区
int bufp4_8 = 0;  // buf中下一个空闲位置

int getch4_8(void)  // 取一个字符（可能是压回的字符）
{
	return (bufp4_8 > 0) ? buf4_8 : getchar();
	/* 缓冲区读取后要恢复 */
	int c;
	
	if (buf4_8 != '0') {
		c = buf4_8;
		buf4_8 = '0';
	}
	else {
		c = getchar();
	}
	return c;
}

void ungetch(int c)  // 把字符压回输入中
{
	if (buf4_8 != '0')
		printf("ungetch: too many characters\n");
	else
		buf4_8 = c;
}

/* 
题干：假定最多只压回一个字符。请相应修改getch与ungetch这两个函数
*/