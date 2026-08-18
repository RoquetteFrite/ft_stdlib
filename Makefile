m	?=	"Add new feature"

all:
	make -C ft_linked_list
	gcc main.c ft_linked_list/ft_linked_list.a

clean:
	make -C ft_linked_list clean

fclean:
	make -C ft_linked_list fclean

re:
	make -C ft_linked_list re

push: 	fclean
	git add .
	git commit -m $(m)
	git pull
	git push

.PHONY: all clean fclean re push
