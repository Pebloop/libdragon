##
## EPITECH PROJECT, 2019
## libDragon
## File description:
## Install the lib
##

SRC	=	dragon.c	\
		framebuffer.c	\
		basic_draw.c	\

OBJ	=	$(SRC:.c=.o)

NAME	= libdragon.a

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -c $(SRC) -Iinclude
	ar rc $(NAME) $(OBJ)
	cp -r include/ ../../
	cp $(NAME) ../

clean:
	-rm -f $(OBJ)
	-rm -f $(NAME)

fclean: clean
	-rm -f ../$(NAME)
