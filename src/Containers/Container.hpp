/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Container
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "IContainer.hpp"

class Container : public IContainer
{
public:
    Container(std::string name, sf::Vector2f parentRelativePos, sf::Vector2f parentRelativeScale, IObject *parent = NULL);
    ~Container();

    inline IObject *getChilds(std::string Name) override { return _childs[Name]; };

    void addChild(std::string Name, IObject *NewChild) override;
};
