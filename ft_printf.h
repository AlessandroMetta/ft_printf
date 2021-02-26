/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:55:49 by ametta            #+#    #+#             */
/*   Updated: 2021/02/26 15:56:10 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cnv_opt 
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	char	type;
}				t_cnv_opt;
/* PRINTF */
int			ft_printf(const char *input, ...);

/* UTILITIES */
# define	min(A, B)	((A) < (B) ? (A) : (B))
# define	max(A, B)	((A) > (B) ? (A) : (B))
# define	ft_putchar(A)	write(1, &(A), 1)
int		ft_strlen(char *str);

/*		si occupa di salvare nella struttura tutte le specifiche di conversione		*/
int			parse_conversion(const char *input, va_list arg, int *ret);

/*		inizializzazione della struttura		*/
static void init_stc(t_cnv_opt *to_init);

/*		serie di funzioni che si occupano della stampa della conversione	*/
void		conversion(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_char(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_string(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_integer(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_unsigned_integer(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_hex_low(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_hex_up(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_ptr_add(int *ret, va_list arg, t_cnv_opt *cnv_opt);
void		print_percent(int *ret, t_cnv_opt *cnv_opt);

#endif