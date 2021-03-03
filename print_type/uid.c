/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:09:12 by ametta            #+#    #+#             */
/*   Updated: 2021/03/03 16:37:12 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		print_integer2(t_cnv_opt *cnv_opt, int *ret, char *str_nbr,
								long int nbr)
{
	int to_add;

	to_add = ft_strlen(str_nbr);
	if (nbr == 0 && cnv_opt->precision == 0)
		to_add = 0;
	if (cnv_opt->zero && cnv_opt->precision == -1 && nbr < 0)
		ft_putchar('-');
	if ((!cnv_opt->minus) && cnv_opt->zero && cnv_opt->precision == -1)
		fill('0', (cnv_opt->width - to_add), ret);
	if (!(cnv_opt->minus && cnv_opt->zero && cnv_opt->precision == -1))
		fill(' ', cnv_opt->width - max(cnv_opt->precision, to_add), ret);
	if (!(cnv_opt->zero && cnv_opt->precision == -1) && nbr < 0)
		ft_putchar('-');
	if (!(cnv_opt->precision == -1))
		fill('0', (cnv_opt->precision - to_add), ret);
	if (!(nbr == 0 && cnv_opt->precision == 0))
		write(1, str_nbr, to_add);
	if (cnv_opt->minus)
		fill(' ', (cnv_opt->width - ((cnv_opt->precision != -1) ?
						(max(cnv_opt->precision, to_add)) : to_add)), ret);
	return (to_add);
}

void			print_integer(int *ret, va_list arg, t_cnv_opt *cnv_opt)
{
	char		*str_nbr;
	long int	nbr;
	long int	i;
	int			to_add;

	nbr = (va_arg(arg, int));
	i = nbr;
	if (nbr < 0)
	{
		i *= -1;
		cnv_opt->width--;
		(*ret)++;
	}
	str_nbr = ft_litoa(i);
	to_add = print_integer2(cnv_opt, ret, str_nbr, nbr);
	(*ret) += to_add;
	free(str_nbr);
}

void			print_unsigned_integer(int *ret, va_list arg,
										t_cnv_opt *cnv_opt)
{
	char			*str_nbr;
	unsigned int	nbr;
	int				to_add;

	nbr = (va_arg(arg, int));
	str_nbr = ft_litoa(nbr);
	to_add = ft_strlen(str_nbr);
	if (nbr == 0 && cnv_opt->precision == 0)
		to_add = 0;
	if ((!cnv_opt->minus) && cnv_opt->zero && cnv_opt->precision == -1)
		fill('0', (cnv_opt->width - to_add), ret);
	if (!(cnv_opt->minus && cnv_opt->zero && cnv_opt->precision == -1))
		fill(' ', cnv_opt->width - max(cnv_opt->precision, to_add), ret);
	if (!(cnv_opt->precision == -1))
		fill('0', (cnv_opt->precision - to_add), ret);
	if (!(nbr == 0 && cnv_opt->precision == 0))
		write(1, str_nbr, to_add);
	if (cnv_opt->minus)
		fill(' ', (cnv_opt->width - ((cnv_opt->precision != -1) ?
						(max(cnv_opt->precision, to_add)) : to_add)), ret);
	(*ret) += to_add;
	free(str_nbr);
}
