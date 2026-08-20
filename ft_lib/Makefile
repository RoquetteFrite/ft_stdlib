SRC	=	ft_memmove.c \
		ft_swap.c	\
		ft_strlen.c	\
		ft_strcmp.c	\
		ft_strdup.c

OBJ	=	${SRC:.c=.o}

NAME	=	ft_lib.a

CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
