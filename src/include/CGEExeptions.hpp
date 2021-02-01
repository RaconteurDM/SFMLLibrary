/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** MySfmlExeptions
*/

#pragma once

#include <iostream>

namespace cge
{
    class cgeExeptions
    {
    public:
        cgeExeptions(const std::string &where, const std::string &what);
        cgeExeptions(const std::string &where, const cgeExeptions &other);
        ~cgeExeptions();

        std::string what() const { return _what; };
        std::string where() const { return _where; };

    protected:
        const std::string _what;
        const std::string _where;
    };
} // namespace cge
