##
## EPITECH PROJECT, 2019
## libDragon
## File description:
## Install the lib
##

SRC_SKL	=		src/dragon.c									\
				src/dg_window.c									\

SRC_EPI =		src/epi_tools/dep_tools.c						\

SRC_FMB =		src/elements/framebuffer/dg_framebuffer.c		\
				src/elements/framebuffer/dg_fb_putpx.c			\
				src/elements/framebuffer/dg_fb_putline.c		\
				src/elements/framebuffer/dg_fb_putcircle.c		\
				src/elements/framebuffer/dg_fb_putrectangle.c	\

SRC_MATH =		src/mathematics/dg_square.c 					\
				src/mathematics/dg_abs.c 						\
				src/mathematics/dg_pow.c						\
				src/mathematics/dg_square.c						\
				src/mathematics/dg_trigo.c						\
				src/mathematics/dg_arc_trigo.c				\

SRC_RD =		src/elements/rendering/dg_spritesheet.c			\
				src/elements/rendering/dg_animation.c			\
				src/elements/rendering/dg_animator.c			\

SRC_ECS_STC =	src/ecs/struct/dg_component.c					\
				src/ecs/struct/dg_entity.c						\
				src/ecs/struct/dg_system.c						\
				src/ecs/struct/dg_scene.c						\

SRC_ECS_S =		src/ecs/systems/dg_system_animator.c			\

SRC_ALL =	$(SRC_SKL) $(SRC_EPI) $(SRC_FMB) $(SRC_MATH) $(SRC_RD) $(SRC_ECS_STC) $(SRC_ECS_S)

OBJ	=	$(SRC_ALL:.c=.o)

INC_PATH = $(strip ../include/)

INC =	$(INC_PATH)libdragon.h		\

CFLAGS =	-Iinclude

NAME	= libdragon.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp -r include/ ../
	mv $(NAME) ../

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f ../$(NAME)
	-rm -f $(INC)
