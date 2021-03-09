#include "ft_printf.h"

static void	ft_print_hex(va_list arg, t_specs *specs, int *print, char *base)
{
	char			*s;
	unsigned int	nbr;
	int 			len;

	nbr = va_arg(arg, unsigned int);
	s = ft_itoa_base(nbr, base);
	len = (nbr == 0 && specs->precis == 0 ? 0 : ft_strlen(s));
	(*print) += len;
	if (!specs->minus && (specs->zero && specs->precis == -1))
		(*print) += fill('0', specs->width - len);
	if (!specs->minus && !(specs->zero && specs->precis == -1))
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	if (specs->precis != -1)
		(*print) += fill('0', specs->precis - len);
	if (!(nbr == 0 && specs->precis == 0))
		write(1, s, len);
	if (specs->minus)
		(*print) += fill(' ', specs->width - (specs->precis != -1 ?
		max(specs->precis, len) : len));
	free(s);
}

void		ft_print_hex_low(va_list arg, t_specs *specs, int *print)
{
	ft_print_hex(arg, specs, print, "0123456789abcdef");
}

void		ft_print_hex_up(va_list arg, t_specs *specs, int *print)
{
	ft_print_hex(arg, specs, print, "0123456789ABCDEF");
}

void		ft_print_ptr(va_list arg, t_specs *specs, int *print)
{
	char					*s;
	unsigned long long int	nbr;
	int						len;

	nbr = va_arg(arg, unsigned long long int);
	s = ft_itoa_base(nbr, "0123456789abcdef");
	specs->width -= 2;
	len = ((nbr == 0 && specs->precis == 0) ? 0 : ft_strlen(s));
	(*print) += len + 2;
	if (!specs->minus && specs->zero)
		write(1, "0x", 2);
	if (!(specs->minus) && (specs->zero && specs->precis == -1))
		(*print) += fill('0', specs->width - len);
	if (!(specs->minus) && !(specs->zero && specs->precis == -1))
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	if (!specs->zero)
		write(1, "0x", 2);
	if (specs->precis != -1)
		(*print) += fill('0', specs->precis - len);
	if (!(nbr == 0 && specs->precis == 0))
		write(1, s, len);
	if (specs->minus)
		(*print) += fill(' ', specs->width - (specs->precis != -1 ?
		max(specs->precis, len) : len));
	free(s);
}
