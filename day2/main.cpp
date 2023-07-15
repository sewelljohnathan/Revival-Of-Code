
#include <fstream>
#include <iostream>
#include <vector>

#include "main.hpp"

int main(void)
{

    std::ifstream inFile("question.in");

    int x = 1, y = 3;

    std::string s;
    std::vector<char> code;
    while (inFile >> s)
    {
        for (const char &c : s)
        {
            switch (c)
            {
            case 'U':
                y = pad[y - 1][x] == 0 ? y : y - 1;
                break;
            case 'D':
                y = pad[y + 1][x] == 0 ? y : y + 1;
                break;
            case 'L':
                x = pad[y][x - 1] == 0 ? x : x - 1;
                break;
            case 'R':
                x = pad[y][x + 1] == 0 ? x : x + 1;
                break;
            }
        }

        code.push_back(toHex(pad[y][x]));
    }

    for (const char &c : code)
    {
        std::cout << c;
    }
    std::cout << std::endl;
}
