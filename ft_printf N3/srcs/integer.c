/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:48:47 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 09:48:47 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	control(t_specs *specs, char **s, long int nbr, int *print)
{
	size_t	len;

	if (nbr < 0)
		*s = ft_itoa_base(-nbr, "0123456789");
	else
		*s = ft_itoa_base(nbr, "0123456789");
	len = ft_strlen(*s);
	if (nbr == 0 && specs->precis == 0)
		len = 0;
	if (nbr < 0)
	{
		specs->width--;
		(*print) += len + 1;
	}
	else
		(*print) += len;
	return (len);
}

void	put_integer(va_list arg, t_specs *specs, int *print)
{
	char		*s;
	long int	nbr;
	int			len;

	nbr = va_arg(arg, int);
	len = control(specs, &s, nbr, print);
	if (nbr < 0 && specs->zero && specs->precis == -1)
		write(1, "-", 1);
	if (!specs->minus && (specs->zero && specs->precis == -1))
		(*print) += fill('0', specs->width - len);
	if (!specs->minus && !(specs->zero && specs->precis == -1))
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	if (nbr < 0 && !(specs->zero && specs->precis == -1))
		write(1, "-", 1);
	if (specs->precis != -1)
		(*print) += fill('0', specs->precis - len);
	if (!(nbr == 0 && specs->precis == 0))
		write(1, s, len);
	if (specs->minus && specs->precis != -1)
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	else if (specs->minus)
		(*print) += fill(' ', specs->width - len);
	free(s);
}
