/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** LinkObj
*/

#include "../include/LinkObj.hpp"
#include "../include/CGEExeptions.hpp"

cge::IObject *cge::LinkObj::getGlobalObj(const std::string &Id)
{
    if (!_objectMap[Id])
        throw cgeExeptions("execGlobObj", "Try to get an inexistant Global Object");
    return _objectMap[Id];
}

void cge::LinkObj::execGlobObj(const std::string &Id)
{
    if (!_objectMap[Id])
        throw cgeExeptions("execGlobObj", "Try to exec from inexistant Global Object");
    _objectMap[Id]->exec();
}

void cge::LinkObj::delGlobObj(const std::string &Id)
{
    if (!_objectMap[Id])
        throw cgeExeptions("delGlobObj", "Try to delete id from inexistant Global Object");
    _objectMap[Id] = NULL;
    _objectMap.erase(Id);
}

void cge::LinkObj::addGlobObj(const std::string &Id, IObject *Obj)
{
    if (!Obj)
        throw cgeExeptions("delGlobObj", "Try to add inexistant Object to Global Object");
    _objectMap[Id] = Obj;
}

cge::LinkObj::objectMapT cge::LinkObj::_objectMap = cge::LinkObj::createMap();
