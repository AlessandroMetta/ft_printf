/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csuid_prc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:09:30 by ametta            #+#    #+#             */
/*   Updated: 2021/03/09 16:09:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_chr(va_list arg, t_specs *specs, int *printed)
{
	char	chr;
	int		i;

	i = 0;
	chr = va_arg(arg, int);
	if (specs->minus)
		write(1, &chr, 1);
	while (i < specs->width - 1)
	{
		write(1, " ", 1);
		i++;
		(*printed)++;
	}
	if (!specs->minus)
		write(1, &chr, 1);
	(*printed)++;
}

void	ft_print_str(va_list arg, t_specs *specs, int *printed)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (specs->minus)
		write(1, str, ((specs->precis >= 0) ? min(specs->precis, len) : len));
	if (specs->width > ((specs->precis >= 0) ? min(specs->precis, len) : len))
		while (i < specs->width - (specs->precis >= 0 ? min(specs->precis, len)
		: len))
		{
			write(1, ((specs->zero && !specs->minus) ? "0" : " "), 1);
			i++;
		}
	if (!specs->minus)
		write(1, str, ((specs->precis >= 0) ? min(specs->precis, len) : len));
	(*printed) += i + (specs->precis >= 0 ? min(specs->precis, len) : len);
}

void	ft_print_prc(int *printed, t_specs *specs)
{
	if (!specs->minus && specs->zero)
		(*printed) += fill('0', specs->width - 1);
	if (!specs->minus && !specs->zero)
		(*printed) += fill(' ', specs->width - 1);
	write(1, "%", 1);
	(*printed)++;
	if (specs->minus)
		(*printed) += fill(' ', specs->width - 1);
}

void	ft_print_integer(va_list arg, t_specs *specs, int *print)
{
	char		*s;
	long int	nbr;
	int			len;

	nbr = va_arg(arg, int);
	s = ft_itoa_base((nbr < 0 ? -nbr : nbr), "0123456789");
	len = (nbr == 0 && specs->precis == 0 ? 0 : ft_strlen(s));
	specs->width -= (nbr < 0 ? 1 : 0);
	(*print) += (nbr < 0 ? (1 + len) : len);
	if (nbr < 0 && specs->zero && specs->precis == -1)
		write(1, "-", 1);
	if (!specs->minus && (specs->zero && specs->precis == -1))
		(*print) += fill('0', specs->width - len);
	if (!specs->minus && !(specs->zero && specs->precis == -1))
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	if (nbr < 0 && !(specs->zero && specs->precis == -1))
		write(1, "-", 1);
	if (specs->precis != -1)
		(*print) += fill('0', specs->precis - len);
	if (!(nbr == 0 && specs->precis == 0))
		write(1, s, len);
	if (specs->minus)
		(*print) += fill(' ', specs->width - (specs->precis != -1 ?
		max(specs->precis, len) : len));
	free(s);
}

void	ft_print_unsign_int(va_list arg, t_specs *specs, int *print)
{
	char			*s;
	unsigned int	nbr;
	int				len;

	nbr = va_arg(arg, int);
	s = ft_itoa_base(nbr, "0123456789");
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
