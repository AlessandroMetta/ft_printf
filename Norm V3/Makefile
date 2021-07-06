CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

RM		=	rm -rf

FILES	=	srcs/main.c				\
			srcs/esadecimal.c		\
			srcs/pointer.c		\
			srcs/parsing.c		\
			srcs/utils.c		\
			srcs/character.c	\
			srcs/integer.c	\
			srcs/unsigned.c	\
			srcs/string.c	\
			srcs/percentual.c	\

OBJS = $(FILES:.c=.o)

$(NAME):	$(OBJS)
					ar -rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
					$(RM) $(OBJS)

fclean: clean
					$(RM) $(NAME)

re:			fclean all
