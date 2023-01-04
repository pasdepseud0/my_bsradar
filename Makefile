##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile generator
##

SRC		=	\
			src/step01.c \
			src/step02.c \
			src/main.c

NAME =	my_radar

OBJ =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I include

LIB	= -L lib/my -lmy

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: 	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) $(LIB) $(CSFML)

clean:
	make clean -C lib/my/
	find . \( -name "#*#" -o -name "*~" -o -name "$(OBJ)" \) -delete

fclean:	clean
	make fclean -C lib/my
	find . \( -name  "vgcore.*" -o -name "*.log" -o -name "*.a" \) -delete
	find . \( -name "*.o" -o -name "$(NAME)" \) -delete

unit_test: fclean
		make unit_test -C tests/

run_test: unit_test
	tests/./unit_test

debug: CFLAGS += -g

debug: 	re

re:	fclean all
