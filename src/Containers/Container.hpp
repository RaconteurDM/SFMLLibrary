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

    inline IObject *getChild(std::string Name) override { return _childs[Name]; };
    inline std::map<std::string, IObject *> getAllChilds() const override { return _childs; };

    virtual bool canPlace(IObject *NewChild, bool absoluteCondition = false) const override;

    virtual void addChild(std::string Name, IObject *NewChild) override;

    IObject *detachChild(std::string name) override;
    void removeChild(std::string name) override;
    void removeAllChilds() override;

    virtual void setPosition() override;
    virtual void setScale() override;
};
