
#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <unordered_map>
#include <vector>

bool sortPairs(const std::pair<char, int> & a, const std::pair<char, int> & b)
{
    if (a.second != b.second) 
    {
        return a.second > b.second;
    }
    else 
    {
        return a.first < b.first;
    }
}
int main(void)
{

    std::ifstream inFile("question.in");

    int sum = 0;

    std::string line;
    while (inFile >> line)
    {   

        std::regex re("((?:[a-z]+-)+)([0-9]+)\\[([a-z]{5})\\]");
        std::smatch matches;
        std::regex_search(line, matches, re);

        std::string name = matches[1];
        int id = std::stoi(matches[2]);
        std::string checksum = matches[3];

        std::unordered_map<char, int> map;
        std::vector<std::pair<char, int>> vec;
        for (const char & c: name)
        {
            if (c == '-')
            {
                continue;
            }
            if (map.count(c)) 
            {
                map.at(c) += 1;
            }
            else 
            {
                map.insert(std::pair<char, int>(c, 1));
            }
        }
        for (const auto & i: map) 
        {
            vec.push_back(i);
        }
        std::sort(vec.begin(), vec.end(), sortPairs);
        

        std::string realChecksum = "";
        for (int i = 0; i < 5; i++)
        {
            realChecksum += vec.at(i).first;
        }

        if (checksum == realChecksum)
        {   
            std::string realname = "";
            for (const char & c: name) {
                if (c == '-')
                {
                    realname += ' ';
                }
                else
                {
                    realname += (char) ((c - 97 + id) % 26 + 97);
                }
            }
            std::cout << name << " | " << realname << std::endl;
            sum += id;
        }

    }

    std::cout << sum << std::endl;
}
