##
## EPITECH PROJECT, 2022
## B-PSU-210-MPL-2-1-minishell2-guillaume.lemoine
## File description:
## Makefile
##

CFLAGS	= -W -Wall -Werror -Wextra -Iinclude/ -g3

SRC		=	main.c

OBJ		=	$(SRC:.c=.o)

BIN		= 	mysh

LIB 	=	./lib/libmy.a

all: $(BIN)

$(BIN): $(OBJ) $(LIB)
	@$(CC) -o $(BIN) $(OBJ) -L./lib -lmy
	@echo Make Success

$(LIB):
	@make -C ./lib/my

clean:
	@$(RM) *.o
	@make clean -C lib/my
	@echo Clean Done

fclean: clean
	@$(RM) $(BIN)
	@make -C ./lib/my fclean
	@$(RM) $(LIB)
	@echo Fclean Done

re: fclean all
