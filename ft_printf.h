/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:55:49 by ametta            #+#    #+#             */
/*   Updated: 2021/03/03 16:43:55 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_cnv_opt
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	char	type;
}				t_cnv_opt;

/*
** 							PRINTF
*/
int				ft_printf(const char *input, ...);

/*
** 							UTILITIES
*/
int				min(int a, int b);
int				max(int a, int b);
void			ft_putchar(char c);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
void			fill(char c, int size, int *ret);
char			*ft_litoa(long int nbr);
char			*ft_hitoa(unsigned long long int nbr, char *base);
char			*ft_strchr(const char *str, int c);
int				ft_atoi(const char *str);

/*
**						funzioni di parsing
*/
int				parse_flag(const char *to_parse, t_cnv_opt *cnv_opt);
int				parse_width(const char *to_parse, va_list arg,
				t_cnv_opt *cnv_opt);
int				parse_precision(const char *to_parse, va_list arg,
				t_cnv_opt *cnv_opt);
int				parse_type(const char *to_parse, t_cnv_opt *cnv_opt);

/*
** 		serie di funzioni che si occupano della stampa della conversione
*/
void			print_char(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_string(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_integer(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_unsigned_integer(int *ret, va_list arg,
										t_cnv_opt *cnv_opt);
void			print_hex_low(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_hex_up(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_ptr(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_percent(int *ret, t_cnv_opt *cnv_opt);

#endif
