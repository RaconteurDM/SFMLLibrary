/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** WindowCont
*/

#pragma once

#include "Container.hpp"
#include "MySfmlExeptions.hpp"

namespace cge
{
    class WindowCont : public Container
    {
    public:
        WindowCont(std::string name, sf::Vector2f scale, sf::Color backgroundColor = sf::Color::Black);
        ~WindowCont();

        void initWindow(std::string name, sf::Vector2f scale, sf::Color backgroundColor);
        sf::RenderWindow *getWindow();

        int loop();
        int launch();

    protected:
        sf::RenderWindow *window;
        sf::Event _event;
    };
} // namespace cge
