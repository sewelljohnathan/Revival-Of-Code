
#include <fstream>
#include <iostream>
#include <vector>

int main(void) 
{
    std::ifstream inFile("question.in");

    int count = 0;

    std::vector<int> colA, colB, colC;
    std::string s;
    while (inFile >> s) 
    {

        colA.push_back(std::stoi(s));
        inFile >> s;
        colB.push_back(std::stoi(s));
        inFile >> s;
        colC.push_back(std::stoi(s));

    }

    for (int i = 0; i < colA.size(); i += 3) 
    {
        int a = colA.at(i), b = colA.at(i+1), c = colA.at(i + 2);
        count += (a + b > c && a + c > b && b + c > a);
    }
    for (int i = 0; i < colB.size(); i += 3) 
    {
        
        int a = colB.at(i), b = colB.at(i+1), c = colB.at(i + 2);
        count += (a + b > c && a + c > b && b + c > a);
    }
    for (int i = 0; i < colC.size(); i += 3) 
    {
        
        int a = colC.at(i), b = colC.at(i+1), c = colC.at(i + 2);
        count += (a + b > c && a + c > b && b + c > a);
    }

    std::cout << count << std::endl;

}