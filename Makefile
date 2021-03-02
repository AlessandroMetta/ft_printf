CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

AR		=	ar rc

RM		=	rm -rf

FILE	=	./ft_printf.c			\
			./ft_printf.h			\
			./ft_printf_utils.c		\
			./print_type/cs_pc.c	\
			./print_type/uid.c		\
			./print_type/xXp.c		\

OBJS = $(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
					$(AR) $(NAME) $(OBJS)
					ranlib $(NAME)

clean:
					$(RM) $(OBJS)

fclean: clean
					$(RM) $(NAME)

re:			fclean all
