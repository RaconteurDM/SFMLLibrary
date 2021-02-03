/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** GenResp
*/

#include "../../src/include/Window.hpp"
#include "../../src/include/Parser.hpp"
#include "../../src/include/Logs.hpp"
#include "../../src/include/CGEExeptions.hpp"

int main(void)
{
    try
    {
        std::cout << cge::Parser("tests/UnitTests/FilesTests/testMultiFileError1.txt", cge::Parser::MAP, NULL).getTextMap("    ");
    }
    catch (cge::cgeExeptions &e)
    {
        std::cout << e.where() << ": " << e.what() << std::endl;
    }
}
