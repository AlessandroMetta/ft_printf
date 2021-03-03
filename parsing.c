/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:55:34 by ametta            #+#    #+#             */
/*   Updated: 2021/03/03 16:30:02 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flag(const char *to_parse, t_cnv_opt *cnv_opt)
{
	int i;

	to_parse++;
	i = 1;
	while (*to_parse == '-' || *to_parse == '0')
	{
		if (*to_parse == '-')
			cnv_opt->minus = 1;
		else
			cnv_opt->zero = 1;
		i++;
		to_parse++;
	}
	return (i);
}

int		parse_width(const char *to_parse, va_list arg, t_cnv_opt *cnv_opt)
{
	int i;

	i = 0;
	if (!*to_parse)
		return (0);
	else if (*to_parse == '*')
	{
		cnv_opt->width = va_arg(arg, int);
		if (cnv_opt->width < 0)
		{
			cnv_opt->width *= -1;
			cnv_opt->minus = 1;
		}
		return (1);
	}
	else
	{
		cnv_opt->width = ft_atoi(to_parse);
		while (ft_isdigit(to_parse[i]))
			i++;
		return (i);
	}
}

int		parse_precision(const char *to_parse, va_list arg, t_cnv_opt *cnv_opt)
{
	int i;

	i = 0;
	if ((!*to_parse) || !(*to_parse++ == '.'))
		return (0);
	else if (*to_parse == '*')
	{
		cnv_opt->precision = va_arg(arg, int);
		if (cnv_opt->precision < 0)
			cnv_opt->precision = -1;
		return (2);
	}
	else if (!ft_isdigit(*to_parse))
	{
		cnv_opt->precision = 0;
		return (1);
	}
	else
	{
		cnv_opt->precision = ft_atoi(to_parse);
		while (ft_isdigit(to_parse[i]))
			i++;
		return (i + 1);
	}
}

int		parse_type(const char *to_parse, t_cnv_opt *cnv_opt)
{
	if (!to_parse)
		return (0);
	else if (ft_strchr("csdiuxXp%", *to_parse))
	{
		cnv_opt->type = *to_parse;
		return (1);
	}
	return (0);
}
