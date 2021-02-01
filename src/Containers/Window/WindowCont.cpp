/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** WindowCont
*/

#include "../../include/WindowCont.hpp"


cge::WindowCont::WindowCont(std::string name, sf::Vector2f scale, sf::Color backgroundColor)
    : Container(name, sf::Vector2f(0, 0), sf::Vector2f(1, 1))
{
    window = NULL;
    initWindow(name, scale, backgroundColor);
}

cge::WindowCont::~WindowCont()
{
    if (window)
        delete window;
}

void cge::WindowCont::initWindow(std::string name, sf::Vector2f scale, sf::Color backgroundColor)
{
    if (window)
        throw cgeExeptions("WindowCont:initWindow", "Already initialyzed");
    window = new sf::RenderWindow(sf::VideoMode(scale.x, scale.y), name);
}

int cge::WindowCont::loop()
{
    while (window->isOpen()) {
        while (window->pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        window->display();
    }
    delete window;
    window = NULL;
    return (0);
}

int cge::WindowCont::launch()
{
    initWindow("MyTest", sf::Vector2f(600, 600), sf::Color::Black);
    return (loop());
}
