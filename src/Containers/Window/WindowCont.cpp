/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** WindowCont
*/

#include "WindowCont.hpp"


WindowCont::WindowCont(std::string name, sf::Vector2f scale, sf::Color backgroundColor)
    : Container(name, sf::Vector2f(0, 0), sf::Vector2f(1, 1))
{
    initWindow(name, scale, backgroundColor);
}

WindowCont::~WindowCont()
{
    if (window)
        delete window;
}

void WindowCont::initWindow(std::string name, sf::Vector2f scale, sf::Color backgroundColor)
{
    if (window)
        throw MySfmlExeptions("WindowCont:initWindow", "Already initialyzed");
    window = new sf::RenderWindow(sf::VideoMode(scale.x, scale.y), name);
}
