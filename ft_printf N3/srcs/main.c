/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:48:55 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 10:02:29 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		put_chr(arg, specs, printed);
	else if (specs->type == 's')
		put_str(arg, specs, printed);
	else if (specs->type == 'i' || specs->type == 'd')
		put_integer(arg, specs, printed);
	else if (specs->type == 'u')
		put_unsign_int(arg, specs, printed);
	else if (specs->type == 'x')
		put_hex_low(arg, specs, printed);
	else if (specs->type == 'X')
		put_hex_up(arg, specs, printed);
	else if (specs->type == 'p')
		put_ptr(arg, specs, printed);
	else if (specs->type == '%')
		put_prc(printed, specs);
	else
		(*printed) = -1;
}

static void	conversion(const char **format, va_list arg, int *printed)
{
	t_specs	specs;

	init_struct(&specs);
	parse_flag(format, &specs);
	parse_width(format, arg, &specs);
	parse_precis(format, arg, &specs);
	parse_type(format, &specs);
	sorting_conv(arg, &specs, printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
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
