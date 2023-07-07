
#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> pad = {
    {0, 0,  0,  0,  0, 0, 0},
    {0, 0,  0,  1,  0, 0, 0},
    {0, 0,  2,  3,  4, 0, 0},
    {0, 5,  6,  7,  8, 9, 0},
    {0, 0, 10, 11, 12, 0, 0},
    {0, 0,  0, 13,  0, 0, 0},
    {0, 0,  0,  0,  0, 0, 0},
};

char toHex(int val) {

    if (val >= 0 && val <= 9) {
        return val + '0';
    }
    if (val >= 10 && val <= 14) {
        return (val - 10) + 'A';
    }
    return -1;
}


int main(void) {

    std::ifstream inFile("question.in");

    int x = 1, y = 3;

    std::string s;
    std::vector<char> code;
    while (inFile >> s) 
    {
        for (const char & c: s) 
        {
            switch (c) 
            {
                case 'U': y = pad[y-1][x] == 0? y: y-1; break;
                case 'D': y = pad[y+1][x] == 0? y: y+1; break;
                case 'L': x = pad[y][x-1] == 0? x: x-1; break;
                case 'R': x = pad[y][x+1] == 0? x: x+1; break;
            }
        }

        code.push_back(toHex(pad[y][x]));
    }

    for (const char & c: code) {
        std::cout << c;
    }
    std::cout << std::endl;


}
