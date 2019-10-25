SRC	=	main.c	\

NAME	=	dragon.out

all:	$(NAME)

$(NAME):
		make -C dragon/
		gcc -o $(NAME) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics

clean:
		make clean -C dragon/

fclean:	clean
		make fclean -C dragon/
		-rm $(NAME)

re:	fclean all
