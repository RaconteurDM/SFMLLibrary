##
## EPITECH PROJECT, 2021
## SFMLLibrary
## File description:
## Makefile
##

EXEC = test
SOURCES =	 main.cpp	\

OBJECTS =	$(SOURCES:.cpp=.o)

LIBS = -L./src -lMySFML -lsfml-graphics -lsfml-window -lsfml-system

DEBUG = -g -ggdb -g3

all: 
	make -sC src lib
	make -sC . re
	make -sC . clean

alldebug: 
	make -sC src lib
	make -sC . debug
	make -sC . clean


re:		$(OBJECTS)
	g++ -o $(EXEC) $(OBJECTS) $(LIBS) -I./src/include

debug:	$(OBJECTS)
	g++ -o $(EXEC) $(OBJECTS) $(LIBS) -I./src/include $(DEBUG)

clean:
	make -sC src clean
	rm -rf $(OBJECTS)

fclean: clean
	make -sC src fclean
	rm -rf $(EXEC)