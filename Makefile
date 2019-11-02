SRC	=	main.c	\

NAME	=	dragon.out

DEBUG	=	dragon.d

all:	$(NAME)

$(NAME):
		make -C dragon/
		gcc -Wall -Wextra -o $(NAME) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics

debug:
		make -C dragon/
		gcc -g3 -o $(DEBUG) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics

clean:
		make clean -C dragon/

fclean:	clean
		make fclean -C dragon/
		-rm $(NAME)
		-rm $(DEBUG)

re:	fclean all
