##
## EPITECH PROJECT, 2021
## SFMLLibrary
## File description:
## Makefile
##

EXEC = libMySFML.a
SOURCES =	$(wildcard Containers/*.cpp)	\
			$(wildcard Containers/Window/*.cpp)	\
			$(wildcard Object/*.cpp)	\
			$(wildcard Errors/*.cpp)	\
			$(wildcard LinkObj/*.cpp)	\
			$(wildcard Parser/*.cpp)	\
			$(wildcard GeneralLib/*.cpp)	\
			$(wildcard Logs/*.cpp)

OBJECTS =	$(SOURCES:.cpp=.o)

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

DEBUG = -g -ggdb -g3

lib:	$(OBJECTS)
	ar rcs $(EXEC) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(EXEC)
