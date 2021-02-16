#include <stdio.h>

int ft_printf(const char *, ...);

int main()
{
	int a=10;
	int *str = &a;
//	ft_printf("your %%d:   %d   |   ", str);
//	ft_printf("your %%x:  \"%x\"\n", str);
	ft_printf("your %%p:  \"%p\"\n", str);
//	printf("orig %%d:   %ld   ||   ", str);
	printf("orig %%x:   %x -- ", str);
//	printf("orig %%lx:   %lx -- ", str);
//	printf("orig %%lu:   %lu || 	", str);
//	printf("orig %%p:   %p\n", str);

//	int b=-1;
//	ft_printf("your %%u:   %u   |   ", b);
//	printf("orig %%u:   %u\n", b);
}
