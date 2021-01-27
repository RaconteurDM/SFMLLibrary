##
## EPITECH PROJECT, 2021
## SFMLLibrary
## File description:
## Makefile
##

CC = g++ -c
CC_FLAGS = -std=c++14 -static -Wall -Wextra -W

EXEC = libMySFML
SOURCES =	$(wildcard *.cpp)	\
			$(wildcard */*.cpp) \
			$(wildcard */*/*.cpp)	\
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS =	$(wildcard *.hpp)	\
			$(wildcard */*.hpp) \
			$(wildcard */*/*.hpp)	\
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

lib:	$(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LIBS)

clean:
	rm -f $(EXEC) $(OBJECTS)
