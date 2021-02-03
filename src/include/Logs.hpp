/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Logs
*/

#include <map>

#pragma once
namespace cge
{
    class LogUnit
    {
    public:
        inline LogUnit(std::string name, bool directDisplay = false) : _directDisplay(directDisplay) {};
        inline ~LogUnit() {};

        void addLine(std::string message);

        bool _directDisplay;
    };

    class Logs
    {
    public:
        Logs(std::string name);
        inline Logs() {};
        void DestroyLogs();
        inline ~Logs() {};

        cge::LogUnit *operator[](std::string name);

        static std::map<std::string, LogUnit *> _logsMap;
    };
} // namespace cge
