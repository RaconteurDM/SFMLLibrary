/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Container
*/

#include "Container.hpp"
#include "../Errors/MySfmlExeptions.hpp"

Container::Container(std::string name, sf::Vector2f parentRelativePos, sf::Vector2f parentRelativeScale, IObject *parent) : IContainer(name)
{
    _name = name;
    _parent = parent;
    _parentRelativeScale = parentRelativeScale;
    _parentRelativePosition = parentRelativePos;
    if (parent->getType() != CONTAINER && parent != NULL)
        throw MySfmlExeptions("Container::Container", "Object creation with parent that can't hold child");
    else if (parent != NULL)
        ((Container *)parent)->addChild(name, this);
}

Container::~Container()
{
}
