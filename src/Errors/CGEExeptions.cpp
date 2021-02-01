/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** MySfmlExeptions
*/

#include "../include/CGEExeptions.hpp"

cge::cgeExeptions::cgeExeptions(const std::string &where, const std::string &what)
    : _what(what), _where(where)
{
}

cge::cgeExeptions::cgeExeptions(const std::string &where, const cgeExeptions &other)
    : _what(other.what()), _where(where + "/" + other.where())
{
}

cge::cgeExeptions::~cgeExeptions()
{
}
