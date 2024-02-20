
/*
Steg 1 läs in input från fil och spara i vektorer
Steg 2 skapa funktion som hittar tillhörande intervall till siffra
Steg 3 loopa igenom alla maps
Steg 4 loopa igenom alla seeds och spara min location
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

std::vector<std::string> splitString(const std::string &s, char delimiter = ' ')
{
    std::vector<std::string> words;
    std::istringstream iss(s);
    std::string word;
    while (std::getline(iss, word, delimiter))
    {
        if (!word.empty())
            words.push_back(word);
    }
    return words;
}

std::vector<std::string> createNumList(const std::string &s)
{
    std::vector<std::string> numbers;
    numbers = splitString(s, '\n');
    std::regex npattern("\\d");
    for (auto it = numbers.begin(); it != numbers.end(); it++)
    {
        if (!std::regex_search(*it, npattern))
        {
            numbers.erase(it);
            it--;
        }
    }
    return numbers;
}

int main()
{
    std::vector<long int> seeds;
    std::vector<std::vector<std::vector<long int>>> maps;
    std::fstream fs{"input.txt"};
    if (fs.fail())
    {
        std::cerr << "Fil kunde ej läsas";
        return -1;
    }
    std::string section{};
    std::vector<std::string> sections{};
    while (std::getline(fs, section, ':'))
    {
        sections.push_back(section);
    }

    std::vector<std::vector<std::string>> sections_list{};
    for (std::string s : sections)
    {
        if (createNumList(s).size() > 0)
        {
            sections_list.push_back(createNumList(s));
        }
    }

    std::vector<std::string> tempseeds = splitString(sections_list[0][0]);
    for (std::string s : tempseeds)
    {
        seeds.push_back(std::stol(s));
    }

    for (auto it = sections_list.begin() + 1; it != sections_list.end(); it++)
    {
        std::vector<std::vector<long int>> tempm{};
        for (auto s : *it)
        {
            std::vector<std::string> temps = splitString(s);
            std::vector<long int> tempn{};
            for (auto s : temps)
            {
                tempn.push_back(std::stol(s));
            }
            tempm.push_back(tempn);
        }
        maps.push_back(tempm);
    }

    for (auto v : maps[0])
    {
        std::cout << "SEPERATOR OF MAPPINGS" << std::endl;
        for (auto i : v)
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}