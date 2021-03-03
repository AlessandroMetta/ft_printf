CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

RM		=	rm -rf

FILES	=	ft_printf.c				\
			ft_printf_utils.c		\
			ft_printf_utils2.c		\
			parsing.c				\
			print_type/cs_pc.c		\
			print_type/uid.c		\
			print_type/xp.c			\

OBJS = $(FILES:.c=.o)

$(NAME):	$(OBJS)
					ar -rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
					$(RM) $(OBJS)

fclean: clean
					$(RM) $(NAME)

re:			fclean all
