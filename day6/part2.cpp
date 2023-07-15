
#include <fstream>
#include <iostream>

int main(void)
{
    std::ifstream inFile("question.in");

    int frequency[8][26] = {0};

    std::string s;
    while (inFile >> s)
    {
        for (int i = 0; i < 8; i++)
        {
            int charIndex = s[i] - 'a';
            frequency[i][charIndex]++;
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        int leastPopularIndex = 0;
        for (int j = 0; j < 26; j++)
        {
            if (frequency[i][j] < frequency[i][leastPopularIndex])
            {
                leastPopularIndex = j;
            }
        }
        std::cout << (char)(leastPopularIndex + 'a');
    }

    std::cout << std::endl;

    return 0;
}