/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** MySfmlExeptions
*/

#include "../include/MySfmlExeptions.hpp"

MySfmlExeptions::MySfmlExeptions(const std::string &where, const std::string &what)
    : _what(what), _where(where)
{
}

MySfmlExeptions::MySfmlExeptions(const std::string &where, const MySfmlExeptions &other)
    : _what(other.what()), _where(where + "/" + other.where())
{
}

MySfmlExeptions::~MySfmlExeptions()
{
}
