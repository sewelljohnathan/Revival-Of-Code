
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

enum Direction 
{ 
    FIRST_DIRECTION = 0,
    NORTH = FIRST_DIRECTION, 
    EAST, 
    SOUTH, 
    WEST, 
    LAST_DIRECTION
};
Direction operator++(Direction& dir) 
{
    dir = static_cast<Direction>((static_cast<int>(dir) + 1) % static_cast<int>(LAST_DIRECTION));
    return dir;
}
Direction operator--(Direction& dir) 
{
    dir = static_cast<Direction>((static_cast<int>(dir) - 1 + static_cast<int>(LAST_DIRECTION)) % static_cast<int>(LAST_DIRECTION));
    return dir;
}

int main(void) 
{
    std::ifstream inFile("question.in");

    Direction curDir = NORTH;
    int horzSteps = 0;
    int vertSteps = 0;

    std::set<std::pair<int, int>> visited;
    visited.insert(std::pair<int, int>(0, 0));
    
    std::string s;
    while (inFile >> s) 
    {
    
        char turn = s.at(0);
        s = s.substr(1);
        s.erase(std::remove(s.begin(), s.end(), ','), s.end());
        int dist = std::stoi(s);

        if (turn == 'R') { ++curDir; }
        if (turn == 'L') { --curDir; }

        bool found = false;
        for (int i = 0; i < dist; i++) 
        {

            switch (curDir) 
            {
                case NORTH: vertSteps++; break;
                case EAST: horzSteps++; break;
                case SOUTH: vertSteps--; break;
                case WEST: horzSteps--; break;
            }

            std::pair<int, int> loc(horzSteps, vertSteps);
            if (visited.count(loc)) 
            {
                found = true;
                break;
            }
            visited.insert(loc);
        }
        if (found) break;
    }

    int totalDist = abs(horzSteps) + abs(vertSteps);
    std::cout << totalDist << std::endl;

    return 0;
}
