
#include <fstream>
#include <iostream>
#include <regex>

void display(int screen[6][50])
{
    for (int y = 0; y < 6; y++)
    {
        for (int x = 0; x < 50; x++)
        {
            std::cout << (screen[y][x] ? "#" : ".");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    int screen[6][50] = {0};

    std::ifstream inFile("question.in");

    std::string line;
    while (std::getline(inFile, line))
    {
        std::regex re("(rect (\\d+)x(\\d+))|(rotate row y=(\\d+) by (\\d+))|(rotate column x=(\\d+) by (\\d+))");
        std::smatch matches;
        std::regex_search(line, matches, re);

        if (matches[1] != "")
        {
            for (int y = 0; y < std::stoi(matches[3]); y++)
            {
                for (int x = 0; x < std::stoi(matches[2]); x++)
                {
                    screen[y][x] = 1;
                }
            }
        }
        if (matches[4] != "")
        {
            int y = std::stoi(matches[5]);
            int shiftBy = std::stoi(matches[6]);

            int temp[50];
            for (int x = 0; x < 50; x++)
            {
                temp[(x + shiftBy) % 50] = screen[y][x];
            }
            for (int x = 0; x < 50; x++)
            {
                screen[y][x] = temp[x];
            }
        }
        if (matches[7] != "")
        {
            int x = std::stoi(matches[8]);
            int shiftBy = std::stoi(matches[9]);

            int temp[6];
            for (int y = 0; y < 6; y++)
            {
                temp[(y + shiftBy) % 6] = screen[y][x];
            }
            for (int y = 0; y < 6; y++)
            {
                screen[y][x] = temp[y];
            }
        }
    }

    int lightsOnCount = 0;
    for (int y = 0; y < 6; y++)
    {
        for (int x = 0; x < 50; x++)
        {
            lightsOnCount += screen[y][x];
        }
    }
    display(screen);

    std::cout << lightsOnCount << std::endl;
}
