#include <stdarg.h>

void	ft_putchar(char c);

void	ft_putnbr(int n);

void	ft_putnumbase(int nbr, int base, int ESA);

void    ft_putadd(int nbr);

int	ft_printf(const char *input, ...)
{
	va_list arg;
	int counter = 0;
	char *sval;

	va_start(arg, input);
	while (*input)
	{
		if (*input != '%')
			ft_putchar(*input);
		else if (*++input == 'd' || *input == 'i')
			ft_putnbr(va_arg(arg, int));
//		else if (*input == 'u')
			//
		else if (*input == 'o')
			ft_putnumbase(va_arg(arg, int), 8, 0);
		else if (*input == 'x')
			ft_putnumbase(va_arg(arg, int), 16, 0);
		else if (*input == 'X')
			ft_putnumbase(va_arg(arg, int), 16, 1);
		else if (*input == 'c')
			ft_putchar(va_arg(arg, int));
		else if (*input == 'p')
			ft_putadd(va_arg(arg, int));
		else if (*input == 's')
		{
			sval = va_arg(arg, char *);
			while(*sval)
				ft_putchar(*sval++);
		}
		else if (*input == '%')
			ft_putchar('%');
		// else
			// ERRORE
		input++;
		counter++;
	}
	va_end(arg);
	return (counter);
}
