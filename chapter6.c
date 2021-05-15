#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define XMAX 400
#define YMAX 400
#define NSYM 100

struct point
{
	int x;
	int y;
};

struct rect
{
	struct point pt1;
	struct point pt2;
};

//struct key {
//	char* word;
//	int count;
//} keytab[] = {
//"word", 0, "break", 0, "case", 0
//};

main06()
{
	struct point pt = { 20, 10 };

	struct point maxpt = { 320, 200 };
	printf("%d, %d\n", maxpt.x, maxpt.y);

	double dist, sqrt(double);
	dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
	printf("%f\n", dist);

	struct rect screen = { {1,1}, {4,4} };

	
	struct point middle;
	struct point makepoint(int, int);
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(XMAX, XMAX);
	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y));
	
	//struct point po3;
	//po3 = canonrect(screen);  // ����ʱ�����ض������

	struct point origin = { 1, 2 }, * pp;

	pp = &origin;
	printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
	printf("origin is (%d, %d)\n", pp->x, (*pp).y);

	int a = "a";

	struct { int len; char *str; } *p = { 1, };


	/* ���Ͷ��� typedef */
	typedef int Length;

	Length len, maxlen;
	len = maxlen = 99;

	printf("%d %d\n", len, maxlen);

	/* ���� */
	union u_tag {
		int ival;
		float fval;
		char* sval;
	} u;
	u.fval;

	struct {
		char* name;
		int flags;
		int utypes;
		union 
		{
			int ival;
			float fval;
			char* sval;
		} u;
	} symtab[NSYM];
}

/* makepoint������ͨ��x��y���깹��һ���� */
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint����������������� */
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* ptinrect�����������p�ھ����ڣ��򷵻�1�����򷵻�0 */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x&& p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect����������������淶�� */
struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.x = min(r.pt1.y, r.pt2.y);
	temp.pt1.x = max(r.pt1.x, r.pt2.x);
	temp.pt1.x = max(r.pt1.y, r.pt2.y);
	return temp;
}