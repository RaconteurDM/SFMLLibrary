/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** IContainer
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class IContainer : public Object
{
public:
    IContainer(std::string name, IObject *parent = NULL) : Object(name, parent) {};
    virtual ~IContainer() {};

    virtual IObject *getChild(std::string Name) = 0;
    virtual std::map<std::string, IObject *> getAllChilds() const = 0;

    virtual bool canPlace(IObject *NewChild, bool absoluteCondition) const = 0;

    virtual void addChild(std::string Name, IObject *NewChild) = 0;

    virtual IObject *detachChild(std::string name) = 0;
    virtual void removeChild(std::string name) = 0;
    virtual void removeAllChilds() = 0;

protected:
    std::map<std::string, IObject *> _childs;
};
