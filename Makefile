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

genresp:
	make -sC src lib
	g++ -o genresp tests/UnitTests/GenResp.cpp $(LIBS) -I./src/include -Werror -Wall -Wextra

genrespdebug:
	make -sC src lib
	g++ -o genresp tests/UnitTests/GenResp.cpp src/*/*.cpp src/*/*/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -I./src/include -g -ggdb -g3

tests_run:
	make -sC src lib
	g++ -o tests_run tests/UnitTests/UnitTest.cpp src/*/*.cpp src/*/*/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -lcriterion -I./src/include --coverage
	./tests_run --verbose
	gcovr
	make -sC . fclean

clean:
	make -sC src clean
	rm -rf $(OBJECTS)

fclean: clean
	make -sC src fclean
	rm -rf $(EXEC)
	rm -rf genresp
	rm -rf tests_run
	rm -f *.gcda
	rm -f *.gcno