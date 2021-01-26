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
    if (parent != NULL && parent->getType() != CONTAINER)
        throw MySfmlExeptions("Container::Container", "Object creation with parent that can't hold child");
    else if (parent != NULL)
        ((Container *)parent)->addChild(name, this);
}

Container::~Container()
{
}

void Container::setPosition()
{
    left = _parentRelativePosition.x * _parent->getScale().x + _parent->getPosition().x;
    top = _parentRelativePosition.y * _parent->getScale().y + _parent->getPosition().y;
}

void Container::setScale()
{
    width = _parentRelativeScale.x * _parent->getScale().x;
    top = _parentRelativeScale.y * _parent->getScale().y;
}

bool Container::canPlace(IObject *NewChild, bool absoluteCondition) const
{
    std::map<std::string, IObject *> childsMap = getAllChilds();

    for (auto it = childsMap.begin(); it != childsMap.end(); it++)
    {
        if (it->second->isOnGlobalPlan() && it->second->intersects(*((sf::IntRect *)NewChild)))
            if (absoluteCondition)
                throw MySfmlExeptions("Container::canPlace", "Try to place " + NewChild->getName() + " on " + it->second->getName());
            return (false);
    }
    return (true);
}

void Container::addChild(std::string Name, IObject *NewChild)
{
    NewChild->setPosition();
    NewChild->setScale();
    canPlace(NewChild, true);
    _childs[Name] = NewChild;
}

IObject *Container::detachChild(std::string name)
{
    IObject *toReturn;

    if (!_childs[name])
        throw MySfmlExeptions("Container::detachChild", "Try to detach inexistant child (name = \"" + name + "\")");
    toReturn = _childs[name];
    _childs.erase(name);
    return toReturn;
}

void Container::removeChild(std::string name)
{
    if (!_childs[name])
        throw MySfmlExeptions("Container::removeChild", "Try to remove inexistant child (name = \"" + name + "\")");
    delete _childs[name];
    _childs.erase(name);
}

void Container::removeAllChilds()
{
    auto it = _childs.begin();

    while (it != _childs.end())
    {
        delete it->second;
        it = _childs.erase(it);
    }
}