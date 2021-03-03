/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:51:54 by ametta            #+#    #+#             */
/*   Updated: 2021/03/03 16:28:32 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lnlen(long int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_litoa(long int nbr)
{
	size_t	lim;
	size_t	len;
	char	*str;

	len = ft_lnlen(nbr);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		lim = 1;
	}
	else
		lim = 0;
	while (len > lim)
	{
		len--;
		str[len] = '0' + nbr % 10 * (nbr < 0 ? -1 : 1);
		nbr = nbr / 10;
	}
	return (str);
}

char			*ft_hitoa(unsigned long long int nbr, char *base)
{
	size_t					i;
	unsigned long long int	nb;
	char					*str;

	i = 0;
	nb = nbr;
	if (nbr == 0)
		i = 1;
	else
		while (nb)
		{
			nb /= 16;
			i++;
		}
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (i != 0)
	{
		i--;
		str[i] = *(nbr % 16 + base);
		nbr /= 16;
	}
	return (str);
}

char			*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)str + i);
	return (NULL);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	num;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
