/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:11:47 by ametta            #+#    #+#             */
/*   Updated: 2021/03/09 16:11:48 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flag(const char **format, t_specs *specs)
{
	(*format)++;
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			specs->minus = 1;
		else
			specs->zero = 1;
		(*format)++;
	}
}

void	parse_width(const char **format, va_list arg, t_specs *specs)
{
	if (**format)
	{
		if (**format == '*')
		{
			specs->width = va_arg(arg, int);
			if (specs->width < 0)
			{
				specs->width *= -1;
				specs->minus = 1;
			}
			(*format)++;
		}
		else
			while (ft_isdigit(**format))
			{
				specs->width = (specs->width * 10) + (**format - '0');
				(*format)++;
			}
	}
}

void	parse_precis(const char **format, va_list arg, t_specs *specs)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			specs->precis = va_arg(arg, int);
			if (specs->precis < 0)
				specs->precis = -1;
			(*format)++;
		}
		else
		{
			specs->precis = 0;
			if (ft_isdigit(**format))
			{
				while (ft_isdigit(**format))
				{
					specs->precis = (specs->precis * 10) + (**format - '0');
					(*format)++;
				}
			}
		}
	}
}

void	parse_type(const char **format, t_specs *specs)
{
	if (ft_strchr("csiduxXp%", **format))
	{
		specs->type = **format;
		(*format)++;
	}
}
