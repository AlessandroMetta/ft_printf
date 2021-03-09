CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

RM		=	rm -rf

FILES	=	ft_printf.c				\
			ft_printf_csuid_prc.c	\
			ft_printf_esa_ptr.c		\
			ft_printf_libft.c		\
			ft_printf_parsing.c		\
			ft_printf_utils.c		\

OBJS = $(FILES:.c=.o)

$(NAME):	$(OBJS)
					ar -rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
					$(RM) $(OBJS)

fclean: clean
					$(RM) $(NAME)

re:			fclean all
