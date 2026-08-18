SRC	=	ft_push.c 		\
		ft_push_back.c

OBJ	=	${SRC:.c=.o}

NAME	=	ft_linked_list.a

CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
