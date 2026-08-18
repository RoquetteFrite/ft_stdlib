SRC	=	main.c

OBJ	=	${SRC:.c=.o}

NAME	=	libft.a

FLAGS	=	-Wall -Werror -Wextra

COMMIT	?=	"Add new feature"

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

push: 	fclean
	git add .
	git commit -m $(COMMIT)
	git pull
	git push

run: all
	./$(NAME)

.PHONY: all clean fclean re push run
