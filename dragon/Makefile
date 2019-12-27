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
		spritesheet.c			\
		animation.c				\
		animator.c				\
		dep_tools.c				\
		dg_window.c				\
		dg_component.c			\
		dg_entity.c				\
		dg_system.c				\
		dg_scene.c				\
		dg_system_animator.c	\

OBJ	=	$(SRC:.c=.o)

INC_PATH = $(strip ../include/)

INC =	$(INC_PATH)libdragon.h		\
		$(INC_PATH)framebuffer.h	\
		$(INC_PATH)dg_drawing.h		\

NAME	= libdragon.a

all:	$(NAME)

$(NAME):	$(SRC)
	gcc -c -g3 $(SRC) -Iinclude
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
