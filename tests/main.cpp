/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** main
*/

#include "../src/include/Window.hpp"
#include "../src/include/Parser.hpp"

#include <regex>
 
int main()
{
    Parser test = Parser("tests/test.txt", Parser::MAP, NULL);
    std::cout << test.getTextMap("    ");
}