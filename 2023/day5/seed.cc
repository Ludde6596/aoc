
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

int main()
{
    std::vector<long int> seeds;
    std::vector<std::vector<long int>> seed_to_soil;
    std::vector<std::vector<long int>> soil_to_fertilizer;
    std::vector<std::vector<long int>> fertilizer_to_water;
    std::vector<std::vector<long int>> water_to_light;
    std::vector<std::vector<long int>> light_to_temperature;
    std::vector<std::vector<long int>> temperature_to_humidity;
    std::vector<std::vector<long int>> humidity_to_location;
    std::fstream fs{"input.txt"};
    if (fs.fail())
    {
        std::cerr << "Fil kunde ej läsas";
        return -1;
    }
    std::string line{};
    int mapnum = 0;
    while (std::getline(fs, line))
    {
        std::vector<std::string> rowlist = splitString(line);
        if (mapnum == 0)
        {
            rowlist.erase(rowlist.begin());
            for (auto s : rowlist)
            {
                seeds.push_back(std::stol(s));
            }
            mapnum++;
        }
    }
    for (long int i : seeds)
    {
        std::cout << i << std::endl;
    }

    return 0;
}