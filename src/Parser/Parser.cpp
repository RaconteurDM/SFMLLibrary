/*
** EPITECH PROJECT, 2021
** SFMLLibrary
** File description:
** Parser
*/

#include "../include/Parser.hpp"
#include "../include/CGEExeptions.hpp"
#include <vector>
#include <regex>
#include <fstream>

static std::vector<std::string> splitByRegexTokens(const std::string &toTokenize, const std::string &strRegex)
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

static std::vector<std::string> splitByRegexSeparator(const std::string &toTokenize, const std::string &strRegex)
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

static void removeByRegex(std::string &target, const std::string &strRegex)
{
    std::regex shape(strRegex);
    target = std::regex_replace(target, shape, "");
}

cge::Parser::Parser(std::string string, Types type, Parser *parent) : _parent(parent), _type(type)
{

    if (_type == MAP)
    {
        setAppRelativePath(string);
        loadFile(_appRelativePath);
    }
    else if (_type == STRING)
    {
        _stringValue = string;
        _appRelativePath = _parent->_appRelativePath;
    }
}

cge::Parser::Parser(std::string name, std::map<std::string, std::string> blockMap, Parser *parent) : _parent(parent)
{
    blockParse(name, blockMap);
    _appRelativePath = _parent->_appRelativePath;
    _type = MAP;
}

cge::Parser::Parser(int integer, Parser *parent) : _parent(parent)
{
    _type = INTEGER;
    _intValue = integer;
    _appRelativePath = _parent->_appRelativePath;
}

cge::Parser::Parser(double floatNumber, Parser *parent) : _parent(parent)
{
    _type = DOUBLE;
    _doubleValue = floatNumber;
    _appRelativePath = _parent->_appRelativePath;
}

cge::Parser::~Parser()
{
    for (auto it = _mapValue.begin(); it != _mapValue.end(); it++)
    {
        delete it->second;
    }
}

std::map<std::string, std::string> cge::Parser::blockClass(std::vector<std::string> blockList)
{
    std::map<std::string, std::string> blockMap;
    std::vector<std::string> tmpBlock;

    for (auto it = blockList.begin(); it != blockList.end(); it++)
    {
        tmpBlock = splitByRegexSeparator(*it, "[[:space:]]*:[[:space:]]*");
        if (tmpBlock.size() != 2)
            throw cgeExeptions("cge::Parser::blockClass", std::string("Invalid block: ") + *it);
        if (blockMap.find(tmpBlock[0]) != blockMap.end())
            throw cgeExeptions("cge::Parser::blockClass", std::string("Block: ") + tmpBlock[0] + std::string(" already defined"));
        blockMap[tmpBlock[0]] = tmpBlock[1];
    }
    return (blockMap);
}

void cge::Parser::dataParse(std::string name, std::string data, std::map<std::string, std::string> blockMap)
{
    std::vector<std::string> tmpData;

    if (_mapValue.find(name) != _mapValue.end())
    {
        throw cgeExeptions("cge::Parser::blockClass", std::string("Data: ") + name + std::string(" already defined"));
    }
    if (std::regex_match(data, std::regex("\".*\"")))
    {
        tmpData = splitByRegexSeparator(data, "\"");
        if (tmpData.size() != 2)
        {
            throw cgeExeptions("cge::Parser::dataParse", std::string("Invalid data: ") + data);
        }
        _mapValue[name] = new Parser(tmpData[1], STRING, this);
    }
    else if (std::regex_match(data, std::regex("[0-9]+\\.[0-9]+")))
    {
        _mapValue[name] = new Parser(atof(data.c_str()), this);
    }
    else if (std::regex_match(data, std::regex("[0-9]+")))
    {
        _mapValue[name] = new Parser(atoi(data.c_str()), this);
    }
    else if (std::regex_match(data, std::regex("<.+>")))
    {
        removeByRegex(data, "<");
        removeByRegex(data, ">");
        _mapValue[name] = new Parser(data, blockMap, this);
    }
    else if (std::regex_match(data, std::regex("\\(.+\\)")))
    {
        removeByRegex(data, "\\(");
        removeByRegex(data, "\\)");
        _mapValue[name] = new Parser(data, MAP, this);
    }
    else {
        throw cgeExeptions("cge::Parser::dataParse", std::string("Invalid data: ") + data);
    }
}

