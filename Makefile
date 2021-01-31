##
## EPITECH PROJECT, 2021
## SFMLLibrary
## File description:
## Makefile
##

EXEC = test

SOURCES =	 tests/main.cpp

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
	g++ -o $(EXEC) $(SOURCES) src/*/*.cpp src/*/*/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -I./src/include -g -ggdb -g3

clean:
	make -sC src clean
	rm -rf $(OBJECTS)

fclean: clean
	make -sC src fclean
	rm -rf $(EXEC)