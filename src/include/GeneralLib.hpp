/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** GeneralLib
*/

#pragma once

#include <vector>
#include <iostream>

std::vector<std::string> splitByRegexTokens(const std::string &toTokenize, const std::string &strRegex);

std::vector<std::string> splitByRegexSeparator(const std::string &toTokenize, const std::string &strRegex);

void removeByRegex(std::string &target, const std::string &strRegex);