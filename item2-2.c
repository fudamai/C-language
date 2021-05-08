#include <stdio.h>


rebuild_for()
{
	int lim;
	int i;
	int c;
	char s[10];
	lim = 10;

	/*for (i = 0; i <= lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;*/

	enum loop {NO, YES};
	enum loop okloop = YES;

	i = 0;
	while (okloop == YES)
	{
		if (i > lim - 1)
			okloop = NO;
		else if ((c = getchar()) == '\n')
			okloop = NO;
		else if (c == EOF)
			okloop = NO;
		else
		{
			s[i] = c;
			++i;
		}
	}

	printf(s);
}

/* Ô­Óï¾ä£º
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;
*/