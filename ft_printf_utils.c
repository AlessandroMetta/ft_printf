/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:42:23 by ametta            #+#    #+#             */
/*   Updated: 2021/03/03 15:34:26 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	fill(const char c, int size, int *ret)
{
	while (size-- > 0)
	{
		ft_putchar(c);
		(*ret)++;
	}
}

int		min(int a, int b)
{
	return (a < b ? a : b);
}

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9' ? c : 0);
}
