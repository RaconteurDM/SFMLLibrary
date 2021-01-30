/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** LinkObj
*/

#include "../include/LinkObj.hpp"
#include "../include/MySfmlExeptions.hpp"

IObject *LinkObj::getGlobalObj(const std::string &Id)
{
    if (!_objectMap[Id])
        throw MySfmlExeptions("execGlobObj", "Try to get an inexistant Global Object");
    return _objectMap[Id];
}

void LinkObj::execGlobObj(const std::string &Id)
{
    if (!_objectMap[Id])
        throw MySfmlExeptions("execGlobObj", "Try to exec from inexistant Global Object");
    _objectMap[Id]->exec();
}

void LinkObj::delGlobObj(const std::string &Id)
{
    if (!_objectMap[Id])
        throw MySfmlExeptions("delGlobObj", "Try to delete id from inexistant Global Object");
    _objectMap[Id] = NULL;
    _objectMap.erase(Id);
}

void LinkObj::addGlobObj(const std::string &Id, IObject *Obj)
{
    if (!Obj)
        throw MySfmlExeptions("delGlobObj", "Try to add inexistant Object to Global Object");
    _objectMap[Id] = Obj;
}

LinkObj::objectMapT LinkObj::_objectMap = LinkObj::createMap();
