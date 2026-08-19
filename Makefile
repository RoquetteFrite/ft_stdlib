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
	make -C ft_lib clean

fclean:
	make -C ft_linked_list fclean
	make -C ft_printf fclean
	make -C ft_lib fclean
	rm -f a.out

re:
	make -C ft_linked_list re
	make -C ft_printf re
	make -C ft_lib re

push: 	fclean
	git pull
	git add .
	git commit -m $(m)
	git push

.PHONY: all clean fclean re push