void cge::Parser::blockParse(std::string name, std::map<std::string, std::string> blockMap)
{
    std::vector<std::string> mainLines;
    std::vector<std::string> tmpLine;

    if (blockMap.find(name) == blockMap.end())
    {
        throw cgeExeptions("Parser:blockParse", std::string("Can't find ") + name + std::string("block"));
    }
    mainLines = splitByRegexTokens(blockMap[name], "[^[:space:]].*=.*");
    for (auto it = mainLines.begin(); it != mainLines.end(); it++)
    {
        tmpLine = splitByRegexSeparator(*it, "[[:space:]]*=[[:space:]]*");
        if (tmpLine.size() != 2)
        {
            throw cgeExeptions("cge::Parser::blockParse", std::string("Invalid line: ") + *it);
        }
        dataParse(tmpLine[0], tmpLine[1], blockMap);
    }
}

void cge::Parser::loadFile(std::string &file)
{
    std::ifstream ifs(file);
    std::string content;

    if (ifs.is_open())
        content = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    else
        throw cgeExeptions("cge::Parser::loadFile", std::string("Invalid file:") + _appRelativePath);

    blockParse("main", blockClass(splitByRegexTokens(content, "([^[:space:]]*.*:.*[\\{]([[:space:]]*[^[:space:]].*=.*\n)*[\\}])")));
    removeByRegex(content, "([^[:space:]]*.*:.*[\\{]([[:space:]]*[^[:space:]].*=.*\n)*[\\}])");
    if (!std::regex_match(content, std::regex("[[:space:]]*")))
    {
        throw cgeExeptions("cge::Parser::loadFile", std::string("Invalid blocks:") + content);
    }
}

std::string cge::Parser::getTextMap(std::string basicIndent, std::string actualIndent) const
{
    std::string ret = "";
    auto nextIndent = actualIndent;
    nextIndent += basicIndent;
    if (_type == MAP)
    {
        ret += std::string("{\n");
        for (auto it = _mapValue.begin(); it != _mapValue.end(); it++)
        {
            ret += nextIndent + it->first + std::string(" : ") + it->second->getTextMap(basicIndent, nextIndent);
        }
        ret += actualIndent + std::string("}\n");
    }
    else if (_type == STRING)
    {
        ret = std::string("\"") + _stringValue + std::string("\"\n");
    }
    else if (_type == INTEGER)
    {
        ret = std::to_string(_intValue) + std::string("\n");
    }
    else if (_type == DOUBLE)
    {
        ret = std::to_string(_doubleValue) + std::string("\n");
    }
    return ret;
}

void cge::Parser::setAppRelativePath(std::string path)
{
    std::string ret = "";
    std::vector<std::string> tmpPath;

    if (_parent != NULL)
    {
        tmpPath = splitByRegexSeparator(_parent->getAppRelativePath(), "(\\/|\\\\)");

        for (auto it = tmpPath.begin(); it != (tmpPath.end() - 1); it++)
        {
            ret += *it;
            ret += "/";
        }
        ret += path;
        _appRelativePath = ret;
    }
    else
    {
        ret += path;
        _appRelativePath = ret;
    }
}

cge::Parser &cge::Parser::operator[](const std::string &name)
{
    if (_type != MAP)
        throw cge::cgeExeptions("Parser::operator[]", "Trying to take var from non-block var");
    else if (_mapValue.find(name) == _mapValue.end())
        throw cge::cgeExeptions("Parser::operator[]", "Trying to take inexistant var from block");
    return (*_mapValue[name]);
}