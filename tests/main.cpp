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
    cge::Parser test = cge::Parser("tests/test.txt", cge::Parser::MAP, NULL);
    std::cout << test.getTextMap("    ");
    return (cge::Window("Test", sf::Vector2f(600, 600)).getWindow()->loop());
}