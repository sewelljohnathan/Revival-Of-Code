
#include <fstream>
#include <iostream>

int main(void)
{

    std::ifstream inFile("question.in");

    int counter = 0;

    std::string line;
    while (inFile >> line)
    {   

        bool isOutsideBracket = true;
        bool doesSupport = false;

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

            if (i < line.size() - 3)
            {
                char arr[4];
                for (int j = 0; j < 4; j++)
                {
                    arr[j] = line.at(i + j);
                }

                if (arr[0] != arr[1] && arr[0] == arr[3] && arr[1] == arr[2])
                {
                    if (isOutsideBracket)
                    {
                        doesSupport = true;
                    }
                    else
                    {
                        doesSupport = false;
                        break;
                    }
                }
            }
        }
        
        if (doesSupport)
        {
            std::cout << line << std::endl;
            counter++;
        }
        
    }

    std::cout << counter << std::endl;
}
