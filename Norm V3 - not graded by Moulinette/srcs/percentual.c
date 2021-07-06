/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:49:07 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 09:49:08 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_prc(int *printed, t_specs *specs)
{
	if (!specs->minus && specs->zero)
		(*printed) += fill('0', specs->width - 1);
	if (!specs->minus && !specs->zero)
		(*printed) += fill(' ', specs->width - 1);
	write(1, "%", 1);
	(*printed)++;
	if (specs->minus)
		(*printed) += fill(' ', specs->width - 1);
}
