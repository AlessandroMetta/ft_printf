/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:48:28 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 09:48:28 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_chr(va_list arg, t_specs *specs, int *printed)
{
	char	chr;
	int		i;

	i = 0;
	chr = va_arg(arg, int);
	if (specs->minus)
		write(1, &chr, 1);
	while (i < specs->width - 1)
	{
		write(1, " ", 1);
		i++;
		(*printed)++;
	}
	if (!specs->minus)
		write(1, &chr, 1);
	(*printed)++;
}
