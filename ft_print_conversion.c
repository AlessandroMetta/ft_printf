/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:56:18 by ametta            #+#    #+#             */
/*   Updated: 2021/02/26 16:20:02 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	char	c;
	int		i;

	c = va_arg(arg, int);
	i = 0;
	if (cnv_opt->minus)
		ft_putchar(c);
	while (i < cnv_opt->width - 1)
	{
		ft_putchar(" ");
		i++;
		(*ret)++;
	}
	if (!cnv_opt->minus)
		ft_putchar(c);
	(*ret)++;
}

void		print_string(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	char	*str;
	int		i;
	int		len_str;

	str = va_arg(arg, char*);
	if (!str)
		str = "(null)";
	len_str = ft_strlen(str);
	i = 0;
	if (cnv_opt->minus)
		write(1, str, ((cnv_opt->precision >= 0) ?
				(min(cnv_opt->precision, len_str)) : len_str));
	if (cnv_opt->width > ((cnv_opt->precision >= 0) ?
		min(cnv_opt->precision, len_str) : len_str))
	{
		while (i < cnv_opt->width - ((cnv_opt->precision >= 0) ?
				min(cnv_opt->precision, len_str) : len_str))
		{
			write(1, cnv_opt->zero && !cnv_opt->minus ? "0" : " ", 1);
			i++;
			(*ret)++;
		}
	}
	if (!cnv_opt->minus)
		write(1, str, ((cnv_opt->precision >= 0) ? 
				(min(cnv_opt->precision, len_str)) : len_str));
	(*ret) += (cnv_opt->precision >= 0 ? min(cnv_opt->precision, len_str) :
				len_str);
}

void		print_integer(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{

}

void		print_unsigned_integer(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{

}

void		print_hex_low(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{

}

void		print_hex_up(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{

}

void		print_ptr_add(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{

}

void		print_percent(int *ret, t_cnv_opt *cnv_opt)
{

}
