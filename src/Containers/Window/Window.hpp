/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Window
*/

#pragma once

#include "../Container.hpp"
#include "../../Errors/MySfmlExeptions.hpp"
#include "WindowCont.hpp"

class Window
{
public:
    Window(std::string name, sf::Vector2f scale, sf::Color backgroundColor = sf::Color::Black);
    inline Window();
    ~Window();

protected:
    static WindowCont *_mainWindow;
};
