/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:33 by ametta            #+#    #+#             */
/*   Updated: 2021/03/09 16:09:03 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_struct(t_specs *to_init)
{
	to_init->zero = 0;
	to_init->minus = 0;
	to_init->width = 0;
	to_init->precis = -1;
	to_init->type = '\0';
}

static void	sorting_conv(va_list arg, t_specs *specs, int *printed)
{
	if (specs->type == 'c')
		ft_print_chr(arg, specs, printed);
	else if (specs->type == 's')
		ft_print_str(arg, specs, printed);
	else if (specs->type == 'i' || specs->type == 'd')
		ft_print_integer(arg, specs, printed);
	else if (specs->type == 'u')
		ft_print_unsign_int(arg, specs, printed);
	else if (specs->type == 'x')
		ft_print_hex_low(arg, specs, printed);
	else if (specs->type == 'X')
		ft_print_hex_up(arg, specs, printed);
	else if (specs->type == 'p')
		ft_print_ptr(arg, specs, printed);
	else if (specs->type == '%')
		ft_print_prc(printed, specs);
	else
		(*printed) = -1;
}

static void	conversion(const char **format, va_list arg, int *printed)
{
	t_specs specs;

	init_struct(&specs);
	parse_flag(format, &specs);
	parse_width(format, arg, &specs);
	parse_precis(format, arg, &specs);
	parse_type(format, &specs);
	sorting_conv(arg, &specs, printed);
}

int			ft_printf(const char *format, ...)
{
	va_list arg;
	int		printed;

	va_start(arg, format);
	printed = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed++;
			format++;
		}
		else
			conversion(&format, arg, &printed);
		if (printed == -1)
			return (-1);
	}
	va_end(arg);
	return (printed);
}
