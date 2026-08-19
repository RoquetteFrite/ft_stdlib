m	?=	"Add new feature"

all:
	make -C ft_linked_list
	make -C ft_printf
	gcc main.c \
		ft_linked_list/ft_linked_list.a\
		ft_printf/ft_printf.a

clean:
	make -C ft_linked_list clean
	make -C ft_printf clean

fclean:
	make -C ft_linked_list fclean
	make -C ft_printf fclean
	rm -r a.out

re:
	make -C ft_linked_list re
	make -C ft_printf re

push: 	fclean
	git add .
	git commit -m $(m)
	git pull
	git push

.PHONY: all clean fclean re push
