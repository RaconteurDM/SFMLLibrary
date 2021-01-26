/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** MySfmlExeptions
*/

#pragma once

#include <iostream>

class MySfmlExeptions {
    public:
        MySfmlExeptions(const std::string &where, const std::string &what);
        MySfmlExeptions(const std::string &where, const MySfmlExeptions &other);
        ~MySfmlExeptions();

        std::string what() const{ return _what; };
        std::string where() const { return _where; };

    protected:
        const std::string _what;
        const std::string _where;
};
