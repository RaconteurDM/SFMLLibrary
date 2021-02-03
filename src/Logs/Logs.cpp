/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Logs
*/

#include "../include/Logs.hpp"
#include "../include/CGEExeptions.hpp"
#include <iostream>
#include <string>
#include <ctime>

void cge::LogUnit::addLine(std::string message)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    std::string strTime = '[' + std::to_string(now->tm_hour) + ':' + std::to_string(now->tm_min) + ':' + std::to_string(now->tm_sec) + ']';

    std::cout << strTime << ": " << message << std::endl;
}

cge::Logs::Logs(std::string name)
{
    if (_logsMap.find(name) == _logsMap.end())
        _logsMap[name] = new LogUnit(name, true);
}

void cge::Logs::DestroyLogs()
{
    for (auto it = _logsMap.begin(); it != _logsMap.end(); it++)
    {
        delete it->second;
    }
}

static std::map<std::string, cge::LogUnit *> initLogMap()
{
    std::map<std::string, cge::LogUnit *> init;
    return (init);
}

std::map<std::string, cge::LogUnit *> cge::Logs::_logsMap = initLogMap();

cge::LogUnit *cge::Logs::operator[](std::string name)
{
    if (_logsMap.find(name) == _logsMap.end())
        throw cgeExeptions("Logs::operator[]", "Can't find " + name + " logs");
    return (_logsMap[name]);
}