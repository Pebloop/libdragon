##
## EPITECH PROJECT, 2019
## libDragon
## File description:
## Install the lib
##

SRC	=	dragon.c				\
		framebuffer.c			\
		basic_draw.c			\
		draw_line.c				\
		draw_circle.c			\
		draw_rectangle.c		\
		dg_math.c				\
		dg_trigo.c				\
		dg_trigo_part2.c		\

OBJ	=	$(SRC:.c=.o)

INC_PATH = $(strip ../include/)

INC =	$(INC_PATH)libdragon.h		\
		$(INC_PATH)framebuffer.h	\
		$(INC_PATH)dg_drawing.h		\

NAME	= libdragon.a

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -c $(SRC) -Iinclude
	ar rc $(NAME) $(OBJ)
	cp -r include/ ../
	mv $(NAME) ../

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f ../$(NAME)
	ls ../include/
	-rm -f $(INC)
	ls ../include/
