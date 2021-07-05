/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:48:17 by ametta            #+#    #+#             */
/*   Updated: 2021/06/09 09:48:18 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../../libft/includes/libft.h"

typedef struct s_specs
{
	int			zero;
	int			minus;
	int			width;
	int			precis;
	char		type;
}				t_specs;

int				ft_printf(const char *format, ...);

void			put_chr(va_list arg, t_specs *specs, int *printed);
void			put_str(va_list arg, t_specs *specs, int *printed);
void			put_prc(int *printed, t_specs *specs);
void			put_integer(va_list arg, t_specs *specs, int *print);
void			put_unsign_int(va_list arg, t_specs *specs, int *print);
void			put_hex_low(va_list arg, t_specs *specs, int *print);
void			put_hex_up(va_list arg, t_specs *specs, int *print);
void			put_ptr(va_list arg, t_specs *specs, int *print);

void			parse_flag(const char **format, t_specs *specs);
void			parse_width(const char **format, va_list arg, t_specs *specs);
void			parse_precis(const char **format, va_list arg, t_specs *specs);
void			parse_type(const char **format, t_specs *specs);

char			*ft_itoa_base(unsigned long long int nbr, char *ref_base);
int				fill(char c, int size);

#endif
