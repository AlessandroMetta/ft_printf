/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:06:23 by ametta            #+#    #+#             */
/*   Updated: 2021/03/09 16:07:58 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_specs
{
	int			zero;
	int			minus;
	int			width;
	int			precis;
	char		type;
}				t_specs;

int				ft_printf(const char *format, ...);

void			ft_print_chr(va_list arg, t_specs *specs, int *printed);
void			ft_print_str(va_list arg, t_specs *specs, int *printed);
void			ft_print_prc(int *printed, t_specs *specs);
void			ft_print_integer(va_list arg, t_specs *specs, int *print);
void			ft_print_unsign_int(va_list arg, t_specs *specs, int *print);
void			ft_print_hex_low(va_list arg, t_specs *specs, int *print);
void			ft_print_hex_up(va_list arg, t_specs *specs, int *print);
void			ft_print_ptr(va_list arg, t_specs *specs, int *print);

char			*ft_strchr(const char *str, int c);
int				ft_isdigit(const char c);
size_t			ft_atoi(const char *str);
size_t			ft_strlen(const char *str);

void			parse_flag(const char **format, t_specs *specs);
void			parse_width(const char **format, va_list arg, t_specs *specs);
void			parse_precis(const char **format, va_list arg, t_specs *specs);
void			parse_type(const char **format, t_specs *specs);

char			*ft_itoa_base(unsigned long long int nbr, char *ref_base);
int				fill(char c, int size);
int				max(int a, int b);
int				min(int a, int b);

#endif
