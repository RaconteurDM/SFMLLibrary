/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** UnitTest
*/

#include <criterion/criterion.h>

#include "../../src/include/Window.hpp"
#include "../../src/include/Parser.hpp"
#include "../../src/include/Logs.hpp"
#include "../../src/include/GeneralLib.hpp"

#include <vector>
#include <regex>
#include <fstream>

std::string openFile(std::string &file)
{
    std::ifstream ifs(file);
    std::string content = "";

    if (ifs.is_open())
        content = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    else
        std::cout << "Non existant file: " << file << std::endl;
    return content;
}

Test(Parser, SimpleFileWithBlocks)
{
    std::string file("tests/UnitTests/GoodResCompare/testOneFile1res.txt");
    auto cmp = openFile(file);
    auto toTest = cge::Parser("tests/UnitTests/FilesTests/testOneFile1.txt", cge::Parser::MAP, NULL).getTextMap("    ");
    auto message = "Expected: " + cmp + "\nbut got: " + toTest;

    cr_assert(cmp.compare("") != 0, "Invalid or empty file for test");
    cr_expect(cmp.compare(toTest) == 0, "Invalid resp");
    if (cmp.compare(toTest) != 0)
        std::cout << message << std::endl;
}