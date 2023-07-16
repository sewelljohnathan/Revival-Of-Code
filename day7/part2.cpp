
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

int main(void)
{

    std::ifstream inFile("question.in");

    int counter = 0;

    std::string line;
    while (inFile >> line)
    {

        bool isOutsideBracket = true;
        bool doesSupport = false;

        std::vector<std::array<char, 3>> aba;
        std::vector<std::array<char, 3>> bab;

        for (int i = 0; i < line.size(); i++)
        {
            char c = line.at(i);

            if (c == '[')
            {
                isOutsideBracket = false;
                continue;
            }
            if (c == ']')
            {
                isOutsideBracket = true;
                continue;
            }

            if (i < line.size() - 2)
            {
                std::array<char, 3> arr;
                for (int j = 0; j < 3; j++)
                {
                    arr[j] = line.at(i + j);
                }

                if (arr[0] == arr[2] && arr[0] != arr[1])
                {
                    if (isOutsideBracket)
                    {
                        aba.push_back(arr);
                    }
                    else
                    {
                        bab.push_back(arr);
                    }
                }
            }
        }

        for (const auto &abaArr : aba)
        {
            for (const auto &babArr : bab)
            {
                if (abaArr[0] == babArr[1] && abaArr[1] == babArr[0])
                {
                    doesSupport = true;
                }
            }
        }

        if (doesSupport)
        {
            counter++;
        }
    }

    std::cout << counter << std::endl;
}
