/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:49:13 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 09:49:13 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	control(unsigned long long int nbr, t_specs *specs, char *s)
{
	specs->width -= 2;
	if (nbr == 0 && specs->precis == 0)
		return (0);
	else
		return (ft_strlen(s));
}

void	put_ptr(va_list arg, t_specs *specs, int *print)
{
	char					*s;
	unsigned long long int	nbr;
	int						len;

	nbr = va_arg(arg, unsigned long long int);
	s = ft_itoa_base(nbr, "0123456789abcdef");
	len = control(nbr, specs, s);
	(*print) += len + 2;
	if (!specs->minus && specs->zero)
		write(1, "0x", 2);
	if (!(specs->minus) && (specs->zero && specs->precis == -1))
		(*print) += fill('0', specs->width - len);
	if (!(specs->minus) && !(specs->zero && specs->precis == -1))
		(*print) += fill(' ', specs->width - max(specs->precis, len));
	if (!specs->zero)
		write(1, "0x", 2);
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
