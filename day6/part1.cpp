
#include <fstream>
#include <iostream>

int main(void)
{

    std::ifstream inFile("question.in");

    int frequency[8][26] = {0};
    int mostPopular[8] = {0};

    std::string s;
    while (inFile >> s)
    {
        for (int i = 0; i < 8; i++)
        {
            int charIndex = s[i] - 'a';
            frequency[i][charIndex]++;
            
            char mostPopularInPosition = mostPopular[i];
            if (frequency[i][charIndex] > frequency[i][mostPopularInPosition])
            {
                mostPopular[i] = charIndex;
            }
        }
    }

    for (const int & c: mostPopular)
    {
        std::cout << (char) (c + 'a');
    }
    std::cout << std::endl;
    
    return 0;
}