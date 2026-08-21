SRC	=	ft_push.c 		\
		ft_push_back.c	\
		ft_foreach.c	\
		ft_free_list.c	\
		ft_pop_front.c	\
		ft_pop_back.c	\
		ft_list_find.c

OBJ	=	${SRC:.c=.o}

NAME	=	ft_linked_list.a

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
