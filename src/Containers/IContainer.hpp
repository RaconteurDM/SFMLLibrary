/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** IContainer
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "../Object/Object.hpp"

class IContainer : public Object, public sf::IntRect
{
public:
    IContainer(std::string name) : Object(name) {};
    ~IContainer();

    virtual IObject *getChilds(std::string Name) = 0;

    virtual void addChild(std::string Name, IObject *NewChild) = 0;
protected:
    std::map<std::string, IObject *> _childs;
};
