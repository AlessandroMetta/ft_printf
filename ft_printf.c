/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:58:45 by ametta            #+#    #+#             */
/*   Updated: 2021/02/26 15:34:58 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ci sono vari informazioni di conversione che possiamo dare a printf:
** - le option o flags (noi dobbiamo gestire solo -, che allinea a sinistra
**	 l'argomento convertito, e 0, che nelle conversione numeriche 
**	 va ad inserire zeri in testa fino al raggiungimento dell'ampiezza del campo)
** - un numero che specifica l'ampiezza del campo. se l'argomento cconvertito
**	 ha meno caratteri dell'ampiezza minima del campo, saranno aggiunti in testa
**	 dei caratteri spazio, se specificata la flag 0, vengono aggiunti in testa 
**	 caratteri zero, se invece viene specificata la flag -, gli spazi vengono
**	 inseriti in coda, fino a raggiungere l'ampiezza richiesta.
** - il punto, per separare l'ampiezza dalla precisione
** - il grado di precisione che specifichi:
**	- per le stringhe, il massimo numero di caratteri da scrivere;
**	- per gli interi il numero minimo di cifre da scrivere, con l'aggiunta di 0
**	  in testa per raggiunngere l'ampiezza richiesta.
** - infine il ccarattere di conversione (noi dobbiamo gestire solamente i seguenti: 
**	 csdiuxXp%)
**	per salvare tutte queste informazioni, ci conviene creare una struttura e 
**	definirla come tipo. Essa conterrá tutte queste informazionii.
*/

static void init_stc(t_cnv_opt *to_init)	/* inizializzazione della struttura cnv_opt */
{
	if(to_init)
	{
		to_init->zero = 0;
		to_init->minus = 0;
		to_init->width = 0;
		to_init->precision = -1;
		to_init->type = '\0';
	}
}

void		conversion(int *ret, va_list arg, t_cnv_opt *cnv_opt)	/* indirizza verso la corretta funzione per la conversione */
{
	if (cnv_opt->type == 'c')
		print_char(ret, arg, cnv_opt);
	else if (cnv_opt->type == 's')
		print_string(ret, arg, cnv_opt);
	else if (cnv_opt->type == 'd' || cnv_opt->type == 'i')
		print_integer(ret, arg, cnv_opt);
	else if (cnv_opt->type == 'u')
		print_unsigned_integer(ret, arg, cnv_opt);
	else if (cnv_opt->type == 'x')
		print_hex_low(ret, arg, cnv_opt);
	else if (cnv_opt->type == 'X')
		print_hex_up(ret, arg, cnv_opt);
	else if (cnv_opt->type == 'p')
		print_ptr_add(ret, arg, cnv_opt);
	else if (cnv_opt->type == '%')
		print_percent(ret, cnv_opt);
	else
		*ret = -1;
	
}

int			parse_conversion(const char *input, va_list arg, int *ret)
{
	t_cnv_opt cnv_opt;
	const char *original;

	original = input;
	init_stc(&cnv_opt);
	input += parse_flag(input, &cnv_opt);
	input += parse_width(input, &cnv_opt);
	input += parse_precision(input, &cnv_opt);
	input += parse_type(input, &cnv_opt);
	conversion(ret, arg, &cnv_opt);
	return (input - original);
}

int			ft_printf(const char *input, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, input);
	ret = 0;
	while (*input)
	{
		if (*input != '%')
		{
			ft_putchar(input);
			input++;
			ret++;
		}
		else
			input += parse_conversion(*input, arg, &ret);
	}
	return (ret);
}
