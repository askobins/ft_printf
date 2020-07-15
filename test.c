#include <stdio.h>
#include "inc/libftprintf.h"

int main(void)
{
	int reta, retb;
	puts("me:");
	reta = ft_printf("%32x\n%32d\n", 0, 0);
	puts("them:");
	retb = printf("%32x\n%32d\n", 0, 0);
	printf("me:   %d\nthem: %d\n", reta, retb);
}
