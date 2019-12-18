SRC	=	main.c	\

NAME	=	dragon.out

DEBUG	=	dragon.d

all:	$(NAME)

$(NAME):
		make -C dragon/
		gcc -o $(NAME) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-system -lcsfml-window

debug:
		make -C dragon/
		gcc -g3 -o $(DEBUG) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-system

clean:
		make clean -C dragon/

fclean:	clean
		make fclean -C dragon/
		-rm $(NAME)
		-rm $(DEBUG)

re:	fclean all
