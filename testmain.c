#include "pushswap.h"
#include <stdio.h>
int main(void)
{
	t_pscell	**ablist;
	uintmax_t	size;
	uintmax_t	counter;
	unsigned long long pslsize;

	counter = 0;
	size = 1024;
	ablist = (t_pscell**)ft_memalloc(sizeof(t_pscell*) * 2);
	ablist[0] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * size);
	ablist[1] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * size);
	ablist[0][0].list = 'a';
	ablist[0][0].value = 12;
	ablist[0][0].current = 0;
	ablist[0][0].next = ablist[0] + 1;
	ablist[0][1].list = 'a';
	ablist[0][1].value = 15;
	ablist[0][1].current = 1;
	ablist[0][1].next = ablist[0] + 2;
	ablist[0][2].list = 'a';
	ablist[0][2].value = 17;
	ablist[0][2].current = 2;
	ablist[0][2].next = ablist[0] + 3;
	ablist[0][3].list = 'a';
	ablist[0][3].value = 19;
	ablist[0][3].current = 3;
	ablist[0][3].next = ablist[0] + 4;
	ablist[0][4].list = 'a';
	ablist[0][4].value = 21;
	ablist[0][4].current = 4;
	ablist[0][4].next = ablist[0];
	pslsize = ft_pslsize(ablist[0]);
	printf("size of list is %llu\n", pslsize);
	while (counter < pslsize)
	{
		printf("value is %jd, \ncurrent is %ju, \nnext is %p.\n", ablist[0][counter].value, ablist[0][counter].current, ablist[0][counter].next);
		++counter;
	}
	counter = 0;
//	ft_shift_down(ablist, 'a', pslsize);
	ft_revrotate_a(ablist, pslsize);
	while (counter < pslsize)
	{
		printf("value is %jd, \ncurrent is %ju, \nnext is %p.\n", ablist[0][counter].value, ablist[0][counter].current, ablist[0][counter].next);
		++counter;
	}
}
