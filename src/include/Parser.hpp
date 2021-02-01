/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <map>
#include <vector>

namespace cge
{
    class Parser
    {
    public:
        typedef enum Types_e
        {
            DEFAULT,
            FILE,
            INTEGER,
            DOUBLE,
            STRING,
            MAP
        } Types;

        Parser(std::string string, Types type, Parser *parent);
        Parser(std::string string, std::map<std::string, std::string> blockMap, Parser *parent);
        Parser(int interger, Parser *parent);
        Parser(double floatNumber, Parser *parent);
        ~Parser();

        void loadFile(std::string &file);
        std::map<std::string, std::string> blockClass(std::vector<std::string> blockList);
        void blockParse(std::string name, std::map<std::string, std::string> blockMap);
        void dataParse(std::string name, std::string data, std::map<std::string, std::string> blockMap);

        std::string getTextMap(std::string basicIndent, std::string actualIndent = "");

    private:
        Parser *_parent;
        Types _type;

        int _intValue;
        double _doubleValue;
        std::string _stringValue;
        std::map<std::string, Parser *> _mapValue;
    };
} // namespace cge
