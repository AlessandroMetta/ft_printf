/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:10:35 by ametta            #+#    #+#             */
/*   Updated: 2021/03/09 16:11:33 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int		ft_isdigit(const char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

size_t	ft_atoi(const char *str)
{
	size_t nbr;

	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr);
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
