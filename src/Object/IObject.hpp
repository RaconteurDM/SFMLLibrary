/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** IObject
*/

#pragma once

#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class IObject : public sf::IntRect
{
public:
    typedef enum type_e
    {
        DEFAULT,
        CONTAINER,
        COMPONENT
    } Type;

    virtual ~IObject(){};

    virtual IObject *getParent() = 0;
    virtual sf::Vector2f getParentRelativePosition() const = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual void setPosition() = 0;

    virtual Type getType() const = 0;

    virtual sf::Vector2f getParentRelativeScale() const = 0;
    virtual sf::Vector2f getScale() const = 0;
    virtual void setScale() = 0;

    virtual bool isExecGlobal() const = 0;
    virtual bool isOnGlobalPlan() const = 0;

    virtual std::string getGlobalId() const = 0;

    virtual void exec() = 0;

    virtual std::string getName() const = 0;

protected:
    std::string _name;

    IObject *_parent;
    sf::Vector2f _parentRelativePosition;
    virtual void setParentRelativePosition(sf::Vector2f &) = 0;

    Type _type;
    virtual void setType(Type &NewType) = 0;

    sf::Vector2f _parentRelativeScale;
    virtual void setParentRelativeScale(sf::Vector2f &NewScale) = 0;

    bool _execIsGlobal;
    virtual void setExecGlobal(bool &value) = 0;
    bool _isOnGlobalPlan;
    virtual void setPlanGlobal(bool &value) = 0;

    std::string _globalId;
    virtual void setGlobalId(std::string &id) = 0;
};
