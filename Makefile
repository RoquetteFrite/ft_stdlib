m	?=	"Add new feature"

run:
	gcc main.c \
		ft_linked_list/ft_linked_list.a \
		ft_printf/ft_printf.a \
		ft_lib/ft_lib.a

all:
	make -C ft_lib
	make -C ft_linked_list
	make -C ft_printf
	$(run)

clean:
	make -C ft_lib clean
	make -C ft_printf clean
	make -C ft_linked_list clean

fclean:
	make -C ft_lib fclean
	make -C ft_printf fclean
	make -C ft_linked_list fclean
	rm -f a.out

re:
	make -C ft_lib re
	make -C ft_printf re
	make -C ft_linked_list re
	$(run)

push: 	fclean
	git pull
	git add .
	git commit -m $(m)
	git push

.PHONY: all clean fclean re push
