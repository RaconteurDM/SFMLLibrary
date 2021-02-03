/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** GenResp
*/

#include "../../src/include/Window.hpp"
#include "../../src/include/Parser.hpp"
#include "../../src/include/Logs.hpp"

int main(void)
{
    std::cout << cge::Parser("tests/UnitTests/FilesTests/testMultiFile1-1.txt", cge::Parser::MAP, NULL).getTextMap("    ");
}
