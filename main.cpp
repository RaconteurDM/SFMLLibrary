/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** main
*/

#include "src/include/Window.hpp"

int main(void)
{
    return (Window("MyTest", sf::Vector2f(600, 600)).getWindow()->loop());
}