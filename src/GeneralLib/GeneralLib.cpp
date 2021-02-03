/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** GeneralLib
*/

#include "../include/GeneralLib.hpp"

#include <regex>

std::vector<std::string> splitByRegexTokens(const std::string &toTokenize, const std::string &strRegex)
{
    std::vector<std::string> res;
    std::regex shape(strRegex);
    std::sregex_token_iterator defaultToken;
    std::sregex_token_iterator Tokens(toTokenize.begin(), toTokenize.end(), shape, 0);

    while (Tokens != defaultToken)
    {
        res.push_back(*Tokens);
        Tokens++;
    }
    return (res);
}

std::vector<std::string> splitByRegexSeparator(const std::string &toTokenize, const std::string &strRegex)
{
    std::vector<std::string> res;
    std::regex shape(strRegex);
    std::sregex_token_iterator defaultToken;
    std::sregex_token_iterator Tokens(toTokenize.begin(), toTokenize.end(), shape, -1);

    while (Tokens != defaultToken)
    {
        res.push_back(*Tokens);
        Tokens++;
    }
    return (res);
}

void removeByRegex(std::string &target, const std::string &strRegex)
{
    std::regex shape(strRegex);
    target = std::regex_replace(target, shape, "");
}
