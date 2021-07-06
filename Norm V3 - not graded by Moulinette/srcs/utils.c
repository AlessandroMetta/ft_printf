/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:49:29 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 10:15:53 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(unsigned long long int nbr, char *ref_base)
{
	int						size;
	char					*str_nbr;
	unsigned long long int	cp;
	int						base;

	cp = nbr;
	base = ft_strlen(ref_base);
	size = 1;
	while (cp / base)
	{
		size++;
		cp /= base;
	}
	str_nbr = (char *)malloc(sizeof(char) * (size + 1));
	allocation_checker((void *)str_nbr);
	str_nbr[size--] = '\0';
	str_nbr[0] = '0';
	while (nbr > 0)
	{
		str_nbr[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (str_nbr);
}

int	fill(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}
