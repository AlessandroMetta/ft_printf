/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:49:19 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 09:49:19 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	repeat(t_specs *specs, int times)
{
	int	i;

	i = 0;
	while (i < specs->width - times)
	{
		if (specs->zero && !specs->minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	return (i);
}

static int	control(t_specs *specs, int len)
{
	int	i;

	i = 0;
	if (specs->precis >= 0)
	{
		if (specs->width > min(specs->precis, len))
			i = repeat(specs, min(specs->precis, len));
	}
	else if (specs->width > len)
		i = repeat(specs, len);
	return (i);
}

void	put_str(va_list arg, t_specs *specs, int *printed)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (specs->minus && specs->precis >= 0)
		write(1, str, min(specs->precis, len));
	else if (specs->minus)
		write(1, str, len);
	i = control(specs, len);
	if (!specs->minus && specs->precis >= 0)
		write(1, str, min(specs->precis, len));
	else if (!specs->minus)
		write(1, str, len);
	if (specs->precis >= 0)
		(*printed) += i + min(specs->precis, len);
	else
		(*printed) += i + len;
}
