/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:37:24 by ametta            #+#    #+#             */
/*   Updated: 2021/03/03 16:48:55 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		print_hex(int *ret, va_list arg, t_cnv_opt *cnv_opt,
				char *base)
{
	char			*output;
	unsigned int	nbr;
	int				to_add;

	nbr = (va_arg(arg, unsigned int));
	output = ft_hitoa(nbr, base);
	to_add = ft_strlen(output);
	if (nbr == 0 && cnv_opt->precision == 0)
		to_add = 0;
	if (!cnv_opt->minus && cnv_opt->zero && cnv_opt->precision == -1)
		fill('0', cnv_opt->width - to_add, ret);
	if (!(cnv_opt->minus && cnv_opt->zero && cnv_opt->precision == -1))
		fill(' ', cnv_opt->width - max(cnv_opt->precision, to_add), ret);
	if (cnv_opt->precision != -1)
		fill('0', cnv_opt->precision - to_add, ret);
	if (!(nbr == 0 && cnv_opt->precision == 0))
		write(1, output, to_add);
	if (cnv_opt->minus)
		fill(' ', cnv_opt->width - (cnv_opt->precision != -1 ?
					max(cnv_opt->precision, to_add) : to_add), ret);
	(*ret) += to_add;
	free(output);
}

void			print_hex_low(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	print_hex(ret, arg, cnv_opt, "0123456789abcdef");
}

void			print_hex_up(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	print_hex(ret, arg, cnv_opt, "0123456789ABCDEF");
}

static int		print_ptr2(int *ret, t_cnv_opt *cnv_opt, char *str,
				long long int nbr)
{
	int	to_add;

	to_add = ft_strlen(str);
	if (nbr == 0 && cnv_opt->precision == 0)
		to_add = 0;
	if (!cnv_opt->minus && cnv_opt->zero)
		write(1, "0x", 2);
	if (!cnv_opt->minus && cnv_opt->zero && cnv_opt->precision == -1)
		fill('0', cnv_opt->width - to_add, ret);
	if (!(cnv_opt->minus && cnv_opt->zero && cnv_opt->precision == -1))
		fill(' ', cnv_opt->width - max(cnv_opt->precision, to_add), ret);
	if (!cnv_opt->zero)
		write(1, "0x", 2);
	if (cnv_opt->precision != -1)
		fill('0', cnv_opt->precision - to_add, ret);
	if (!(nbr == 0 && cnv_opt->precision == 0))
		write(1, str, to_add);
	if (cnv_opt->minus)
		fill(' ', cnv_opt->width - (cnv_opt->precision != -1 ?
					max(cnv_opt->precision, to_add) : to_add), ret);
	return (to_add);
}

void			print_ptr(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	char					*str;
	unsigned long long int	nbr;
	int						to_add;

	nbr = (va_arg(arg, unsigned long long int));
	str = ft_hitoa(nbr, "0123456789abcdef");
	cnv_opt->width -= 2;
	to_add = print_ptr2(ret, cnv_opt, str, nbr);
	(*ret) += to_add + 2;
	free(str);
}
