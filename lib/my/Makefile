##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

AR				=	ar
ARFLAGS			=	rsc libmy.a *.o

all: make_lib

make_lib:
	@$(CC)   *.c -c -g3
	@$(AR) $(ARFLAGS)
	@cp libmy.a ../libmy.a
	@echo LIB Done

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ../libmy.a
	@rm -rf libmy.a

re: fclean all
