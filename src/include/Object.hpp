/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Object
*/

#pragma once

#include "IObject.hpp"
#include "LinkObj.hpp"

namespace cge
{
    class Object : public IObject
    {
    public:
        inline Object(std::string name, IObject *parent = NULL)
        {
            _name = name;
            _parent = parent;
        };
        inline ~Object(){};

        inline IObject *getParent() override { return _parent; };
        inline sf::Vector2f getParentRelativePosition() const override { return _parentRelativePosition; };

        inline Type getType() const override { return _type; };

        inline virtual sf::Vector2f getParentRelativeScale() const override { return _parentRelativeScale; };

        inline bool isExecGlobal() const override { return _execIsGlobal; };
        inline bool isOnGlobalPlan() const override { return _isOnGlobalPlan; };

        inline std::string getGlobalId() const override { return _globalId; };

        virtual std::string getName() const { return _name; };

    protected:
        inline void setParentRelativePosition(sf::Vector2f &NewPos) override { _parentRelativePosition = NewPos; };

        inline void setType(Type &NewType) override { _type = NewType; };

        inline virtual void setParentRelativeScale(sf::Vector2f &NewScale) override { _parentRelativeScale = NewScale; };

        inline void setExecGlobal(bool &value) override { _execIsGlobal = value; };
        inline void setPlanGlobal(bool &value) override { _isOnGlobalPlan = value; };

        void setGlobalId(std::string &id) override
        {
            LinkObj().addGlobObj(id, this);
            _globalId = id;
        };
    };
} // namespace cge
