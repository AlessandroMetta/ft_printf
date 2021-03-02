/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:55:49 by ametta            #+#    #+#             */
/*   Updated: 2021/03/02 18:13:59 by ametta           ###   ########.fr       */
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
/* PRINTF */
int				ft_printf(const char *input, ...);

/* UTILITIES */
# define	min(A, B)	((A) < (B) ? (A) : (B))
# define	max(A, B)	((A) > (B) ? (A) : (B))
# define	ft_putchar(A)	write(1, &(A), 1)
int				ft_strlen(char *str);
void			fill(char c, int size, int *ret);
char			*ft_litoa(long int nbr);

/*	si occupa di salvare nella struttura tutte le specifiche di conversione	*/
int				parse_conversion(const char *input, va_list arg, int *ret);

/*		inizializzazione della struttura		*/
static void		init_stc(t_cnv_opt *to_init);

/*		serie di funzioni che si occupano della stampa della conversione	*/
void			conversion(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_char(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_string(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_string2(int *ret, t_cnv_opt *cnv_opt, int to_add);
void			print_integer(int *ret, va_list arg, t_cnv_opt *cnv_opt);
int				print_integer2(t_cnv_opt *cnv_opt, int *ret, char *str_nbr,
									long int nbr);
void			print_unsigned_integer(int *ret, va_list arg,
										t_cnv_opt *cnv_opt);
void			print_hex_low(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_hex_up(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_ptr2(int *ret, t_cnv_opt cnv_opt, char *add,
							long long int n)
void			print_ptr(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void			print_percent(int *ret, t_cnv_opt *cnv_opt);

#endif
