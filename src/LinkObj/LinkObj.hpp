/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** LinkObj
*/

#pragma once

#include <map>
#include <iostream>

#include "../Object/IObject.hpp"

class LinkObj
{
public:
    LinkObj() {};
    ~LinkObj() {};

    IObject *getGlobalObj(const std::string &Id);

    void execGlobObj(const std::string &Id);

    void addGlobObj(const std::string &Id, IObject *Obj);
    void delGlobObj(const std::string &Id);

private:
    static std::map<std::string, IObject *> _objectMap;
};
