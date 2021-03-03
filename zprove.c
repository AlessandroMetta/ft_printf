#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("ciao %10.4d\n", 100);
	printf("ciao %10.4d", 100);
	return (0);
}
