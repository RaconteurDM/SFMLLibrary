/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** LinkObj
*/

#pragma once

#include <map>
#include <iostream>

#include "IObject.hpp"

class LinkObj
{
public:
    LinkObj() {};
    ~LinkObj() {};

    typedef std::map<std::string, IObject *> objectMapT;

    IObject *getGlobalObj(const std::string &Id);

    void execGlobObj(const std::string &Id);

    void addGlobObj(const std::string &Id, IObject *Obj);
    void delGlobObj(const std::string &Id);

private:
    static inline objectMapT createMap() { objectMapT map; return map; };
    static objectMapT _objectMap;
};