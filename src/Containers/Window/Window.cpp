/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Window
*/

#include "Window.hpp"

Window::Window(std::string name, sf::Vector2f scale, sf::Color backgroundColor)
{
    if (!_mainWindow)
        _mainWindow = new WindowCont(name, scale, backgroundColor);
    else
        throw MySfmlExeptions("Window:Window", "You should only use the default constructor after window initialization");
}

Window::~Window()
{
    _mainWindow = NULL;
}