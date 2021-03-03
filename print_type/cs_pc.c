/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_pc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:36:13 by ametta            #+#    #+#             */
/*   Updated: 2021/03/03 16:34:29 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			print_char(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	char	c;
	int		i;

	c = va_arg(arg, int);
	i = 0;
	if (cnv_opt->minus)
		ft_putchar(c);
	while (i < cnv_opt->width - 1)
	{
		ft_putchar(' ');
		i++;
		(*ret)++;
	}
	if (!cnv_opt->minus)
		ft_putchar(c);
	(*ret)++;
}

static void		print_string2(int *ret, t_cnv_opt *cnv_opt, int to_add)
{
	int	i;

	i = 0;
	if (cnv_opt->width > ((cnv_opt->precision >= 0) ?
		min(cnv_opt->precision, to_add) : to_add))
	{
		while (i < cnv_opt->width - ((cnv_opt->precision >= 0) ?
				min(cnv_opt->precision, to_add) : to_add))
		{
			write(1, cnv_opt->zero && !cnv_opt->minus ? "0" : " ", 1);
			i++;
			(*ret)++;
		}
	}
}

void			print_string(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	char	*str;
	int		to_add;

	str = va_arg(arg, char*);
	if (!str)
		str = "(null)";
	to_add = ft_strlen(str);
	if (cnv_opt->minus)
		write(1, str, ((cnv_opt->precision >= 0) ?
				(min(cnv_opt->precision, to_add)) : to_add));
	print_string2(ret, cnv_opt, to_add);
	if (!cnv_opt->minus)
		write(1, str, ((cnv_opt->precision >= 0) ?
				(min(cnv_opt->precision, to_add)) : to_add));
	(*ret) += (cnv_opt->precision >= 0 ? min(cnv_opt->precision, to_add) :
				to_add);
}

void			print_percent(int *ret, t_cnv_opt *cnv_opt)
{
	if (!(cnv_opt->minus && cnv_opt->zero))
		fill(' ', cnv_opt->width - 1, ret);
	if (cnv_opt->zero && !cnv_opt->minus)
		fill('0', cnv_opt->width - 1, ret);
	ft_putchar('%');
	(*ret)++;
	if (cnv_opt->minus)
		fill(' ', cnv_opt->width - 1, ret);
}
